//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.21
// 内容　：長くなるとか、大きくなるとか前に直線に行くスキル
//-------------------------------------------------------

#pragma once
#include <GameObject\AttackSystem\attack.h>
#include <Utility\timer.h>
#include <Device\MotionSystem\motion.h>

namespace AttackSystem
{
	class Laser : public Attack
	{
	public :
		///<summary>コンストラクタ</summary>
		///<param name = "first position">最初の位置</param>
		///<param name = "size">スキルのサイズ</param>
		///<param name = "side">サイド</param>
		///<param name = "attack">攻撃ポイント</param>
		///<param name = "knockdown">敵を倒せられるか？</param>
		///<param name = "knockback">敵を押されるか？</param>
		///<param name = "added position">前に動かせるため</param>
		///<param name = "added size">サイズが変更できるため</param>
		///<param name = "life span">何秒に実現させるのか？</param>
		///<param name = "take damage at">
		Laser(Math::Vector3 first_position, Math::Vector3 size, Side side, std::string animation_to_play, int attack, int knockdown, int knockback, int dbreak, int damage_combo, float life_span_timer, float take_damage_at, Direction source_dir);
		~Laser();
		virtual std::vector <std::shared_ptr<Attack>> Collide();
		virtual void Update();
		virtual void Draw();

	private :
		int m_c_attack;
		int m_c_knockdown;
		int m_c_knockback;
		int m_c_dbreak;
		int m_damage_combo;
		float m_take_damage_at; // いつダメージを受けるか？

		Math::Vector3 m_add_size;
		Math::Vector3 m_add_position;
		Utility::Timer m_life_span_timer;
		std::shared_ptr<MotionSystem::Motion> m_motion;
	};
}