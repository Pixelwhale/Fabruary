#pragma once
#include <Device\game_device.h>

class Background
{
public:
	Background();
	Background(const Background&);
	~Background();

	///<summary>XVˆ—</summary>
	void Update();
	///<summary>”wŒi‚ğ•`‰æ</summary>
	void DrawBack();
	///<summary>‘OŒi‚ğ•`‰æ</summary>
	void DrawFront();

private:
	Device::Random* m_random;					//Random
	shared_ptr<Device::Renderer> m_renderer;	//Renderer

	float m_light_alpha;						//Light‚Ì–¾“x
	float m_pc_light = 0.5f;					//PcLight‚Ì–¾“x
	bool m_pc_alpha_switch = true;				//“_–Å‚ÌFlag
};