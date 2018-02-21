//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.19
// ���e�@�F�w��̏ꏊ������AiState
//-------------------------------------------------------------
#include <GameObject\AI\CharaAI\Move\ai_head_to.h>
#include <Character\character_base.h>

using namespace AI;

HeadDestination::HeadDestination(
	std::shared_ptr<Character::CharacterBase> my_chara,
	Math::Vector3 destination)
	:m_character(my_chara), m_destination(destination)
{
}

HeadDestination::HeadDestination(const HeadDestination&) {}
HeadDestination::~HeadDestination()
{
	m_character = NULL;
}

void HeadDestination::GetBattleInfo(MetaAI* meta_ai)
{
	return;
}

void HeadDestination::Update(std::shared_ptr<Character::AiController> controller)
{
	if (InRange(40))					//�߂�����ƏI��
	{
		m_end_flag = true;
		return;
	}

	Math::Vector3 velocity = m_destination - m_character->GetPosition();
	velocity = velocity.normalize();
	controller->SetVelocity(velocity);

	if (!InRange(256))					//�����������Ƒ���
		controller->Run();
}

bool HeadDestination::InRange(float distance)
{
	return (m_character->GetPosition() - m_destination).lengthSqrt() < distance * distance;
}

std::shared_ptr<AiState> HeadDestination::NextState(int difficulty)
{
	return std::make_shared<HeadDestination>(m_character, m_destination);
}