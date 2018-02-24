//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.19
// 内容　：Aiで制御するキャラコントローラー
//-------------------------------------------------------------
#include <Character\Controller\ai_controller.h>

using namespace Character;

AiController::AiController(int player_num)
{
	m_velocity = Math::Vector3();
	m_previous_punch = false;
	m_current_punch = false;
	m_previous_kick = false;
	m_current_kick = false;
	m_run = false;
	m_previous_jump = false;
	m_current_jump = false;
	m_defence = false;

	m_player_num = player_num;
	m_tag = make_shared<MotionSystem::Motion>("Character");
	m_tag->Initialize();
	string asset = "chara_tag/";
	m_tag->Play((asset + "com"));
}

AiController::AiController(const AiController&)
{
}

AiController::~AiController()
{
}


Math::Vector3 AiController::Velocity()
{
	return m_velocity;
}

bool AiController::IsPunchTrigger()
{
	return m_current_punch && !m_previous_punch;
}

bool AiController::IsKickTrigger()
{
	return m_current_kick && !m_previous_kick;
}

bool AiController::IsRun()
{
	return m_run;
}

bool AiController::IsJumpTrigger()
{
	return m_current_jump && !m_previous_jump;
}

bool AiController::IsDefence()
{
	return m_defence;
}

bool AiController::IsPause() 
{
	return false;
}


void AiController::Update()
{
	m_previous_jump = m_current_jump;
	m_previous_kick = m_current_kick;
	m_previous_punch = m_current_punch;

	m_current_jump = false;
	m_current_kick = false;
	m_current_punch = false;
	m_run = false;
	m_defence = false;
}

void AiController::SetVelocity(Math::Vector3 velocity)
{
	m_velocity = velocity;
}

void AiController::TriggerPunch()
{
	m_current_punch = true;
}

void AiController::TriggerKick()
{
	m_current_kick = true;
}

void AiController::TriggerJump()
{
	m_current_jump = true;
}

void AiController::Run()
{
	m_run = true;
}

void AiController::Defence()
{
	m_defence = true;
}

void AiController::Draw()
{
	m_tag->Draw();
}

void AiController::SetTagColor(Color color)
{
	m_tag->SetColor(color);
}

void AiController::UpdateMotion(Math::Vector3 draw_pos)
{
	m_tag->SetPosition(draw_pos);
	m_tag->Update();
}
