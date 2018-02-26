//-------------------------------------------------------
// ì¬ÒFœ@Œ[Ÿ
// ì¬“úF2018.02.19
//-------------------------------------------------------
#include "scene_fader.h"
#include <Def\window_def.h>

using namespace Scene;

SceneFader::SceneFader(std::shared_ptr<SceneBase> scene, float fade_in_sec, float fade_out_sec)
{
	m_scene = scene;
	m_fade_in = Utility::Timer(fade_in_sec);
	m_fade_out = Utility::Timer(fade_out_sec);
}

void SceneFader::Initialize(SceneType previous)
{
	state = kIn;
	SceneBase::Initialize(previous);
	m_scene->Initialize(previous);

	ResetFadeIn();
	ResetFadeOut();
}

void SceneFader::ResetFadeIn() 
{
	if (m_previous == SceneType::kCharaSelect ||
		m_previous == SceneType::kTutorial ||
		m_previous == SceneType::kCredit)
		return;

	m_fade_in.Reset();
}

void SceneFader::ResetFadeOut() 
{
	m_fade_out.Reset();
}

void SceneFader::Update()
{
	switch (state)
	{
	case kIn:
		m_fade_in.Update();
		if (m_fade_in.IsTime()) state = kNone;
		break;
	case kNone:
		m_scene->Update();
		if (m_scene->IsEnd()) state = kOut;
		break;
	case kOut:
		m_fade_out.Update();
		if (m_fade_out.IsTime())
		{
			m_is_end = true;
			m_next = m_scene->Next();
		}
		break;
	}
}

void SceneFader::Draw()
{
	m_scene->Draw();

	switch (state)
	{
	case kIn:
		m_renderer->DrawFade(Color(0, 0, 0), m_fade_in.Rate());
		break;
	case kOut:
		m_renderer->DrawFade(Color(0, 0, 0), 1 - m_fade_out.Rate());
		break;
	default:
		break;
	}

}

void SceneFader::Shutdown()
{
	m_scene->Shutdown();
}