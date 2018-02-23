//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.23
// 内容　：CharacterのHP情報
//-------------------------------------------------------------
#pragma once
#include <Device\renderer.h>

namespace UI 
{
	class HpUI 
	{
	public:
		HpUI();
		HpUI(const HpUI&);
		~HpUI();

		///<summary>色設定</summary>
		///<param name="icon_color">キャラのアイコン色</param>
		///<param name="icon_color">チーム色</param>
		void SetColor(Color icon_color, Color team_color);
		///<summary>位置設定</summary>
		void SetPosition(Math::Vector2 position);
		///<summary>描画</summary>
		///<param name="hp">HPのRate</param>
		///<param name="mp">MPのRate</param>
		///<param name="chara_face">キャラのアイコン</param>
		void Draw(float hp, float mp, int chara_face);

	private:
		std::shared_ptr<Device::Renderer> m_renderer;	//Renderer
		Color m_icon_color = Color(1.0f, 1.0f, 1.0f);	//Icon Color
		Color m_team_color = Color(1.0f, 1.0f, 1.0f);	//team Color

		Math::Vector2 m_position;						//描画位置
	};
}