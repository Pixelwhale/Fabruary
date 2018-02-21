//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.21
// 内容　：そのまま立つAiState
//-------------------------------------------------------------
#include <GameObject\AI\CharaAI\Move\ai_stay.h>

using namespace AI;

Stay::Stay()
{
}

Stay::Stay(const Stay&) {}

Stay::~Stay()
{
}

void Stay::GetBattleInfo(std::shared_ptr<MetaAI> meta_ai)
{
	return;
}

void Stay::Update(std::shared_ptr<Character::AiController> controller)
{
	return;
}


std::shared_ptr<AiState> Stay::NextState(int difficulty)
{
	return std::make_shared<Stay>();
}