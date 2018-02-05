//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.03～2017.12.04
// 内容　：Windowの基本処理
//-------------------------------------------------------
#include <Core\application.h>
#include <Def\window_def.h>
#include <DX\DXLib\DxLib.h>

using namespace Core;

Application::Application() 
{
	m_input_state = 0;
	m_game_device = 0;
}

bool Application::InitWindow()
{
	bool result;

#pragma region DxLib初期化
	SetUseDirect3DVersion(DX_DIRECT3D_9EX);
	SetOutApplicationLogValidFlag(false);			//Logを書き出ししない
	SetWindowText(WindowDef::kWindowName);			//Title設定
	SetGraphMode(
		WindowDef::kScreenWidth,						//WindowSize
		WindowDef::kScreenHeight,
		32, 60);									//Color 32bit  60Frame
	ChangeWindowMode(WindowDef::kIsWindow);			//全画面設定
	DxLib_Init();									//DXLibrary初期化
	SetMouseDispFlag(false);						//Mouse表示しない

	m_hwnd = DxLib::GetMainWindowHandle();			//WindowHandleを取得
	m_hInstance = DxLib::GetTaskInstance();			//Programの実体を取得

#pragma endregion

#pragma region GameDevice初期化

	m_game_device = Device::GameDevice::GetInstance();
	result = m_game_device->Initialize(m_hInstance, m_hwnd);
	if (!result)
		return false;

#pragma endregion

	m_input_state = m_game_device->GetInput();

	return true;
}

void Application::Run()
{
	MSG msg;								//Windowの状態メッセージ
	ZeroMemory(&msg, sizeof(MSG));			//msg初期化

	Initialize();							//Gameの初期化
	Load();									//ロードコンテンツ

	while (ProcessMessage()== 0 && !IsEnd())						//終了しない限りGameLoop
	{
		if (!m_input_state->Update())		//InputState更新
			break;

		Update();							//Gameのアップデート
		Draw();								//Gameの描画処理
	}

	Unload();								//コンテンツ解放処理
	ShutDown();								//Windowのシャットダウン処理
}

void Application::ShutDown()
{
	SetMouseDispFlag(true);								//Mouse表示

	if (m_game_device)									//Game Deviceをシャットダウン処理
	{
		m_game_device->ShutDown();
	}

	delete m_game_device;

	DxLib_End();										//DXLib終了処理
}

