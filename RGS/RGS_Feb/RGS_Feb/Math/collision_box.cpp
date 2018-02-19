//-------------------------------------------------------
// ì¬ÒFœ@Œ[Ÿ
// ì¬“úF2018.02.05
//-------------------------------------------------------
#include "collision_box.h"

using namespace Math;

bool CollisionBox::IsCollision(CollisionBox& other)
{
	if (CheckX(other) && CheckY(other) && CheckZ(other)) return true;
	return false;
}

bool CollisionBox::CheckX(CollisionBox& other)
{
	if (m_min.x <= other.m_min.x && m_max.x <= other.m_max.x) return true;
	if (other.m_min.x <= m_min.x && other.m_max.x <= m_max.x) return true;
	return false;
}

bool CollisionBox::CheckY(CollisionBox& other)
{
	if (m_min.y <= other.m_min.y && m_max.y <= other.m_max.y) return true;
	if (other.m_min.y <= m_min.y && other.m_max.y <= m_max.y) return true;
	return false;
}

bool CollisionBox::CheckZ(CollisionBox& other)
{
	if (m_min.z <= other.m_min.z && m_max.z <= other.m_max.z) return true;
	if (other.m_min.z <= m_min.z && other.m_max.z <= m_max.z) return true;
	return false;
}