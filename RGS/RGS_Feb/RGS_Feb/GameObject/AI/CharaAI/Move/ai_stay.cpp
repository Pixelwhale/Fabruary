//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.21
// ���e�@�F���̂܂ܗ���AiState
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