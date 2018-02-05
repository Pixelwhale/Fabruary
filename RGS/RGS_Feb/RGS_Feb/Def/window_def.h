//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.03
// 内容　：Window情報の定義
//-------------------------------------------------------
#pragma once
#include <Windows.h>

namespace WindowDef
{
	//Windowサイズ
	static const int kScreenWidth = 1280;	//Windowの横サイズ
	static const int kScreenHeight = 720;	//Windowの縦サイズ

	//WindowMode
	static const bool kIsWindow = true;

	//Window名
	static const LPCSTR kWindowName = "ゲームタイトルまだ決めてない";
}