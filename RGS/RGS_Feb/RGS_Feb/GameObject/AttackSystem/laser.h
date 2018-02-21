//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.21
// 内容　：長くなるとか、大きくなるとか前に直線に行くスキル
//-------------------------------------------------------

#pragma once
#include <GameObject\AttackSystem\attack.h>
#include <Utility\timer.h>

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
		Laser(Math::Vector3 first_position, Math::Vector3 size, Side side, int attack, int knockdown, int knockback, Math::Vector3 added_position, Math::Vector3 added_size, float life_span_timer);
		~Laser();
		virtual std::vector < std::shared_ptr<Attack>>& Collide();
		virtual void Update();
		virtual void Draw();

	private :
		Utility::Timer m_life_span_timer;
		Math::Vector3 m_added_position;
		Math::Vector3 m_added_size;
	};
}