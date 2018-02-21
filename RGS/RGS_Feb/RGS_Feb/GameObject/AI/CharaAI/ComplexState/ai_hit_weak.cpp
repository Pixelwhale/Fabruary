//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.21
// ���e�@�F�ア�^�[�Q�b�g�Ɛ키AiState
//-------------------------------------------------------------
#include <GameObject\AI\CharaAI\ComplexState\ai_hit_weak.h>
#include <GameObject\AI\CharaAI\ComplexState\ai_hit_near.h>
#include <GameObject\AI\CharaAI\Combo\ai_normal_punch.h>
#include <GameObject\AI\CharaAI\Combo\ai_normal_kick.h>
#include <GameObject\AI\CharaAI\Combo\ai_combo_kick_less.h>
#include <GameObject\AI\CharaAI\Combo\ai_combo_kick_great.h>
#include <GameObject\AI\CharaAI\Combo\ai_combo_punch_less.h>
#include <GameObject\AI\CharaAI\Combo\ai_combo_punch_great.h>
#include <GameObject\AI\CharaAI\Move\ai_trace.h>
#include <GameObject\AI\MetaAI\meta_ai.h>
#include <GameObject\AI\CharaAI\ComplexState\ai_combo_near.h>
#include <GameObject\AI\CharaAI\ComplexState\ai_hit_strong.h>
#include <GameObject\AI\CharaAI\ComplexState\ai_wait.h>

using namespace AI;

HitWeak::HitWeak(std::shared_ptr<Character::CharacterBase> my_character, int difficulty)
	:m_character(my_character), m_difficulty(difficulty)
{
	m_end_flag = false;
}

HitWeak::HitWeak(const HitWeak&)
{
}

HitWeak::~HitWeak()
{
}

void HitWeak::GetBattleInfo(MetaAI* meta_ai)
{
	m_target = meta_ai->FindWeak(m_character);

	if (m_attack == NULL)		//Punch���ݒ肳��Ă��Ȃ����A�ݒ肷��
	{
		int punch_count = Device::GameDevice::GetInstance()->GetRandom()->Next(1, 6);
		m_attack = std::make_shared<NormalPunch>(m_character, m_target, punch_count);
	}

	m_trace = std::make_shared<Trace>(m_character, m_target, m_difficulty);
}

void HitWeak::Update(std::shared_ptr<Character::AiController> controller)
{
	m_trace->Update(controller);
	m_attack->Update(controller);

	//��Z1500�A���Z300�i�L�^�p�j
	bool isEnd = m_attack->IsEnd();
	if (m_attack->IsEnd())
		m_end_flag = true;
}

std::shared_ptr<AiState> HitWeak::NextState(int difficulty)
{
	if (m_target == NULL || m_target->IsDead())
		return make_shared<HitWeak>(m_character, difficulty);

	std::shared_ptr<AiState> attack = std::make_shared<NormalKick>(m_character, m_target);

	if (difficulty < 3)
		return make_shared<ComboNear>(m_character, attack, difficulty);

	float rate = Device::GameDevice::GetInstance()->GetRandom()->NextDouble();

	if (rate < 0.1f)
		return make_shared<Wait>(m_character, 1.5f / difficulty);

	if (m_character->GetMp() > 300 && rate < 0.2f)
	{
		attack = std::make_shared<PunchComboWeak>();
		return make_shared<ComboNear>(m_character, attack, difficulty);
	}

	if (m_character->GetMp() > 300 && rate < 0.4f)
	{
		attack = std::make_shared<KickComboWeak>();
		return make_shared<ComboNear>(m_character, attack, difficulty);
	}

	if (difficulty > 6 && m_character->GetMp() > 1500
		&& m_character->GetHp() > 60)
	{
		return make_shared<HitStrong>(m_character, difficulty);
	}

	if (m_character->GetMp() > 1500 && rate > 0.9f)
	{
		attack = std::make_shared<KickComboStrong>();
		return make_shared<ComboNear>(m_character, attack, difficulty);
	}

	if (m_character->GetMp() > 1500 && rate > 0.8f)
	{
		attack = std::make_shared<PunchComboStrong>();
		return make_shared<ComboNear>(m_character, attack, difficulty);
	}

	return make_shared<HitWeak>(m_character, difficulty);
}
