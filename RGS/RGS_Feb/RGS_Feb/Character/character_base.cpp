#include <Character\character_base.h>

using namespace Character;

CharacterBase::CharacterBase(Math::Vector3 velocity)
{
	m_velocity = velocity;
	m_hp = 500;
	m_gage = 0;
}

CharacterBase::~CharacterBase()
{
}

void CharacterBase::Initialize()
{
	m_hp = 500;
	m_gage = 0;
}

void CharacterBase::Update()
{
	MoveUpdate();
	GageUpdate();
}

void CharacterBase::MoveUpdate()
{
	m_position += m_velocity;
}

void CharacterBase::GageUpdate()
{
	++m_gage;
	if (m_gage >= 100)
	{
		m_gage = 100;
	}
}


