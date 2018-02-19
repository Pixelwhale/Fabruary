//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.15
// 内容　：攻撃（キック）の当たり判定
//-------------------------------------------------------

#pragma once

#include <GameObject\AttackSystem\attack.h>
#include <Utility\timer.h>

namespace AttackSystem
{
	class Kick : public Attack
	{
	public :
		///<summary>コンストラクタ</summary>
		///<param name = "side">キャラクターはどんなチームに属する</param>
		///<param name = "position">キャラクターの位置</param>
		///<param name = "size">攻撃の大きさ</param>
		///<param name = "life span">何秒に実現させるのか？</param>
		Kick(Math::Vector3 position, Math::Vector3 size, Side side, int knockdown, int knockback, float life_span_timer);
		~Kick();
		virtual void Collide(AttackManager attackManager);
		virtual void Update();
		virtual void Draw();

	private:
		Utility::Timer m_life_span_timer; // まだあったているか？
	};
}