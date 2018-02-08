//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.11
// 内容　：Projector
//-------------------------------------------------------
#include <Device\projector.h>
#include <Def\window_def.h>

using namespace Device;

Projector::Projector()
{
	m_window_size = Math::Point(
		WindowDef::kScreenWidth,
		WindowDef::kScreenHeight);
}

Projector::Projector(const Projector&)
{
}

Projector::~Projector()
{
}

void Projector::Initialize()
{
	SetCameraNearFar(1.0f, 1000.0f);								//Near 1.0 Far 1000.0
	Zoom(100);														//Orthographic Zoom out 100

	m_rotation = 0;
	SetTarget(Math::Vector3(0.0f, 0.0f, 0.0f));						//目標：原点
	SetRelativePosition(Math::Vector3(0.0f, 50.0f, -100.0f));		//相対位置設定(左手系座標なのでZは-)
}

void Device::Projector::SpriteMode()
{
	m_stock_target = m_target;										//設定を記録
	m_stock_rerelative_position = m_relative_position;

	SetupCamera_Ortho(m_window_size.y);								//縮小
	//画面の左下を原点
	SetTarget(Math::Vector3(m_window_size.x / 2, m_window_size.y / 2, 0.0f));
	SetRelativePosition(Math::Vector3(0, 0, -1));
}

void Device::Projector::PopSetting()
{
	m_target = m_stock_target;										//設定を戻す
	m_relative_position = m_stock_rerelative_position;
	
	Rotate(m_rotation);												//回転位置へ戻す
	Zoom(m_zoom_rate);												//元の大きさに戻る
}

void Projector::SetRelativePosition(Math::Vector3 relative_position)
{
	m_relative_position.x = relative_position.x;
	m_relative_position.y = relative_position.y;
	m_relative_position.z = relative_position.z;
	VectorAdd(&m_position, &m_relative_position, &m_target);		//位置設定
	UpdateView();
}

void Projector::SetTarget(Math::Vector3 target) 
{
	m_target.x = target.x;
	m_target.y = target.y;
	m_target.z = target.z;
	VectorAdd(&m_position, &m_relative_position, &m_target);		//位置設定
	UpdateView();
}

void Projector::Rotate(float angle) 
{
	m_rotation = angle;												//回転角度を記録
	VectorRotationY(&m_position, &m_relative_position, angle);		//Localに対して回転
	VectorAdd(&m_position, &m_position, &m_target);					//ターゲットへ移動
	UpdateView();
}

void Projector::Zoom(float rate) 
{
	m_zoom_rate = rate;					//拡大縮小率を保存
	SetupCamera_Ortho(rate);			//拡大縮小
}

void Projector::UpdateView() 
{
	SetCameraPositionAndTarget_UpVecY(m_position, m_target);		//Viewを更新
}

Math::Vector3 Projector::Position() 
{
	return  Math::Vector3(m_position.x, m_position.y, m_position.z);
}
