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
	std::shared_ptr<Character::CharacterBase> target)
	:m_character(my_chara), m_target(target)
{
}

Trace::Trace(const Trace&) {}
Trace::~Trace()
{
	m_character = NULL;
	m_target = NULL;
}

void Trace::GetBattleInfo(std::shared_ptr<MetaAI> meta_ai)
{
	return;
}

void Trace::Update(std::shared_ptr<Character::AiController> controller)
{
	if (InRange(40))					//近すぎると終了
	{
		m_end_flag = true;
		return;
	}

	Math::Vector3 velocity = m_target->GetPosition() - m_character->GetPosition();
	velocity = velocity.normalize();
	controller->SetVelocity(velocity);

	if (!InRange(256))					//距離が長いと走る
		controller->Run();
}

bool Trace::InRange(float distance)
{
	return (m_character->GetPosition() - m_target->GetPosition()).lengthSqrt() < distance * distance;
}

std::shared_ptr<AiState> Trace::NextState(int difficulty)
{
	return std::make_shared<Trace>(m_character, m_target->GetPosition());
}