//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.19
// ���e�@�FNormalKick��AiState
//-------------------------------------------------------------
#include <GameObject\AI\CharaAI\Combo\ai_normal_kick.h>
#include <Character\character_base.h>

using namespace AI;

NormalKick::NormalKick(
	std::shared_ptr<Character::CharacterBase> my_chara,
	std::shared_ptr<Character::CharacterBase> target)
	:m_character(my_chara), m_target(target)
{
	m_end_flag = false;
}

NormalKick::NormalKick(const NormalKick&)
{
}

NormalKick::~NormalKick()
{
	m_character = NULL;
	m_target = NULL;
}

void NormalKick::GetBattleInfo(MetaAI* meta_ai)
{
	return;
}

void NormalKick::Update(std::shared_ptr<Character::AiController> controller)
{
	if (!IsInAttckRange())			//�͈͓������f����
		return;

	controller->TriggerKick();		//�p���`����
	m_end_flag = true;
}

std::shared_ptr<AiState> NormalKick::NextState(int difficulty)
{
	return std::make_shared<NormalKick>(m_character, m_target);
}

bool NormalKick::IsInAttckRange()
{
	float distance = (m_character->GetPosition() - m_target->GetPosition()).lengthSqrt();
	return distance < (Size::kCharaX * 2.0f) * (Size::kCharaX * 2.0f);
}