//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.21
// 内容　：近いターゲットに技を出すAiState
//-------------------------------------------------------------
#include <GameObject\AI\CharaAI\ComplexState\ai_combo_near.h>
#include <GameObject\AI\CharaAI\ComplexState\ai_hit_weak.h>
#include <GameObject\AI\CharaAI\Move\ai_trace.h>
#include <GameObject\AI\CharaAI\ComplexState\ai_wait.h>
#include <GameObject\AI\MetaAI\meta_ai.h>

using namespace AI;

ComboNear::ComboNear(std::shared_ptr<Character::CharacterBase> my_character,
	std::shared_ptr<AiState> attack, int difficulty)
	:m_character(my_character), m_attack(attack), m_difficulty(difficulty)
{
	m_end_flag = false;
}

ComboNear::ComboNear(const ComboNear&)
{
}

ComboNear::~ComboNear()
{
}

void ComboNear::GetBattleInfo(MetaAI* meta_ai)
{
	m_target = meta_ai->FindNear(m_character);

	m_trace = std::make_shared<Trace>(m_character, m_target, m_difficulty);
}

void ComboNear::Update(std::shared_ptr<Character::AiController> controller)
{
	m_trace->Update(controller);
	m_attack->Update(controller);

	if (m_attack->IsEnd())
		m_end_flag = true;
}

std::shared_ptr<AiState> ComboNear::NextState(int difficulty)
{
	int rate = Device::GameDevice::GetInstance()->GetRandom()->Next(1, 9);

	if (rate - difficulty > 0)
		return make_shared<Wait>(m_character, 2.0f / difficulty);

	return make_shared<HitWeak>(m_character, difficulty);
}
