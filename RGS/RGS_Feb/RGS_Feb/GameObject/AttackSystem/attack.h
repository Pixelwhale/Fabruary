//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2018.02.05
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
		Attack(Math::Vector3 position, Math::Vector3 size, Side side, int atk, int knockdown, int knockback, bool repeat_hit = false);

		//キャラに当たる後Attack自身のリアクション
		//Attacksを後はAttackManagerに入れる。
		virtual std::vector<std::shared_ptr<Attack>>& Collide() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;

		Math::CollisionBox GetBox() const
		{
			return Math::CollisionBox(m_position - m_size / 2, m_position + m_size / 2);
		}

		float GetPositionX() { return m_position.x; }
		Side GetSide() const { return m_side; }
		int GetAtk() const { return m_atk; }
		int GetKnockBack() const { return m_knockback; }
		int GetKnockDown() const { return m_knockdown; }

		//重複判定にかかわる
		bool IsRepeat() const { return m_repeat_hit; }
		void AddID(int ID) { m_attacked_list.push_back(ID); }
		const std::vector<int>& GetAttackedList() const { return m_attacked_list; }

		bool IsEnd() const { return m_is_end; }

	protected:
		//CollisionBoxの生成用
		Math::Vector3 m_position;		//CollisionBoxの中心位置
		Math::Vector3 m_size;			//CollisionBoxの大きさ

		Side m_side;

		int m_atk;			//攻撃力
		int m_knockback;	//撃退の距離
		int m_knockdown;	//倒れる値、キャラの上限値超えると倒れる

		bool m_is_end;

		bool m_repeat_hit;		//重複判定できるスキルはtrue
		std::vector<int> m_attacked_list;
	};
}
