//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.02.05
// 内容：攻撃のインターフェース。
//-------------------------------------------------------
#pragma once
#include <Math\vector3.h>
#include <Math\collision_box.h>

namespace AttackSystem
{
	class Attack
	{
	public:
		Attack(Math::Vector3 position, Math::Vector3 size) : m_position(position), m_size(size) {};
		virtual void Collide() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;
		bool IsEnd() { return m_is_end; }
		Math::CollisionBox GetBox()
		{
			return Math::CollisionBox(m_position - m_size / 2, m_position + m_size / 2);
		}
	private:
		bool m_is_end;

		//CollisionBoxの生成用
		Math::Vector3 m_position;		//CollisionBoxの中心位置
		Math::Vector3 m_size;			//CollisionBoxの大きさ
	};
}
