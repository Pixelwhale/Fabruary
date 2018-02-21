//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.19
// 内容　：NormalKickのAiState
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
	if (!IsInAttckRange())			//範囲内か判断する
		return;

	controller->TriggerKick();		//パンチする
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