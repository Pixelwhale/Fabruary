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
	m_next = kLogo;
	m_is_end = false;
}

void Loading::LoadContents()
{
	m_content->LoadTexture("title", ".png");
	m_content->LoadTexture("NEEC1280black", ".png");

	m_content->LoadTexture("tutorial", ".png");
	m_content->LoadTexture("credit", ".png");

	m_content->LoadTexture("background", ".png");
	m_content->LoadTexture("background_light", ".png");
	m_content->LoadTexture("background_front", ".png");
	m_content->LoadTexture("background_pc_light_back", ".png");
	m_content->LoadTexture("background_pc_light_front", ".png");
	m_content->LoadTexture("pc_monitor", ".png");
	m_content->LoadTexture("monitor", ".png");

	m_content->LoadTexture("pause", ".png");

	m_content->LoadTexture("chara_face", ".png", 4, 4, 1, 64, 64);
	m_content->LoadTexture("hp_ui_back", ".png");
	m_content->LoadTexture("hp_ui_front", ".png");
	m_content->LoadTexture("hp_ui_hp", ".png");
	m_content->LoadTexture("hp_ui_mp", ".png");

	m_content->LoadTexture("panel_number", ".png", 10, 10, 1, 64, 64);

	m_content->LoadTexture("select_chara_ui", ".png");
	m_content->LoadTexture("select_chara_business", ".png");
	m_content->LoadTexture("select_chara_designer", ".png");
	m_content->LoadTexture("select_chara_planner", ".png");
	m_content->LoadTexture("select_chara_programmer", ".png");
	m_content->LoadTexture("select_chara_button", ".png");
	m_content->LoadTexture("select_chara_join_button", ".png");
	m_content->LoadTexture("select_chara_ready", ".png");
	m_content->LoadTexture("fight", ".png");

	m_content->LoadTexture("menu_start_game", ".png");
	m_content->LoadTexture("menu_tutorial", ".png");
	m_content->LoadTexture("menu_credit", ".png");
	m_content->LoadTexture("menu_quit", ".png");

	m_content->LoadSE("ゴング_onjin", ".mp3");
	m_content->LoadSE("se_countdown", ".mp3");
	m_content->LoadSE("se_hit", ".mp3");
	m_content->LoadSE("se_over", ".mp3");
	m_content->LoadSE("se_down", ".mp3");
	m_content->LoadSE("se_ukemi", ".mp3");
	m_content->LoadSE("se_punch", ".mp3");
	m_content->LoadSE("se_kick", ".mp3");
	m_content->LoadSE("se_screen_in", ".mp3");
	m_content->LoadSE("se_screen_out", ".mp3");
	m_content->LoadSE("se_select", ".mp3");
	m_content->LoadSE("se_cancel", ".mp3");
	m_content->LoadSE("se_skill_bn", ".mp3");
	m_content->LoadSE("se_skill_cg", ".mp3");
	m_content->LoadSE("se_skill_pg", ".mp3");
	m_content->LoadSE("se_skill_kamekame", ".mp3");

	m_content->LoadBGM("stlp6", ".mp3");
	m_content->LoadBGM("tw052", ".mp3");
	m_content->LoadBGM("tw071", ".mp3");
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