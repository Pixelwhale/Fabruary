//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.19
// 内容　：テクスチャ、音などをロードするシーン
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
	m_content->LoadSSFile("Character_base/Character.ssbp");

	m_content->LoadTexture("background", ".png");
	m_content->LoadTexture("background_light", ".png");
	m_content->LoadTexture("background_front", ".png");
	m_content->LoadTexture("background_pc_light_back", ".png");
	m_content->LoadTexture("background_pc_light_front", ".png");
	m_content->LoadTexture("pc_monitor", ".png");

	m_content->LoadTexture("pause", ".png");
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