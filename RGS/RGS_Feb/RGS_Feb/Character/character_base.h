//-------------------------------------------------------
// 作成者：金　淳元
// 作成日：2018.02.05
// 内容　：キャラクターのベースクラス
//-------------------------------------------------------
#pragma once
#include <Device\game_device.h>;
#include <Math\vector3.h>;


namespace Character
{
	class CharacterBase
	{
	public:
		CharacterBase();
		~CharacterBase();
		void Initialize();
		void Update();
		void MoveUpdate();
		void GageUpdate();
	private:
		int m_hp;
		int m_gage;
		Math::Vector3 m_position;
		Math::Vector3 m_velocity;
		std::shared_ptr<Core::InputState> m_input;
	};


}