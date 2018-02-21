//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.21
// 内容　：防御AiState
//-------------------------------------------------------------
#include <GameObject\AI\CharaAI\Defence\ai_defence.h>

using namespace AI;

Defence::Defence()
{
	m_end_flag = false;
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
	controller->Defence();
}


std::shared_ptr<AiState> Defence::NextState(int difficulty)
{
	return std::make_shared<Defence>();
}