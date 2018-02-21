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
	enum Direction
	{
		kCenter,
		kRight,
		kLeft,
	};
	struct Attacked
	{
		Attacked(int id, int cool_down) : id(id), cool_down(cool_down) {}
		int id;
		int cool_down;
	};

	class Attack
	{
	public:
		Attack(Math::Vector3 position, Math::Vector3 size, Side side, int dmg, int knockdown, int knockback, int dbreak, int cool_down = -1, Direction source_dir = kCenter);

		//キャラに当たる後Attack自身のリアクション
		//Attacksを後はAttackManagerに入れる。
		virtual std::vector<std::shared_ptr<Attack>>& Collide() = 0;

		virtual void Update()
		{
			//attacked cool downのUpdate
			for (auto attacked : m_attacked_list) { --attacked.cool_down; }
		};

		virtual void Draw() = 0;

		Math::CollisionBox GetBox() const
		{
			return Math::CollisionBox(m_position - m_size / 2, m_position + m_size / 2);
		}

		const Math::Vector3& GetPosition() const { return m_position; }
		Side GetSide() const { return m_side; }
		int GetAtk() const { return m_atk; }
		int GetKnockBack() const { return m_knockback; }
		int GetKnockDown() const { return m_knockdown; }
		int GetBreak() const { return m_break; }

		//重複判定にかかわる
		int IsRepeat() const { return m_cool_down; }
		void AddID(int id) { m_attacked_list.push_back(Attacked(id, m_cool_down)); }
		const std::vector<Attacked>& GetAttackedList() const { return m_attacked_list; }

		Direction GetSourceDir() const { return m_source_dir; }

		bool IsEnd() const { return m_is_end; }

	protected:
		//CollisionBoxの生成用
		Math::Vector3 m_position;		//CollisionBoxの中心位置
		Math::Vector3 m_size;			//CollisionBoxの大きさ

		Side m_side;

		int m_dmg;			//攻撃力
		int m_knockback;	//撃退の距離
		int m_knockdown;	//倒れる値
		int m_break;		//防御を崩れる値

		bool m_is_end;

		int m_cool_down;		//キャラはフレームことに判定する。重複判定しないスキルは-1に設定する
		std::vector<Attacked> m_attacked_list;

		Direction m_source_dir;
	};
}
