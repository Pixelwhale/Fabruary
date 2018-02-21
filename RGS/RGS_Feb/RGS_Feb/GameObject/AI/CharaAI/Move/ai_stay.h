//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.21
// ���e�@�F���̂܂ܗ���AiState
//-------------------------------------------------------------
#pragma once
#include <GameObject\AI\CharaAI\ai_state.h>

namespace Character
{
	class CharacterBase;
}

namespace AI
{
	class Stay : public AiState
	{
	public:
		Stay();
		Stay(const Stay&);
		~Stay();

		virtual void GetBattleInfo(std::shared_ptr<MetaAI> meta_ai);
		virtual void Update(std::shared_ptr<Character::AiController> controller);
		virtual std::shared_ptr<AiState> NextState(int difficulty);

	private:
	};
}
