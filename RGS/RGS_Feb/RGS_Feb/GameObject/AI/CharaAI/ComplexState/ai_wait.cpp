//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.21
// ���e�@�F�w��b����҂�AiState
//-------------------------------------------------------------
#include <GameObject\AI\CharaAI\ComplexState\ai_wait.h>
#include <GameObject\AI\CharaAI\ComplexState\ai_hit_weak.h>

using namespace AI;

Wait::Wait(std::shared_ptr<Character::CharacterBase> my_character, float second)
	:m_character(my_character)
{
	m_wait_timer = Utility::Timer(second);
	m_wait_timer.Reset();
}

Wait::Wait(const Wait&)
{
}

Wait::~Wait()
{
}

void Wait::GetBattleInfo(MetaAI* meta_ai)
{
	return;
}

void Wait::Update(std::shared_ptr<Character::AiController> controller)
{
	m_wait_timer.Update();

	if (m_wait_timer.IsTime())
		m_end_flag = true;
}

std::shared_ptr<AiState> Wait::NextState(int difficulty)
{
	return std::make_shared<HitWeak>(m_character);
}
