//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.02.05
//-------------------------------------------------------
#include <Scene\end.h>

using namespace Scene;

End::End()
{
}

void End::Update()
{
}

void End::Draw()
{
	m_renderer->DrawString("End", Math::Vector2(150, 0));
}

void End::Shutdown()
{
}