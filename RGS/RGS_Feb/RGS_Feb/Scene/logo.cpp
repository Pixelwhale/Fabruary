//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.27
// 内容　：LogoScene
//-------------------------------------------------------
#include <Scene\logo.h>
#include <Def\window_def.h>

using namespace Scene;

Logo::Logo()
{

}

void Logo::Initialize(SceneType previous)
{
	SceneBase::Initialize(previous);
	m_team_logo = make_shared<MotionSystem::Motion>("Logo");
	m_team_logo->Play("Logo/Logo", 1);
	m_team_logo->Initialize();
	m_team_logo->SetPosition(Math::Vector3(
		WindowDef::kScreenWidth / 2, WindowDef::kScreenHeight / 2, 0));
	m_team_logo->SetScale(Math::Vector2(1, 1));

	m_logo_timer = Utility::Timer(3.5f);
	m_logo_timer.Reset();
}

void Logo::Update()
{
	UpdateSchool();
	UpdateTeam();

	CheckEnd();
}

void Logo::UpdateSchool()
{
	m_logo_timer.Update();
}

void Logo::UpdateTeam()
{
	if (!m_logo_timer.IsTime())
		return;

	m_team_logo->Update();
}

void Logo::Draw()
{
	m_renderer->DrawFade(Color(0, 0, 0), 1.0f);

	float rate = m_logo_timer.Rate() * 2 - 1;
	if (rate < 0)
		rate *= -1;

	if (!m_logo_timer.IsTime())
		m_renderer->DrawTexture("NEEC1280black", Math::Vector2(), 1 - rate);

	if (!m_logo_timer.IsTime())
		return;

	m_team_logo->Draw2D();
}

void Logo::Shutdown()
{
	m_team_logo = NULL;
}

void Logo::CheckEnd()
{
	if (m_team_logo->IsCurrentMotionEnd())
	{
		m_is_end = true;
		m_next = SceneType::kTitle;
	}
}