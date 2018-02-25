//-------------------------------------------------------
// çÏê¨é“ÅFú@å[èü
// çÏê¨ì˙ÅF2018.02.05
//-------------------------------------------------------
#include <Scene\tutorial.h>

using namespace Scene;

Tutorial::Tutorial()
{
}

void Tutorial::Initialize(SceneType previous) 
{
	SceneBase::Initialize(previous);

	m_background = make_shared<Background>();
}

void Tutorial::Update()
{
	m_background->Update();
}

void Tutorial::Draw()
{
	m_renderer->DrawOnBloomFilter();		//DrawFilter
	m_background->DrawBack();				//îwåi
	m_background->DrawFront();				//ëOåi


	m_renderer->DrawBloom();				//BloomEffect
}

void Tutorial::Shutdown()
{
	m_background = NULL;
}