//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.21
// ���e�@�F�h��AiState
//-------------------------------------------------------------
#pragma once
#include <GameObject\AI\CharaAI\ai_state.h>

namespace AI
{
	class Defence : public AiState
	{
	public:
		Defence();
		Defence(const Defence&);
		~Defence();

		virtual void GetBattleInfo(MetaAI* meta_ai);
		virtual void Update(std::shared_ptr<Character::AiController> controller);
		virtual std::shared_ptr<AiState> NextState(int difficulty);

	private:
	};
}
