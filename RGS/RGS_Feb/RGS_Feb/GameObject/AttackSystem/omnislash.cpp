//-------------------------------------------------------
// �쐬�ҁF�V�X�����g���T
// �쐬���F2018.02.23
// ���e�@�F�U���i�I���j�X���b�V���j�̓����蔻��
//-------------------------------------------------------

#include <GameObject\AttackSystem\omnislash.h>
#include <GameObject\AttackSystem\damage.h>

using namespace AttackSystem;

OmniSlash::OmniSlash(Math::Vector3 position, Math::Vector3 size, Side side, int attack, int knockdown, int knockback, int dbreak, float life_span_timer)
	: Attack(Math::Vector3(), Math::Vector3(), side, 0, 0, 0, 0), m_life_span_timer(life_span_timer)
{
	m_c_size = size;
	m_c_attack = attack;
	m_c_knockback = knockback;
	m_c_knockdown = knockdown;
	m_c_dbreak = dbreak;
}

// �f�X�g���N�^
OmniSlash::~OmniSlash() {}

std::vector<std::shared_ptr<Attack>> OmniSlash::Collide()
{
	std::vector<std::shared_ptr<Attack>> attack;
	attack.clear();
	attack.push_back(std::make_shared<AttackSystem::Damage>
}

