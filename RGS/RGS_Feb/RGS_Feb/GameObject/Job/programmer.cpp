//-------------------------------------------------------
// �쐬�ҁF�V�X�����g���T
// �쐬���F2017.02.05
// ���e�@�F�L�����N�^�[�̃W���u�̃C���^�t�F�[�X
//-------------------------------------------------------

#include <GameObject\Job\programmer.h>

using namespace Job;

//�R���X�g���N�^
Programmer::Programmer(int punch_count, int kick_count)
{
	CharacterTraits(punch_count, kick_count);
}

//�f�X�g���N�^
Programmer::~Programmer() {}

void Job::Programmer::Punch(AttackSystem::AttackManager & attack_manager, Math::Vector3 position, Math::Vector3 size, int knockdown, int knockback, bool is_left, float life_span_timer)
{
	//std::shared_ptr<AttackSystem::Attack> punch(new AttackSystem::Punch(position, size, GetSide(), knockdown, knockback, life_span_timer));
	//attack_manager.AddAttack(punch);
}

void Job::Programmer::Kick(AttackSystem::AttackManager & attack_manager, Math::Vector3 position, Math::Vector3 size, int knockdown, int knockback, bool is_left, float life_span_timer)
{
	//std::shared_ptr<AttackSystem::Attack> kick(new AttackSystem::Punch(position, size, GetSide(), knockdown, knockback, life_span_timer));
	//attack_manager.AddAttack(kick);
}

void Job::Programmer::Skill1(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, Math::Vector3 size, int knockdown, int knockback, bool is_left, float life_span_timer)
{

}

void Job::Programmer::Skill2(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, Math::Vector3 size, int knockdown, int knockback, bool is_left, float life_span_timer)
{

}

void Job::Programmer::Skill3(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, Math::Vector3 size, int knockdown, int knockback, bool is_left, float life_span_timer)
{

}

void Job::Programmer::Skill4(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, Math::Vector3 size, int knockdown, int knockback, bool is_left, float life_span_timer)
{

}

