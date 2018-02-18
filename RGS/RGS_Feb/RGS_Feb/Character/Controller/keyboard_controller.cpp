//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.19
// 内容　：Keyboardで制御するキャラコントローラー
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