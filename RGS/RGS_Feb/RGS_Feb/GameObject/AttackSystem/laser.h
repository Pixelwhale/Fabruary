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
		///<summary> </summary>
		Laser(Math::Vector3 position, Math::Vector3 size, Side side, int attack, int knockdown, int knockback, float life_span_timer);
		~Laser();
		virtual std::vector < std::shared_ptr<Attack>>& Collide();
		virtual void Update();
		virtual void Draw();

	private :
		Utility::Timer m_life_span_timer;
	};
}