//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.22
// 内容　：ダメージを担当する当たり判定
//-------------------------------------------------------

#pragma once
#include <GameObject\AttackSystem\attack.h>
#include <Utility\timer.h>
#include <Device\MotionSystem\motion.h>

namespace AttackSystem
{
	class Damage : public Attack
	{
	public :
		///<summary>コンストラクタ</summary>
		///<param name = "side">キャラクターはどんなチームに属する</param>
		///<param name = "position">キャラクターの位置</param>
		///<param name = "size">攻撃の大きさ</param>
		///<param name = "life span">何秒に実現させるのか？</param>
		Damage(Math::Vector3 position, Math::Vector3 size, Side side, int attack, int knockdown, int knockback, int dbreak, std::string animationToPlay, float life_span_timer);
		~Damage();
		virtual std::vector<std::shared_ptr<Attack>> Collide();
		virtual void Update();
		virtual void Draw();

	private :
		Utility::Timer m_life_span_timer;	// まだあったているか？

		std::shared_ptr<MotionSystem::Motion> m_motion;
	};
}
