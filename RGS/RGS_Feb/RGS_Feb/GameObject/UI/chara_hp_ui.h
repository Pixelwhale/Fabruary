//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.23
// ���e�@�FCharacter��HP���
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

		///<summary>�F�ݒ�</summary>
		///<param name="icon_color">�L�����̃A�C�R���F</param>
		///<param name="icon_color">�`�[���F</param>
		void SetColor(Color icon_color, Color team_color);
		///<summary>�ʒu�ݒ�</summary>
		void SetPosition(Math::Vector2 position);
		///<summary>�`��</summary>
		///<param name="hp">HP��Rate</param>
		///<param name="mp">MP��Rate</param>
		///<param name="chara_face">�L�����̃A�C�R��</param>
		void Draw(float hp, float mp, int chara_face);

	private:
		std::shared_ptr<Device::Renderer> m_renderer;	//Renderer
		Color m_icon_color = Color(1.0f, 1.0f, 1.0f);	//Icon Color
		Color m_team_color = Color(1.0f, 1.0f, 1.0f);	//team Color

		Math::Vector2 m_position;						//�`��ʒu
	};
}