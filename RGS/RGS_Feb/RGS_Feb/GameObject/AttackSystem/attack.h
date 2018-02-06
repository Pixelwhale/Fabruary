//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.02.05
// 内容：攻撃のインターフェース。
//-------------------------------------------------------
#pragma once
#include <Math\vector3.h>

namespace AttackSystem
{
	class Attack
	{
	public:
		Attack();
		virtual void Update() = 0;
		virtual void Draw() = 0;
		bool IsEnd() { return m_is_end; }
	private:
		short timer;		//単位：frame
		bool m_is_end;
		Math::Vector3 m_position;		//CollisionBoxの中心位置
	};
}
