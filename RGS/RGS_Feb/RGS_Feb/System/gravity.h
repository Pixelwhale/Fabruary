//-------------------------------------------------------
// ì¬ÒFœ@Œ[Ÿ
// ì¬“úF2017.02.05
//-------------------------------------------------------
#pragma once
#include <Math\vector3.h>

namespace System
{
	class Gravity
	{
	public:
		Gravity();
		~Gravity();
		void Update(Math::Vector3& velocity);
	private:
		const float kG = 10.0f;
		bool m_on_ground;
	};
}