//-------------------------------------------------------
// 作成者：金　淳元
// 作成日：2018.02.05
// 内容　：キャラクターのベースクラス
//-------------------------------------------------------
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
	float speed = 5;
	if (true)
	{
		speed += 0.2;
		if (speed >= 8)
		{
			speed = 8;
		}
	}
	m_position += m_velocity * speed;
}

void CharacterBase::GageUpdate()
{
	++m_gage;
	if (m_gage >= 3000)
	{
		m_gage = 3000;
	}
}


