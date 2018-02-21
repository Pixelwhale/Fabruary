//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.19
// 内容　：KickCombo（大）のAiState
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
		///<summary>遅延時間をリセット</summary>
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
		Combo m_current_combo;			//現在の段階
		Device::Random* m_random;		//ランダム
		Utility::Timer m_timer;			//遅延時間
	};
}