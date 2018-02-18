//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.19
// ���e�@�FKeyboard�Ő��䂷��L�����R���g���[���[
//-------------------------------------------------------------
#include <Character\Controller\keyboard_controller.h>

using namespace Character;

KeyboardController::KeyboardController()
{
	m_input = Device::GameDevice::GetInstance()->GetInput();
}

KeyboardController::KeyboardController(const KeyboardController&)
{
}

KeyboardController::~KeyboardController()
{
	m_input = NULL;
}


Math::Vector3 KeyboardController::Velocity()
{
	return m_input->GetKeyBoardVelocity();
}

bool KeyboardController::IsPunchTrigger()
{
	return m_input->IsKeyTrigger(KEY_INPUT_A);
}

bool KeyboardController::IsKickTrigger()
{
	return m_input->IsKeyTrigger(KEY_INPUT_D);
}

bool KeyboardController::IsRun()
{
	return m_input->IsKeyDown(KEY_INPUT_E);
}

bool KeyboardController::IsJumpTrigger()
{
	return m_input->IsKeyTrigger(KEY_INPUT_SPACE);
}

bool KeyboardController::IsDefence()
{
	return m_input->IsKeyDown(KEY_INPUT_Q);
}