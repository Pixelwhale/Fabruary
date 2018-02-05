//-------------------------------------------------------
// çÏê¨é“ÅFú@å[èü
// çÏê¨ì˙ÅF2017.02.05
//-------------------------------------------------------
#pragma once
#include "vector3.h";

namespace Math
{
	class CollisionBox
	{
	public:
		CollisionBox(Vector3& min, Vector3& max) : m_min(min), m_max(max) {};
		bool IsCollision(CollisionBox& other);
	private:
		bool CheckX(CollisionBox& other);
		bool CheckY(CollisionBox& other);
		bool CheckZ(CollisionBox& other);
		Vector3& m_min;
		Vector3& m_max;
	};
}