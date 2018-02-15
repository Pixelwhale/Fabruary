//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.02.15
// 内容：攻撃のインターフェース。
//-------------------------------------------------------
#include "attack.h"

using namespace AttackSystem;
using namespace Math;
using namespace Size;

Attack::Attack(Vector3 position, Vector3 size, Side side, int knockback, int knockdown, bool repeat_hit)
{
	m_position = position;
	m_size = size;
	m_side = side;
	m_knockback = knockback;
	m_knockdown = knockdown;
	m_repeat_hit = repeat_hit;
	m_is_end = false;
}