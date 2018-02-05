//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.04
// 内容　：WindowAPIを使ってApplicationの起動
//-------------------------------------------------------
#include <Windows.h>
#include <memory>
#include <Core\game.h>

//WindowsAPI
int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR lpCmdLine,
	int nCmdShow)
{
	std::shared_ptr<Core::Application> game;	//ゲームクラス

	game = std::make_shared<Core::Game>();		//実体を持たせる
	if (game == NULL)							//失敗する場合プログラムを終了
		return 0;

	if (!game->InitWindow())					//Windowを開く、失敗する場合プログラムを終了
		return 0;

	game->Run();								//ゲームアプリを起動

	return 0;									//Applicationを終了
}