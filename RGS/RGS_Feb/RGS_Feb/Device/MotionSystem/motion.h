//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.8
// ���e�@�FSpriteStudio�̋@�\���ȒP�ɂ܂Ƃ߂����[�V�����N���X
//-------------------------------------------------------------
#pragma once
#include <ssbpLib\SS5Player.h>
#include <Device\projector.h>
#include <Color\color.h>
#include <Math\vector3.h>
#include <Math\vector2.h>

namespace MotionSystem
{
	class Motion 
	{
	public:
		Motion(string asset_name);
		Motion(const Motion&);
		~Motion();

		void Initialize();
		void Release();
		void Play(string motion_name);

		void Update();
		void Draw();

		void SetPosition(Math::Vector3 position);
		void SetColor(Color color);
		void SetScale(Math::Vector2 scale);

	private:
		ss::Player* m_motion_player;
		std::shared_ptr<Device::Projector> m_projector;

		Math::Vector3 m_position;
	};
}