//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.23
// 内容　：CharacterのHP情報
//-------------------------------------------------------------
#include <GameObject\UI\chara_hp_ui.h>
#include <Device\game_device.h>

using namespace UI;

HpUI::HpUI() 
{
	m_renderer = Device::GameDevice::GetInstance()->GetRenderer();
}

HpUI::HpUI(const HpUI&) 
{
}

HpUI::~HpUI() 
{
}

void HpUI::SetColor(Color color) 
{
	m_color = color;
}

void HpUI::SetPosition(Math::Vector2 position) 
{
	m_position = position;
}

void HpUI::Draw(float hp, float mp, int chara_face)
{
	m_renderer->DrawTexture("hp_ui_back", m_position);

	//draw hp
	//draw mp

	m_renderer->DrawTexture("hp_ui_front", m_position,
		Math::Vector2(), Math::Vector2(1, 1), 0, m_color);

	m_renderer->DrawMotion("chara_face", chara_face, m_position + Math::Vector2(32, 32),
		m_color);
}
