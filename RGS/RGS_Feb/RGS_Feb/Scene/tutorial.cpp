//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.02.05
//-------------------------------------------------------
#include <Scene\tutorial.h>

using namespace Scene;

Tutorial::Tutorial()
{
}

void Tutorial::Update()
{
}

void Tutorial::Draw()
{
	m_renderer->DrawString("Tutorial", Math::Vector2(150, 0));
}

void Tutorial::Shutdown()
{
}