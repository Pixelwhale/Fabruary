#include <GameObject\AI\CharaAI\Combo\ai_combo_kick_less.h>

using namespace AI;

KickComboWeak::KickComboWeak()
{
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

void KickComboWeak::GetBattleInfo(std::shared_ptr<MetaAI> meta_ai)
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
		
		ResetTimer();
	}
}

std::shared_ptr<AiState> KickComboWeak::NextState()
{
	return make_shared<KickComboWeak>();						//仮
}