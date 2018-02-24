//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.25
// ���e�@�FTitleMenu��State
//-------------------------------------------------------
#include <GameObject\UI\title_state.h>

using namespace UI;

TitleState::TitleState()
{
	m_renderer = Device::GameDevice::GetInstance()->GetRenderer();
	m_input = Device::GameDevice::GetInstance()->GetInput();

	m_end_flag = false;
}

TitleState::TitleState(const TitleState&)
{
}

TitleState::~TitleState()
{
	m_renderer = NULL;
	m_input = NULL;
}

bool TitleState::IsEnd()
{
	return m_end_flag;
}