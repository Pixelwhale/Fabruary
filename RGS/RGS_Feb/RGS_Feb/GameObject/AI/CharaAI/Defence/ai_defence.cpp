//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.21
// ���e�@�F�h��AiState
//-------------------------------------------------------------
#include <GameObject\AI\CharaAI\Defence\ai_defence.h>

using namespace AI;

Defence::Defence(std::shared_ptr<AiState> last_state, int difficulty)
	:m_last_state(last_state)
{
	m_end_flag = false;
	m_timer = Utility::Timer(0.5f / difficulty);
}

Defence::Defence(const Defence&) {}

Defence::~Defence()
{
}

void Defence::GetBattleInfo(MetaAI* meta_ai)
{
	return;
}

void Defence::Update(std::shared_ptr<Character::AiController> controller)
{
	m_timer.Update();
	if (!m_timer.IsTime())
		return;

	controller->Defence();
}

std::shared_ptr<AiState> Defence::NextState(int difficulty)
{
	return m_last_state;
}