//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.22
// ���e�@�FStage�w�i
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

	///<summary>�X�V����</summary>
	void Update();
	///<summary>�w�i��`��</summary>
	void DrawBack();
	///<summary>�O�i��`��</summary>
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

	float m_light_alpha;						//Light�̖��x
	float m_pc_light = 0.5f;					//PcLight�̖��x
	bool m_pc_alpha_switch = true;				//�_�ł�Flag
};