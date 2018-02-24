//-------------------------------------------------------
// �쐬�ҁF�V�X�����g���T
// �쐬���F2018.02.15
// ���e�@�F�J�E���g�_�E���̃^�C�}�[
//-------------------------------------------------------

#include <Utility\timer.h>

using namespace Utility;

Timer::Timer()
{
	m_limit_time = 60; // 1�b
	m_current_time = m_limit_time;
}

Timer::Timer(float seconds)
{
	m_limit_time = 60 * seconds;
	m_current_time = m_limit_time;
}

Timer::Timer(const Timer&) {}

Timer::~Timer() {}

void Timer::Update()
{
	if (m_current_time > 0)
	{
		m_current_time--;
	}
	else
	{
		m_current_time = 0;
	}
}

void Timer::Reset()
{
	m_current_time = m_limit_time;
}

bool Timer::IsTime()
{
	return m_current_time <= 0;
}

float Timer::Rate()
{
	return 1 * m_current_time / m_limit_time;
}