//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.12
// 内容　：透明のあるテクスチャはソートして描画する必要が
//			あるので、そのためのクラス
//-------------------------------------------------------
#pragma once
#include <vector>
#include <Color\color.h>
#include <Math\vector3.h>
#include <DX\DXLib\DxLib.h>

namespace Device
{
	struct TransparentObj
	{
		///<summary>半透明があるテクスチャを描画するObject</summary>
		///<param name="texture_name">アセット名</param>
		///<param name="index">MotionのIndex（Motionがない場合は-1）</param>
		///<param name="position">位置</param>
		///<param name="scale">大きさ(X軸のピクセル数)</param>
		///<param name="angle">回転角度（ラジアン）</param>
		///<param name="color">色</param>
		TransparentObj(std::string texture_name, int index,
			Math::Vector3 position,
			float scale, float angle, Color color)
			:texture_name(texture_name), index(index),
			position(position),
			scale(scale), angle(angle), color(color)
		{
			projection_dis = 0;
		}

		std::string		texture_name;		//アセット名
		int				index;				//MotionのIndex（Motionがない場合は-1）
		Math::Vector3	position;			//位置
		float			projection_dis;		//カメラとの位置
		float			scale;				//大きさ(X軸のピクセル数)
		float			angle;				//回転（ラジアン）
		Color			color;				//色
	};

	class DepthSort
	{
	public:
		DepthSort();
		DepthSort(const DepthSort&);
		~DepthSort();

		///<summary>半透明物件を追加</summary>
		///<param name="obj">半透明物件の設定</param>
		void AddTransparentObj(TransparentObj obj);
		///<summary>Listにあるものをクリア</summary>
		void Clear();

		///<summary>ソート（後ろから前に描画順を配置）</summary>
		///<param name="projector_pos">カメラの位置</param>
		void Sort(Math::Vector3 projector_pos);
		///<summary>描画リスト</summary>
		std::vector<TransparentObj>& DrawList();

	private:
		std::vector<TransparentObj>	m_draw_list;			//描画リスト

	};
}