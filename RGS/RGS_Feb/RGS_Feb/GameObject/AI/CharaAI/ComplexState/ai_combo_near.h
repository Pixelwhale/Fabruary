//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.21
// 内容　：近いターゲットに技を出すAiState
//-------------------------------------------------------------
#pragma once
#include <GameObject\AI\CharaAI\ai_state.h>

namespace Character
{
	class CharacterBase;
}

namespace AI
{
	class ComboNear : public AiState
	{
	public:
		ComboNear(std::shared_ptr<Character::CharacterBase> my_character,
			std::shared_ptr<AiState> attack);
		ComboNear(const ComboNear&);
		~ComboNear();

		virtual void GetBattleInfo(MetaAI* meta_ai);
		virtual void Update(std::shared_ptr<Character::AiController> controller);
		virtual std::shared_ptr<AiState> NextState(int difficulty);

	private:
		std::shared_ptr<Character::CharacterBase> m_character;		//自機
		std::shared_ptr<Character::CharacterBase> m_target;			//Target

		std::shared_ptr<AiState> m_trace;							//追尾Ai
		std::shared_ptr<AiState> m_attack;							//攻撃Ai
	};
}
