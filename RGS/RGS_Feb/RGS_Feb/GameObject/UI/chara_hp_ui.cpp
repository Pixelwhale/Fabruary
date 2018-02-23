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

void HpUI::SetColor(Color icon_color, Color team_color)
{
	m_icon_color = icon_color;
	m_team_color = team_color;
}

void HpUI::SetPosition(Math::Vector2 position) 
{
	m_position = position;
}

void HpUI::Draw(float hp, float mp, int chara_face)
{
	if (hp > 1)
		hp = 1;
	if (hp < 0)
		hp = 0;
	if (mp > 1)
		mp = 1;
	if (mp < 0)
		mp = 0;

	m_renderer->DrawTexture("hp_ui_back", m_position);

	//offset(94, 34) length(194) height(38)
	float hp_start = (1 - hp) * 194;
	m_renderer->DrawTexture("hp_ui_hp", m_position + Math::Vector2(94, 34),
		Math::Vector2(hp_start, 0), Math::Vector2(194 - hp_start, 38));
	//offset(100, 72) length(166) height(20)
	float mp_start = (1 - mp) * 166;
	m_renderer->DrawTexture("hp_ui_mp", m_position + Math::Vector2(100, 72),
		Math::Vector2(mp_start, 0), Math::Vector2(166 - mp_start, 20));

	m_renderer->DrawTexture("hp_ui_front", m_position,
		Math::Vector2(), Math::Vector2(1, 1), 0, m_team_color);

	m_renderer->DrawMotion("chara_face", chara_face, m_position + Math::Vector2(32, 32),
		m_icon_color);
}
