//-------------------------------------------------------
// çÏê¨é“ÅFú@å[èü
// çÏê¨ì˙ÅF2018.02.05
//-------------------------------------------------------
#pragma once
#include "vector3.h";

namespace Math
{
	class CollisionBox
	{
	public:
		CollisionBox(Vector3 min, Vector3 max) : m_min(min), m_max(max) {};
		bool IsCollision(const CollisionBox& other) const;

	private:
		bool CheckX(const CollisionBox& other) const;
		bool CheckY(const CollisionBox& other) const;
		bool CheckZ(const CollisionBox& other) const;
		Vector3& m_min;
		Vector3& m_max;
	};
}