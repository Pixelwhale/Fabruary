//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.11
// 内容　：Projector
//-------------------------------------------------------
#pragma once
#include <DX\DXLib\DxLib.h>
#include <Math\vector3.h>

namespace Device 
{
	class Projector 
	{
	public:
		Projector();
		Projector(const Projector&);
		~Projector();
		///<summary>初期化処理</summary>
		void Initialize();

		///<summary>2D Spriteを描画するために座標変換する</summary>
		void SpriteMode();
		///<summary>座標変換後に元の設定を戻す</summary>
		void PopSetting();

		///<summary>目標との相対位置を設定</summary>
		///<param name="relative_position">Projectorと目標の相対位置関係</param>
		void SetRelativePosition(Math::Vector3 relative_position);
		///<summary>注目点を設定</summary>
		///<param name="target">注目目標</param>
		void SetTarget(Math::Vector3 target);

		///<summary>回転</summary>
		///<param name="angle">回転角度（ラジアン）</param>
		void Rotate(float angle);
		///<summary>拡大、縮小</summary>
		///<param name="rate">大きい程ZoomOut、小さい程ZoomIn（0以下は上下逆転）</param>
		void Zoom(float rate);

		///<summary>カメラの位置</summary>
		Math::Vector3 Position();

	private:
		///<summary>Viewを更新（移動などがある場合）</summary>
		void UpdateView();

	private:
		VECTOR m_position;				//Projectorの位置
		VECTOR m_target;				//注目点
		VECTOR m_relative_position;		//Projectorと目標の相対位置

		float  m_rotation;						//回転角度を保存用変数
		float  m_zoom_rate;						//拡大縮小を保存用変数
		VECTOR m_stock_target;					//一旦保存の注目点
		VECTOR m_stock_rerelative_position;		//一旦保存のProjectorと目標の相対位置
	};
}