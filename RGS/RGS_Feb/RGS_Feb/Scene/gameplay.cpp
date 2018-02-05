//-------------------------------------------------------
// ì¬ÒFœ@Œ[Ÿ
// ì¬“úF2017.02.05
//-------------------------------------------------------
#include <Scene\gameplay.h>

using namespace Scene;

GamePlay::GamePlay()
{
}

void GamePlay::Update()
{
}

void GamePlay::Draw()
{
	m_renderer->DrawString("GamePlay", Math::Vector2(150, 0));
}

void GamePlay::Shutdown()
{
}