//-------------------------------------------------------
// ì¬ÒFœ@Œ[Ÿ
// ì¬“úF2018.02.05
//-------------------------------------------------------
#include <Scene\pause.h>

using namespace Scene;

Pause::Pause()
{
}

void Pause::Update()
{
}

void Pause::Draw()
{
	m_renderer->DrawString("Pause", Math::Vector2(150, 0));
}

void Pause::Shutdown()
{
}