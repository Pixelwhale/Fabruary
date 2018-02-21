//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.21
// 内容　：近いターゲットと戦うAiState
//-------------------------------------------------------------
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
#include <GameObject\AI\CharaAI\ComplexState\ai_hit_weak.h>

using namespace AI;

HitNear::HitNear(std::shared_ptr<Character::CharacterBase> my_character, int difficulty)
	:m_character(my_character), m_difficulty(difficulty)
{
	m_end_flag = false;
}

HitNear::HitNear(const HitNear&)
{
}

HitNear::~HitNear()
{
}

void HitNear::GetBattleInfo(MetaAI* meta_ai)
{
	m_target = meta_ai->FindNear(m_character);

	if (m_attack == NULL)		//Punchが設定されていない時、設定する
	{
		int punch_count = Device::GameDevice::GetInstance()->GetRandom()->Next(1, 6);
		m_attack = std::make_shared<NormalPunch>(m_character, m_target, punch_count);
	}

	m_trace = std::make_shared<Trace>(m_character, m_target, m_difficulty);
}

void HitNear::Update(std::shared_ptr<Character::AiController> controller)
{
	m_trace->Update(controller);
	m_attack->Update(controller);

	//大技1500、小技300（記録用）
	if (m_attack->IsEnd())
		m_end_flag = true;
}

std::shared_ptr<AiState> HitNear::NextState(int difficulty)
{
	if (m_target->IsDead())
		return make_shared<HitNear>(m_character, difficulty);

	std::shared_ptr<AiState> attack = std::make_shared<NormalKick>(m_character, m_target);

	float rate = Device::GameDevice::GetInstance()->GetRandom()->NextDouble();

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

	if (m_character->GetMp() > 1500 && rate > 0.95f)
	{
		attack = std::make_shared<KickComboStrong>();
		return make_shared<ComboNear>(m_character, attack, difficulty);
	}

	if (m_character->GetMp() > 1500 && rate > 0.9f)
	{
		attack = std::make_shared<PunchComboStrong>();
		return make_shared<ComboNear>(m_character, attack, difficulty);
	}

	return make_shared<HitWeak>(m_character, difficulty);
}
