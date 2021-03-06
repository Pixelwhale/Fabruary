//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2018.02.05
//-------------------------------------------------------
#include "collision_box.h"

using namespace Math;

bool CollisionBox::IsCollision(const CollisionBox& other) const
{
	if (CheckX(other) && CheckY(other) && CheckZ(other)) return true;
	return false;
}

bool CollisionBox::CheckX(const CollisionBox& other) const
{
	if (m_min.x <= other.m_min.x && m_max.x >= other.m_min.x) return true;
	if (other.m_min.x <= m_min.x && other.m_max.x >= m_min.x) return true;
	return false;
}

bool CollisionBox::CheckY(const CollisionBox& other) const
{
	if (m_min.y <= other.m_min.y && m_max.y >= other.m_min.y) return true;
	if (other.m_min.y <= m_min.y && other.m_max.y >= m_min.y) return true;
	return false;
}

bool CollisionBox::CheckZ(const CollisionBox& other) const
{
	if (m_min.z <= other.m_min.z && m_max.z >= other.m_min.z) return true;
	if (other.m_min.z <= m_min.z && other.m_max.z >= m_min.z) return true;
	return false;
}