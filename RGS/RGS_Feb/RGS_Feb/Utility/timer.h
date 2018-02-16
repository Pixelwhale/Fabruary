//-------------------------------------------------------
// �쐬�ҁF�V�X�����g���T
// �쐬���F2017.02.15
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

	private:
		int m_limit_time;	// ���b�ł����H
		int m_current_time;	// ���Ԃ̍��̏��
	};
}