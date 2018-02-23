//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.21
// 内容　：特定のキャラを追尾するAiState
//-------------------------------------------------------------
#include <GameObject\AI\CharaAI\Move\ai_trace.h>
#include <Character\character_base.h>

using namespace AI;

Trace::Trace(
	std::shared_ptr<Character::CharacterBase> my_chara,
	std::shared_ptr<Character::CharacterBase> target,
	int difficulty)
	:m_character(my_chara), m_target(target), m_difficulty(difficulty)
{
	m_end_flag = false;
}

Trace::Trace(const Trace&) {}
Trace::~Trace()
{
	m_character = NULL;
	m_target = NULL;
}

void Trace::GetBattleInfo(MetaAI* meta_ai)
{
	return;
}

void Trace::Update(std::shared_ptr<Character::AiController> controller)
{
	if (m_target == NULL || m_target->IsDead()) 
	{
		m_end_flag = true;
		return;
	}

	if (InRange(130))							//近すぎると終了
	{
		controller->SetVelocity(Math::Vector3());
		m_end_flag = true;
		return;
	}

	m_end_flag = false;

	Math::Vector3 velocity = m_target->GetPosition() - m_character->GetPosition();
	velocity.x *= 0.6f;
	velocity = velocity.normalize();
	controller->SetVelocity(velocity);

	if (!InRange(300) && m_difficulty > 4)		//距離が長いと走る
	{
		controller->Run();
	}

	if (InRange(250) &&
		m_target->GetPosition().y > 200)
		controller->TriggerJump();
}

bool Trace::InRange(float distance)
{
	float z = m_target->GetPosition().z - m_character->GetPosition().z;
	z = (z < 0) ? -z : z;
	if (z > Size::kCharaZ / 3.0f)
		return false;

	float a = (m_target->GetPosition() - m_character->GetPosition()).lengthSqrt();
	float b = distance * distance;

	return (m_target->GetPosition() - m_character->GetPosition()).lengthSqrt() < distance * distance;
}

std::shared_ptr<AiState> Trace::NextState(int difficulty)
{
	return std::make_shared<Trace>(m_character, m_target, difficulty);
}