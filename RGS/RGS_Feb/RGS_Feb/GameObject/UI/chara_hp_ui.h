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

		void SetColor(Color color);
		void SetPosition(Math::Vector2 position);

		void Draw(float hp, float mp, int chara_face);

	private:
		std::shared_ptr<Device::Renderer> m_renderer;	//Renderer
		Color m_color = Color(1.0f, 1.0f, 1.0f);		//Blending Color
		Math::Vector2 m_position;						//�`��ʒu
	};
}