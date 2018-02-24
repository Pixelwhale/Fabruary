//-------------------------------------------------------
// �쐬�ҁF�V�X�����g���T
// �쐬���F2018.02.15
// ���e�@�F�J�E���g�_�E���̃^�C�}�[
//-------------------------------------------------------

#pragma once
#include <memory>

namespace Utility
{
	class Timer
	{
	public:
		Timer();
		Timer(float seconds);
		Timer(const Timer&);
		~Timer();
		///<summary>�^�C�}�[���X�V</summary>
		void Update();
		///<summary>�^�C�}�[�����Z�b�g</summary>
		void Reset();
		///<summary>��ɂȂ������H</summary>
		bool IsTime();
		float GetCurrentTimes() const { return m_current_time; }
		float Rate();

	private:
		float m_limit_time = 0;	// ���b�ł����H
		float m_current_time = 0;	// ���Ԃ̍��̏��
	};
}