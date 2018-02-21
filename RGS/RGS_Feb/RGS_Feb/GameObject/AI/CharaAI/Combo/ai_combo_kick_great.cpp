//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.19
// ���e�@�FKickCombo�i��j��AiState
//-------------------------------------------------------------
#include <GameObject\AI\CharaAI\Combo\ai_combo_kick_great.h>

using namespace AI;

KickComboStrong::KickComboStrong()
{
	m_end_flag = false;
	m_random = Device::GameDevice::GetInstance()->GetRandom();
	m_timer = Utility::Timer(m_random->Next(3, 12) / 60.0f);
	m_current_combo = Combo::kDefence;
}

KickComboStrong::KickComboStrong(const KickComboStrong&)
{
}

KickComboStrong::~KickComboStrong()
{
}

void KickComboStrong::GetBattleInfo(MetaAI* meta_ai)
{
	return;
}

void KickComboStrong::ResetTimer()
{
	m_timer = Utility::Timer(m_random->Next(3, 13) / 60.0f);	//Combo�ڑ����Ԃ͍ő�10�t���[��
}

void KickComboStrong::Update(std::shared_ptr<Character::AiController> controller)
{
	m_timer.Update();
	if (!m_timer.IsTime())										//�s���t���[���ȊO�̓��^�[��
		return;

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
	if (m_current_combo == Combo::kRun)
	{
		controller->Run();
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

std::shared_ptr<AiState> KickComboStrong::NextState(int difficulty)
{
	return make_shared<KickComboStrong>();						//��
}