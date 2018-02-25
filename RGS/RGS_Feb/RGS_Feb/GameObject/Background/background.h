//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.22
// 内容　：Stage背景
//-------------------------------------------------------------
#pragma once
#include <Device\game_device.h>
#include <Device\MotionSystem\motion.h>

class Background
{
public:
	Background();
	Background(const Background&);
	~Background();

	///<summary>更新処理</summary>
	void Update();
	///<summary>背景を描画</summary>
	void DrawBack();
	///<summary>前景を描画</summary>
	void DrawFront();

private:
	Device::Random* m_random;					//Random
	shared_ptr<Device::Renderer> m_renderer;	//Renderer
	shared_ptr<MotionSystem::Motion> m_motion;	//motion;

	float m_light_alpha;						//Lightの明度
	float m_pc_light = 0.5f;					//PcLightの明度
	bool m_pc_alpha_switch = true;				//点滅のFlag
};