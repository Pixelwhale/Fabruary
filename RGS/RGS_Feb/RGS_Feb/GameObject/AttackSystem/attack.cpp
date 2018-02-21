//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2018.02.15
// 内容：攻撃のインターフェース。
//-------------------------------------------------------
#include "attack.h"

using namespace AttackSystem;
using namespace Math;
using namespace Size;

Attack::Attack(Vector3 position, Vector3 size, Side side, int dmg, int knockback, int knockdown, int dbreak, int cool_down, Direction source_dir)
{
	m_position = position;
	m_size = size;
	m_side = side;
	m_dmg = dmg;
	m_knockback = knockback;
	m_knockdown = knockdown;
	m_break = dbreak;
	m_cool_down = cool_down;
	m_source_dir = source_dir;
	m_timer = 0;
	m_is_end = false;
}