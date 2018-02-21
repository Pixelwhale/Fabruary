//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.21
// ���e�@�F�����^�[�Q�b�g�Ɛ키AiState
//-------------------------------------------------------------
#include <GameObject\AI\CharaAI\ComplexState\ai_hit_strong.h>
#include <GameObject\AI\CharaAI\Move\ai_trace.h>
#include <GameObject\AI\CharaAI\Combo\ai_combo_punch_great.h>
#include <GameObject\AI\CharaAI\Combo\ai_combo_kick_great.h>
#include <GameObject\AI\MetaAI\meta_ai.h>
#include <GameObject\AI\CharaAI\ComplexState\ai_hit_weak.h>
#include <GameObject\AI\CharaAI\ComplexState\ai_hit_near.h>
#include <GameObject\AI\CharaAI\ComplexState\ai_wait.h>

using namespace AI;

HitStrong::HitStrong(std::shared_ptr<Character::CharacterBase> my_character, int difficulty)
	:m_character(my_character), m_can_attack(false), m_difficulty(difficulty)
{
	m_end_flag = false;
}

HitStrong::HitStrong(const HitStrong&)
{
}

HitStrong::~HitStrong()
{
}

void HitStrong::GetBattleInfo(MetaAI* meta_ai)
{
	m_target = meta_ai->FindWeak(m_character);

	if (m_attack == NULL)		//Punch���ݒ肳��Ă��Ȃ����A�ݒ肷��
	{
		if (Device::GameDevice::GetInstance()->GetRandom()->Next(0, 2) == 0)
			m_attack = std::make_shared<KickComboStrong>();
		else
			m_attack = std::make_shared<PunchComboStrong>();
	}

	m_trace = std::make_shared<Trace>(m_character, m_target, m_difficulty);
}

void HitStrong::Update(std::shared_ptr<Character::AiController> controller)
{
	m_trace->Update(controller);
	if (m_trace->IsEnd())
		m_can_attack = true;

	if (!m_can_attack)
		return;

	m_attack->Update(controller);

	if (m_attack->IsEnd())
		m_end_flag = true;
}

std::shared_ptr<AiState> HitStrong::NextState(int difficulty)
{
	int priority = Device::GameDevice::GetInstance()->GetRandom()->Next(1, 6);
	priority *= difficulty;
	if (priority > 8 * 3)											//��Փx8 2/5�̊m��
		return make_shared<HitWeak>(m_character, difficulty);

	if(priority > 3 * 3)											//��Փx3 2/5�̊m��
		return make_shared<HitNear>(m_character, difficulty);

	return make_shared<Wait>(m_character, 2.0f / difficulty);
}