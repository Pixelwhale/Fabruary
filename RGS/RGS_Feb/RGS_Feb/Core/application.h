//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.03～2017.12.04
// 内容　：Windowの基本処理
//-------------------------------------------------------
#pragma once
#include <Windows.h>
#include <Core\input_state.h>
#include <Device\game_device.h>
#include <memory>

namespace Core
{
	class Application
	{
	public:
		Application();
		virtual ~Application() {}
		/// <summary>Windowを生成する</summary>
		/// <param name="hInstance">Program実体のハンドル</param>  
		/// <returns>true:成功, false:失敗</returns>  
		bool InitWindow();

		/// <summary>アプリケーションを起動</summary>
		void Run();

	public:
		/// <summary>アプリケーションのシャットダウン処理</summary>
		void ShutDown();

	protected:
		/// <summary>初期化処理</summary>
		virtual void Initialize() = 0;
		/// <summary>リソース読み込む処理</summary>
		virtual void Load() = 0;
		/// <summary>リソース解放処理</summary>
		virtual void Unload() = 0;
		/// <summary>更新処理</summary>
		virtual void Update() = 0;
		/// <summary>描画処理</summary>
		virtual void Draw() = 0;
		/// <summary>終了しているか</summary>
		/// <returns>true:終わる, false:終わってない</returns>  
		virtual bool IsEnd() = 0;

	private:
		HINSTANCE m_hInstance;			//Program実体のハンドル
		HWND m_hwnd;					//Windowのハンドル

	protected:
		std::shared_ptr<InputState> m_input_state;					//Input State
		Device::GameDevice* m_game_device;			//Game Device
	};
}

/// <summary>Window状態のメッセージハンドル</summary>
static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_DESTROY:				//Windowが廃棄された場合
			PostQuitMessage(0);			//終了メッセージを知らせる
			return 0;
		case WM_CLOSE:					//WindowがCloseされた場合
			PostQuitMessage(0);			//終了メッセージを知らせる
			return 0;
		default:
			//その他のメッセージはDefaultMessageHandlerに渡す
			return DefWindowProc(hwnd, msg, wParam, lParam);;
	}
}