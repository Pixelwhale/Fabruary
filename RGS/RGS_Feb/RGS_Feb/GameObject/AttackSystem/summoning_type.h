//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.21
// 内容　：このスキルは攻撃ダメージが零だが、他のスキル玉を生成する。
//-------------------------------------------------------

#pragma once
#include <GameObject\AttackSystem\attack.h>
#include <Utility\timer.h>

namespace AttackSystem
{
	class SummoningType : public Attack
	{
	public :
		///<summary>コンストラクタ</summary>
		///<param name = "side">キャラクターはどんなチームに属する</param>
		///<param name = "position">キャラクターの位置</param>
		///<param name = "size">攻撃の大きさ</param>
		///<param name = "attack">攻撃ポイント</param>
		///<param name = "knockdown">敵を倒せられるか？</param>
		///<param name = "knockback">敵を押されるか？</param>
		///<param name = "life span">何秒に実現させるのか？</param>
		SummoningType(Math::Vector3 position, Math::Vector3 size, Side side, int attack, int knockdown, int knockback, float life_span_timer);
		~SummoningType();
		virtual std::vector <std::shared_ptr<Attack>>& Collide();
		virtual void Update();
		virtual void Draw();

	private :
		Utility::Timer m_life_span_timer;
	};
}
