#pragma once
#include <Device\game_device.h>

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
	Device::Random* m_random;					//Random
	shared_ptr<Device::Renderer> m_renderer;	//Renderer

	float m_light_alpha;						//Light�̖��x
	float m_pc_light = 0.5f;					//PcLight�̖��x
	bool m_pc_alpha_switch = true;				//�_�ł�Flag
};