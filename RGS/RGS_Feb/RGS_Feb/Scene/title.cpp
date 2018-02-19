//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.22
// ���e�@�F�^�C�g���̃V�[���B�X�^�[�g�A���[�h�A�I�v�V�����B
//-------------------------------------------------------
#include <Scene\title.h>

using namespace Scene;

Title::Title()
{
	m_next = kGamePlay;
}

void Title::Update()
{
	if (m_input->IsKeyTrigger(KEY_INPUT_SPACE))
	{
		m_is_end = true;
		m_next = kGamePlay;
	}
}

void Title::Draw()
{
	m_renderer->DrawString("Title", Math::Vector2(150, 0));
}

void Title::Shutdown()
{
}