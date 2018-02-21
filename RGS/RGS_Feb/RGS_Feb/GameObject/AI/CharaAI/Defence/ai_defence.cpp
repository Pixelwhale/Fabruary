//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.21
// 内容　：防御AiState
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