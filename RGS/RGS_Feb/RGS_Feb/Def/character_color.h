//-------------------------------------------------------
// 作成者：金　淳元
// 作成日：2018.2.26
// 内容　：キャラクターのColor
//-------------------------------------------------------
#pragma once
#include <Color\color.h>
#include <Character\side.h>
#include <Math\vector2.h>

namespace CharacterColor
{
	static const Color kColor_NoTeam = Color(220, 121, 0);	//オレンジ
	static const Color kColor_Team1  = Color(220, 49, 16);	//赤
	static const Color kColor_Team2  = Color(49, 220, 220);	//青
	static const Color kColor_Team3  = Color(220, 220, 49);	//黄
	static const Color kColor_Team4  = Color(36, 220, 36);	//緑
	static const Color kColor_NoTeam_Icon = Color(255, 230, 215);
	static const Color kColor_Team1_Icon  = Color(219, 255, 219);
	static const Color kColor_Team2_Icon  = Color(180, 255, 255);
	static const Color kColor_Team3_Icon  = Color(255, 255, 180);
	static const Color kColor_Team4_Icon  = Color(255, 210, 210);

	static const Math::Vector2 kIcon_NoTeam = Math::Vector2(-300, 0);
	static const Math::Vector2 kIcon_Team1 = Math::Vector2(0, 0);
	static const Math::Vector2 kIcon_Team2 = Math::Vector2(300, 0);
	static const Math::Vector2 kIcon_Team3 = Math::Vector2(600, 0);
	static const Math::Vector2 kIcon_Team4 = Math::Vector2(900, 0);

	static const Color GetTeamColor(Side side)
	{
		switch (side)
		{
		case kTeam1:
			return kColor_Team1;
			break;
		case kTeam2:
			return kColor_Team2;
			break;
		case kTeam3:
			return kColor_Team3;
			break;
		case kTeam4:
			return kColor_Team4;
			break;
		case kNoTeam:
			return kColor_NoTeam;
			break;
		default:
			break;
		}
	}
	static const Color GetIconColor(Side side)
	{
		switch (side)
		{
		case kTeam1:
			return kColor_Team1_Icon;
			break;
		case kTeam2:
			return kColor_Team2_Icon;
			break;
		case kTeam3:
			return kColor_Team3_Icon;
			break;
		case kTeam4:
			return kColor_Team4_Icon;
			break;
		case kNoTeam:
			return kColor_NoTeam_Icon;
			break;
		default:
			break;
		}

	}

	static const Math::Vector2 GetUIPosition(Side side)
	{
		switch (side)
		{
		case kTeam1:
			return kIcon_Team1;
			break;
		case kTeam2:
			return kIcon_Team2;
			break;
		case kTeam3:
			return kIcon_Team3;
			break;
		case kTeam4:
			return kIcon_Team4;
			break;
		case kNoTeam:
			return kIcon_NoTeam;
			break;
		default:
			break;
		}
	}
	
}
