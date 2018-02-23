//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.19
// 内容　：Padで制御するキャラコントローラー
//-------------------------------------------------------------
#include <Character\Controller\pad_controller.h>

using namespace Character;

PadController::PadController(int pad_id, int player_num)
	:m_pad_id(pad_id)
{
	m_input = Device::GameDevice::GetInstance()->GetInput();
	m_player_num = player_num;

	m_tag = make_shared<MotionSystem::Motion>("Character");
	m_tag->Initialize();
	string asset = "chara_tag/";
	string player = "p";
	m_tag->Play((asset + std::to_string(m_player_num) + player));
}

PadController::PadController(const PadController&)
{
}

PadController::~PadController()
{
	m_input = NULL;
}


Math::Vector3 PadController::Velocity()
{
	return m_input->GetLeftStick(m_pad_id);
}

bool PadController::IsPunchTrigger()
{
	return m_input->IsPadButtonTrigger(m_pad_id, XINPUT_BUTTON_X);
}

bool PadController::IsKickTrigger()
{
	return m_input->IsPadButtonTrigger(m_pad_id, XINPUT_BUTTON_B);
}

bool PadController::IsRun()
{
	return m_input->IsPadButtonTrigger(m_pad_id, XINPUT_BUTTON_RIGHT_SHOULDER);
}

bool PadController::IsJumpTrigger()
{
	return m_input->IsPadButtonTrigger(m_pad_id, XINPUT_BUTTON_A);
}

bool PadController::IsDefence()
{
	return m_input->IsPadButtonTrigger(m_pad_id, XINPUT_BUTTON_LEFT_SHOULDER);
}

bool PadController::IsPause() 
{
	return m_input->IsPadButtonTrigger(m_pad_id, XINPUT_BUTTON_START);
}


void PadController::Draw()
{
	m_tag->Draw();
}

void PadController::SetTagColor(Color color)
{
	m_tag->SetColor(color);
}

void PadController::UpdateMotion(Math::Vector3 draw_pos)
{
	m_tag->SetPosition(draw_pos);
	m_tag->Update();
}