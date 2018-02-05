//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.22
// 内容　：タイトルのシーン。スタート、ロード、オプション。
//-------------------------------------------------------
#include <Scene\title.h>

using namespace Scene;

Title::Title()
{
}

void Title::Update()
{
}

void Title::Draw()
{
	m_renderer->DrawString("Title", Math::Vector2(150, 0));
}

void Title::Shutdown()
{
}