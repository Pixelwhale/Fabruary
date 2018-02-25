//-------------------------------------------------------
// ì¬ÒFœ@Œ[Ÿ
// ì¬“úF2018.02.05
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
	m_renderer->DrawFade(Color(0, 0, 0));
}

void End::Shutdown()
{
}