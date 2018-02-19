#include <Character\Controller\ai_controller.h>

using namespace Character;

AiController::AiController()
{
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

bool  AiController::IsPunchTrigger()
{
	return m_current_punch && !m_previous_punch;
}

bool  AiController::IsKickTrigger()
{
	return m_current_kick && !m_previous_kick;
}

bool  AiController::IsRun()
{
	return m_run;
}

bool  AiController::IsJumpTrigger()
{
	return m_current_jump && !m_previous_jump;
}

bool  AiController::IsDefence()
{
	return m_defence;
}


void AiController::Update()
{
	m_previous_jump = m_current_jump;
	m_previous_kick = m_current_kick;
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
