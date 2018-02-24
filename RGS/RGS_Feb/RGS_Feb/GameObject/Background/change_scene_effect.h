//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.24
// ���e�@�FSceneChange��Effect
//-------------------------------------------------------
#pragma once
#include <Device\game_device.h>

class SceneEffect 
{
public:
	SceneEffect();
	SceneEffect(const SceneEffect&);
	~SceneEffect();

	///<summary>ZoomRate��ݒ�i�ő�5.0���ɂ��Ă���j</summary>
	///<param name="zoom_rate">�ő�5.0���ɂ��Ă���</param>
	void SetZoomRate(float zoom_rate);
	///<summary>ZoomIn���邩</summary>
	void Zoom(bool is_zoom);
	///<summary>�X�V����</summary>
	void Update();

	///<summary>RenderTarget�ɕ`��</summary>
	void DrawOnEffect();
	///<summary>Effect��`��</summary>
	void DrawEffect();

	///<summary>Effect����������</summary>
	bool IsEnd(bool zoom_in);

private:
	std::shared_ptr<Device::Renderer> m_renderer;	//Renderer

	bool m_is_zoom;									//Zoom in���邩
	float m_rate;									//Zoom Rate
	Math::Vector2 m_pivot;
};