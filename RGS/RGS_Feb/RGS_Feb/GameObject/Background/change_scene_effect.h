//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.24
// 内容　：SceneChangeのEffect
//-------------------------------------------------------
#pragma once
#include <Device\game_device.h>

class SceneEffect 
{
public:
	SceneEffect();
	SceneEffect(const SceneEffect&);
	~SceneEffect();

	///<summary>ZoomRateを設定（最大5.0ｆにしている）</summary>
	///<param name="zoom_rate">最大5.0ｆにしている</param>
	void SetZoomRate(float zoom_rate);
	///<summary>ZoomInするか</summary>
	void Zoom(bool is_zoom);
	///<summary>更新処理</summary>
	void Update();

	///<summary>RenderTargetに描画</summary>
	void DrawOnEffect();
	///<summary>Effectを描画</summary>
	void DrawEffect();

	///<summary>Effect処理完了か</summary>
	bool IsEnd(bool zoom_in);

private:
	std::shared_ptr<Device::Renderer> m_renderer;	//Renderer

	bool m_is_zoom;									//Zoom inするか
	float m_rate;									//Zoom Rate
	Math::Vector2 m_pivot;
};