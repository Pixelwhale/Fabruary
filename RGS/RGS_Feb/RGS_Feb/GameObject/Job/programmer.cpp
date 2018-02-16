//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2017.02.05
// 内容　：キャラクターのジョブのインタフェース
//-------------------------------------------------------

#include <GameObject\Job\programmer.h>

using namespace Job;

//コンストラクタ
Programmer::Programmer(int punch_count, int kick_count)
{
	CharacterTraits(punch_count, kick_count);
}

//デストラクタ
Programmer::~Programmer() {}

void Programmer::Punch(AttackSystem::AttackManager & attack_manager, Math::Vector3 position, Math::Vector3 size, bool is_left, float life_span_timer)
{
	std::shared_ptr<AttackSystem::Attack> punch(new AttackSystem::Punch(GetSide(), position, size, life_span_timer));
	attack_manager.AddAttack(punch);
}

void Programmer::Kick(AttackSystem::AttackManager & attack_manager, Math::Vector3 position, Math::Vector3 size, bool is_left, float life_span_timer)
{
	std::shared_ptr<AttackSystem::Attack> kick(new AttackSystem::Punch(GetSide(), position, size, life_span_timer));
	attack_manager.AddAttack(kick);
}

void Programmer::Skill1(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, Math::Vector3 size, bool is_left, float life_span_timer)
{

}

void Programmer::Skill2(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, Math::Vector3 size, bool is_left, float life_span_timer)
{

}

void Programmer::Skill3(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, Math::Vector3 size, bool is_left, float life_span_timer)
{

}

void Programmer::Skill4(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, Math::Vector3 size, bool is_left, float life_span_timer)
{

}

