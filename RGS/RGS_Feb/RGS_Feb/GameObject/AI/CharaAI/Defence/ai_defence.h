//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.21
// 内容　：防御AiState
//-------------------------------------------------------------
#pragma once
#include <GameObject\AI\CharaAI\ai_state.h>
#include <Utility\timer.h>

namespace AI
{
	class Defence : public AiState
	{
	public:
		Defence(std::shared_ptr<AiState> last_state, int difficulty);
		Defence(const Defence&);
		~Defence();

		virtual void GetBattleInfo(MetaAI* meta_ai);
		virtual void Update(std::shared_ptr<Character::AiController> controller);
		virtual std::shared_ptr<AiState> NextState(int difficulty);

	private:
		std::shared_ptr<AiState> m_last_state;		//前の状態
		Utility::Timer m_timer;						//反応時間
	};
}
