//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.24
// 内容　：Start位置を定義する
//-------------------------------------------------------
#pragma once
#include <Math\vector3.h>

namespace StartPosition
{
	static const Math::Vector3 kPlayer1 = Math::Vector3(-800, 128, -200);
	static const Math::Vector3 kPlayer2 = Math::Vector3(-1000, 128, -320);
	static const Math::Vector3 kPlayer3 = Math::Vector3(800, 128, -200);
	static const Math::Vector3 kPlayer4 = Math::Vector3(1000, 128, -320);
	static const Math::Vector3 kLeft = Math::Vector3(-1000, 128, -250);
	static const Math::Vector3 kRight = Math::Vector3(1000, 128, -250);

	static const Math::Vector3 GetStartPos(int num) 
	{
		switch (num)
		{
		case 1:
			return kPlayer1;
			break;
		case 2:
			return kPlayer2;
			break;
		case 3:
			return kPlayer3;
			break;
		case 4:
			return kPlayer4;
			break;
		case 5:
			return kLeft;
			break;
		case 6:
			return kRight;
			break;
		default:
			return kPlayer1;
			break;
		}
	}
}