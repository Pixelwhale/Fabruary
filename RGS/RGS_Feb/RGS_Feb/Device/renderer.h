//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.10
// 内容　：Render機能を整理したクラス
//-------------------------------------------------------
#pragma once
#include <DX\DXLib\DxLib.h>
#include <Device\content_manager.h>
#include <Device\depth_sort.h>
#include <Math\vector2.h>
#include <Color\color.h>
#include <memory>

namespace Device 
{
	class Renderer 
	{
	public:
		Renderer(std::shared_ptr<ContentManager> contents);
		Renderer(const Renderer&);
		~Renderer();

#pragma region Main System関連

		///<summary>初期化処理</summary>
		void Initialize();
		///<summary>シャットダウン処理</summary>
		void Release();

		///<summary>画面クリア</summary>
		///<param name="r">Red(0～255)</param>
		///<param name="g">Green(0～255)</param>
		///<param name="b">Blue(0～255)</param>
		void Clear(int r, int g, int b);
		///<summary>BackBufferと交換</summary>
		void Swap();

		std::shared_ptr<DepthSort> GetDepthSort();

#pragma endregion


#pragma region 2D Render関連

		///<summary>Textureを描画</summary>
		///<param name="texture_name">Asset名</param>
		///<param name="index">何枚目</param>
		///<param name="position">描画位置</param>
		///<param name="alpha">透明度</param>
		void DrawMotion(std::string texture_name, int index, Math::Vector2 position, float alpha = 1.0f);

		///<summary>Textureを描画</summary>
		///<param name="texture_name">Asset名</param>
		///<param name="position">描画位置</param>
		void DrawTexture(std::string texture_name, Math::Vector2 position, float alpha = 1.0f);

		///<summary>Textureを描画</summary>
		///<param name="texture_name">Asset名</param>
		///<param name="position">描画位置</param>
		///<param name="scale">拡大縮小</param>
		void DrawTexture(
			std::string texture_name, Math::Vector2 position,
			Math::Vector2 scale, float alpha = 1.0);

		///<summary>Textureを描画</summary>
		///<param name="texture_name">Asset名</param>
		///<param name="position">描画位置</param>
		///<param name="pivot">回転、スケール中心</param>
		///<param name="scale">拡大縮小</param>
		///<param name="angle">回転（ラジアン）</param>
		///<param name="color">色</param>
		///<param name="horizen_flip">水平反転？</param>
		void DrawTexture(
			std::string texture_name, Math::Vector2 position,
			Math::Vector2 pivot, Math::Vector2 scale,
			float angle, Color color, bool horizen_flip = false);


		void DrawFade(Color color, float alpha = 1.0f);

#pragma endregion


#pragma region 3D Render関連

		///<summary>モデルを描画</summary>
		///<param name="model_name">Asset名</param>
		///<param name="position">描画位置</param>
		///<param name="size">大きさ</param>
		///<param name="rotation">回転</param>
		void DrawModel(std::string model_name, Math::Vector3 position, 
			Math::Vector3 size, Math::Vector3 rotation);

		///<summary>モデルのテクスチャを元に戻す</summary>
		///<param name="model_name">モデル名</param>
		void ResetModelTexture(std::string model_name);

		///<summary>モデルのテクスチャを変える</summary>
		///<param name="model_name">モデル名</param>
		///<param name="texture_name">テクスチャ名</param>
		void SetModelTexture(std::string model_name, std::string texture_name);

		///<summary>3D空間でTextureを描画</summary>
		///<param name="texture_name">Asset名</param>
		///<param name="index">何枚目</param>
		///<param name="position">描画位置</param>
		///<param name="alpha">透明度</param>
		void DrawMotion3D(std::string texture_name, int index, 
			Math::Vector3 position, float scales, float alpha = 1.0f);

		///<summary>3D空間でTextureを描画</summary>
		///<param name="texture_name">Asset名</param>
		///<param name="index">何枚目</param>
		///<param name="position">描画位置</param>
		///<param name="scale">大きさ（Widthの大きさで同倍率）</param>
		///<param name="angle">回転角度（ラジアン）</param>
		///<param name="color">色</param>
		void DrawMotion3D(std::string texture_name, int index,
			Math::Vector3 position, float scale, float angle, Color color);

		///<summary>3D空間でTextureを描画</summary>
		///<param name="texture_name">Asset名</param>
		///<param name="position">描画位置</param>
		///<param name="scale">拡大縮小(Xのsizeを基準で何pixel)</param>
		///<param name="alpha">透明度</param>
		void DrawTexture3D(std::string texture_name, Math::Vector3 position,
			float scale, float alpha = 1.0f);

		///<summary>3D空間でTextureを描画</summary>
		///<param name="texture_name">Asset名</param>
		///<param name="position">描画位置</param>
		///<param name="scale">拡大縮小(Xのsizeを基準で何pixel)</param>
		///<param name="angle">回転（ラジアン）</param>
		///<param name="color">色</param>
		///<param name="horizen_flip">水平反転？</param>
		void DrawTexture3D(
			std::string texture_name, Math::Vector3 position, 
			float scale, float angle, Color color, bool horizen_flip = false);

		void DrawTransparentObj();

#pragma endregion


#pragma region 文字関連

		///<summary>文字を描画</summary>
		///<param name="textureName">文字列</param>
		///<param name="position">描画位置</param>
		///<param name="color">色</param>
		///<param name="font_name">Font名</param>
		///<param name="center">中央置き</param>
		void DrawString(
			std::string text, std::string font_name, Math::Vector2 position, 
			Color color, bool center = false);

		///<summary>文字を描画</summary>
		///<param name="textureName">文字列</param>
		///<param name="position">描画位置</param>
		///<param name="color">色</param>
		///<param name="center">中央置き</param>
		void DrawString(
			std::string text, Math::Vector2 position, Color color,
			bool center = false);

		///<summary>文字を描画</summary>
		///<param name="textureName">文字列</param>
		///<param name="position">描画位置</param>
		///<param name="center">中央置き</param>
		void DrawString(
			std::string text, Math::Vector2 position, bool center = false);

#pragma endregion


#pragma region Filter関連

		///<summary>RenderTargetを設定</summary>
		void DrawOnGaussFilter();
		///<summary>ぼかし</summary>
		///<param name="ratio">ぼかしの度合い</param>
		void GaussFilter(int ratio);

		///<summary>BloomのRenderTargetを設定</summary>
		void DrawOnBloomFilter();
		///<summary>Bloomしたシーンを描画</summary>
		void DrawBloom();

#pragma endregion


	private:
		std::shared_ptr<ContentManager> m_contents;				//Content Manager
		std::shared_ptr<DepthSort>		m_depth_sort;			//描画順をソートするクラス

		int m_blur_filter_handle = -1;							//BlurのRenderTargetハンドル

		int m_scene_handle = -1;								//SceneのRenderTarget
		int m_hight_light_handle = -1;							//高輝度を取り出すRenderTarget
		int m_down_scale_handle = -1;							//DownScaleしてよりキレイにぼかす
		int m_gauss_handle = -1;								//ぼかす
	};
}