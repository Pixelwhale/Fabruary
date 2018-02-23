//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.19
// 内容　：Keyboardで制御するキャラコントローラー
//-------------------------------------------------------------
#include <Character\Controller\keyboard_controller.h>

using namespace Character;

KeyboardController::KeyboardController(int player_num)
{
	m_input = Device::GameDevice::GetInstance()->GetInput();
	m_player_num = player_num;

	m_tag = make_shared<MotionSystem::Motion>("Character");
	m_tag->Initialize();
	string asset = "chara_tag/";
	string player = "p";
	m_tag->Play((asset + std::to_string(m_player_num) + player));
}

KeyboardController::KeyboardController(const KeyboardController&)
{
}

KeyboardController::~KeyboardController()
{
	m_input = NULL;
	m_tag = NULL;
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

bool KeyboardController::IsPause() 
{
	return m_input->IsKeyTrigger(KEY_INPUT_P);
}


void KeyboardController::Draw() 
{
	m_tag->Draw();
}

void KeyboardController::SetTagColor(Color color)
{
	m_tag->SetColor(color);
}

void KeyboardController::UpdateMotion(Math::Vector3 draw_pos)
{
	m_tag->SetPosition(draw_pos);
	m_tag->Update();
}