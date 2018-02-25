//-------------------------------------------------------------
// ì¬ÒF—Ñ‰À‰b
// ì¬“úF2018.2.22
// “à—e@FStage”wŒi
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

	///<summary>XVˆ—</summary>
	void Update();
	///<summary>”wŒi‚ğ•`‰æ</summary>
	void DrawBack();
	///<summary>‘OŒi‚ğ•`‰æ</summary>
	void DrawFront();

private:
	void InitializeMotion();

private:
	Device::Random* m_random;					//Random
	shared_ptr<Device::Renderer> m_renderer;	//Renderer
	shared_ptr<MotionSystem::Motion> m_programmer;		//programmer motion
	shared_ptr<MotionSystem::Motion> m_damage;			//damage motion
	shared_ptr<MotionSystem::Motion> m_damage_center;	//damage motion
	shared_ptr<MotionSystem::Motion> m_damage_left;		//damage motion
	shared_ptr<MotionSystem::Motion> m_walk;			//walk motion
	shared_ptr<MotionSystem::Motion> m_designer;		//designer motion

	float m_light_alpha;						//Light‚Ì–¾“x
	float m_pc_light = 0.5f;					//PcLight‚Ì–¾“x
	bool m_pc_alpha_switch = true;				//“_–Å‚ÌFlag
};