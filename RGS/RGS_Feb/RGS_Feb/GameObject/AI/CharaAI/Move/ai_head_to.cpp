//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.19
// ���e�@�F�w��̏ꏊ������AiState
//-------------------------------------------------------------
#include <GameObject\AI\CharaAI\Move\ai_head_to.h>

using namespace AI;

HeadDestination::HeadDestination(
	std::shared_ptr<Character::CharacterBase> my_chara,
	Math::Vector3 destination)
	:m_character(my_chara), m_destination(destination)
{
}

HeadDestination::HeadDestination(const HeadDestination&){}
HeadDestination::~HeadDestination()
{
	m_character = NULL;
}

void HeadDestination::GetBattleInfo(std::shared_ptr<MetaAI> meta_ai)
{
	return;
}

void HeadDestination::Update(std::shared_ptr<Character::AiController> controller)
{
}

std::shared_ptr<AiState> HeadDestination::NextState(int difficulty)
{
	return std::make_shared<HeadDestination>(m_character, m_destination);
}