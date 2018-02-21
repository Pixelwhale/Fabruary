//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.21
// 内容　：近いターゲットと戦うAiState
//-------------------------------------------------------------
#include <GameObject\AI\CharaAI\ComplexState\ai_hit_near.h>
#include <GameObject\AI\CharaAI\Combo\ai_normal_punch.h>
#include <GameObject\AI\CharaAI\Move\ai_trace.h>
#include <GameObject\AI\MetaAI\meta_ai.h>

using namespace AI;

HitNear::HitNear(std::shared_ptr<Character::CharacterBase> my_character)
	:m_character(my_character)
{
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
		int punch_count = Device::GameDevice::GetInstance()->GetRandom()->Next(0, 6);
		m_attack = std::make_shared<NormalPunch>(m_character, m_target, punch_count);
	}

	m_trace = std::make_shared<Trace>(m_character, m_target);
}

void HitNear::Update(std::shared_ptr<Character::AiController> controller)
{
	m_trace->Update(controller);
	m_attack->Update(controller);

	//大技3000、小技1500（記録用）
	if (m_attack->IsEnd())
		m_end_flag = true;
}

std::shared_ptr<AiState> HitNear::NextState(int difficulty)
{
	return make_shared<HitNear>(m_character);
}
