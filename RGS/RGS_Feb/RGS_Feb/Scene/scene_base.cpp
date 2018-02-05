//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.18
// 内容　：シーンのベースクラス
//-------------------------------------------------------
#include <Scene\scene_base.h>

using namespace Scene;
using namespace Device;

SceneBase::SceneBase()
{
	m_renderer = GameDevice::GetInstance()->GetRenderer();
	m_input = GameDevice::GetInstance()->GetInput();
}

void SceneBase::Initialize(SceneType previous)
{
	m_end_flag = false;
	m_previous = previous;
}