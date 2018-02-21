//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.19
// 内容　：KickCombo（小）のAiState
//-------------------------------------------------------------
#include <GameObject\AI\CharaAI\Combo\ai_combo_kick_less.h>

using namespace AI;

KickComboWeak::KickComboWeak()
{
	m_end_flag = false;
	m_random = Device::GameDevice::GetInstance()->GetRandom();
	m_timer = Utility::Timer(m_random->Next(3, 12) / 60.0f);
	m_current_combo = Combo::kPunch1;
}

KickComboWeak::KickComboWeak(const KickComboWeak&)
{
}

KickComboWeak::~KickComboWeak()
{
}

void KickComboWeak::GetBattleInfo(MetaAI* meta_ai)
{
	return;
}

void KickComboWeak::ResetTimer()
{
	m_timer = Utility::Timer(m_random->Next(3, 13) / 60.0f);	//Combo接続時間は最大10フレーム
}

void KickComboWeak::Update(std::shared_ptr<Character::AiController> controller)
{
	m_timer.Update();
	if (!m_timer.IsTime())										//行動フレーム以外はリターン
		return;

	if (m_current_combo == Combo::kPunch1 ||
		m_current_combo == Combo::kPunch2)
	{
		controller->TriggerPunch();
		m_current_combo = static_cast<Combo>((int)m_current_combo + 1);
		ResetTimer();
		return;
	}
	if (m_current_combo == Combo::kDefence) 
	{
		controller->Defence();
		m_current_combo = static_cast<Combo>((int)m_current_combo + 1);
		ResetTimer();
		return;
	}
	if (m_current_combo == Combo::kKick) 
	{
		controller->TriggerKick();
		m_current_combo = static_cast<Combo>((int)m_current_combo + 1);
		ResetTimer();
		return;
	}
	if (m_current_combo == Combo::kEnd) 
	{
		m_end_flag = true;
		return;
	}
}

std::shared_ptr<AiState> KickComboWeak::NextState(int difficulty)
{
	return make_shared<KickComboWeak>();						//仮
}