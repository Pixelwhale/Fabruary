//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.19
// ���e�@�FKickCombo�i��j��AiState
//-------------------------------------------------------------
#pragma once
#include <GameObject\AI\CharaAI\ai_state.h>
#include <Device\game_device.h>
#include <Utility\timer.h>

namespace AI
{
	class PunchComboStrong : public AiState
	{
	public:
		PunchComboStrong();
		PunchComboStrong(const PunchComboStrong&);
		~PunchComboStrong();

		virtual void GetBattleInfo(MetaAI* meta_ai);
		virtual void Update(std::shared_ptr<Character::AiController> controller);
		virtual std::shared_ptr<AiState> NextState(int difficulty);

	private:
		///<summary>�x�����Ԃ����Z�b�g</summary>
		void ResetTimer();

	private:
		enum class Combo
		{
			kDefence = 0,
			kRun,
			kPunch,
			kEnd,
		};

	private:
		Combo m_current_combo;			//���݂̒i�K
		Device::Random* m_random;		//�����_��
		Utility::Timer m_timer;			//�x������
	};
}