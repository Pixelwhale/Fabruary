//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.02.05
// 内容：攻撃のインターフェース。
//-------------------------------------------------------
#pragma once
#include <Math\vector3.h>
#include <Math\collision_box.h>
#include <Character\side.h>
#include <Def\size.h>
#include <vector>
#include <memory>

namespace AttackSystem
{
	class Attack
	{
	public:
		Attack(Math::Vector3 position, Math::Vector3 size, Side side, int knockdown, int knockback, bool repeat_hit = false);

		//キャラに当たる後Attack自身のリアクション
		virtual void Collide() = 0;

		virtual void Update() = 0;
		virtual void Draw() = 0;

		Math::CollisionBox GetBox()
		{
			return Math::CollisionBox(m_position - m_size / 2, m_position + m_size / 2);
		}

		Side GetSide() { return m_side; }
		int GetKnockBack() { return m_knockback; }
		int GetKnockDown() { return m_knockdown; }

		bool IsRepeat() { return m_repeat_hit; }
		//重複判定を避けるため
		//std::vector<CharaID> GetAttackedList() { return m_attacked_list; }

		bool IsEnd() { return m_is_end; }

	protected:
		//CollisionBoxの生成用
		Math::Vector3 m_position;		//CollisionBoxの中心位置
		Math::Vector3 m_size;			//CollisionBoxの大きさ

		Side m_side;

		int m_knockback;
		int m_knockdown;

		bool m_is_end;

		bool m_repeat_hit;		//重複判定できるスキルはtrue
		//std::vector<CharaID> m_attacked_list;
	};
}
