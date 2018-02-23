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

void Title::Initialize(SceneType previous)
{
	SceneBase::Initialize(previous);

	m_background = make_shared<Background>();
}

void Title::Update()
{
	if (m_input->IsKeyTrigger(KEY_INPUT_SPACE))
	{
		m_is_end = true;
		m_next = kGamePlay;
	}

	m_background->Update();					//�w�i�X�V
}

void Title::Draw()
{
	m_renderer->DrawOnBloomFilter();		//DrawFilter
	m_background->DrawBack();				//�w�i

	m_renderer->DrawString("Title", Math::Vector2(150, 0));

	m_background->DrawFront();				//�O�i
	m_renderer->DrawBloom();				//BloomEffect
}

void Title::Shutdown()
{
	m_background = NULL;
}