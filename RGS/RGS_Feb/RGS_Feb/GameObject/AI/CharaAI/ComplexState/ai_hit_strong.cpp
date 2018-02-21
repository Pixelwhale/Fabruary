//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.21
// 内容　：強いターゲットと戦うAiState
//-------------------------------------------------------------
#include <GameObject\AI\CharaAI\ComplexState\ai_hit_strong.h>
#include <GameObject\AI\CharaAI\Move\ai_trace.h>
#include <GameObject\AI\CharaAI\Combo\ai_combo_punch_great.h>
#include <GameObject\AI\CharaAI\Combo\ai_combo_kick_great.h>
#include <GameObject\AI\MetaAI\meta_ai.h>
#include <GameObject\AI\CharaAI\ComplexState\ai_hit_weak.h>
#include <GameObject\AI\CharaAI\ComplexState\ai_hit_near.h>

using namespace AI;

HitStrong::HitStrong(std::shared_ptr<Character::CharacterBase> my_character)
	:m_character(my_character), m_can_attack(false)
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

	if (m_attack == NULL)		//Punchが設定されていない時、設定する
	{
		if (Device::GameDevice::GetInstance()->GetRandom()->Next(0, 2) == 0)
			m_attack = std::make_shared<KickComboStrong>();
		else
			m_attack = std::make_shared<PunchComboStrong>();
	}

	m_trace = std::make_shared<Trace>(m_character, m_target);
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
	if (difficulty > 5)
		return make_shared<HitWeak>(m_character);

	return make_shared<HitNear>(m_character);
}