//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.19
// ���e�@�F�e�N�X�`���A���Ȃǂ����[�h����V�[��
//-------------------------------------------------------
#include <Scene\loading.h>

using namespace Scene;

Loading::Loading()
{
	m_content = Device::GameDevice::GetInstance()->GetContent();
	m_next = kTitle;
	m_is_end = false;
}

void Loading::LoadContents()
{
}

void Loading::UnloadContents()
{
}

void Loading::Update()
{
	if (!m_is_end) LoadContents();
	m_is_end = true;
}

void Loading::Draw()
{
	m_renderer->DrawString("Loading", Math::Vector2(150, 0));
}

void Loading::Shutdown()
{
	UnloadContents();
}