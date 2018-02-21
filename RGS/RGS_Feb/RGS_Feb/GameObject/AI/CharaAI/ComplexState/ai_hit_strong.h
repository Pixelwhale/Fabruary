//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.21
// 内容　：強いターゲットと戦うAiState
//-------------------------------------------------------------
#pragma once
#include <GameObject\AI\CharaAI\ai_state.h>

namespace Character
{
	class CharacterBase;
}

namespace AI
{
	class HitStrong : public AiState
	{
	public:
		HitStrong(std::shared_ptr<Character::CharacterBase> my_character, int difficulty);
		HitStrong(const HitStrong&);
		~HitStrong();

		virtual void GetBattleInfo(MetaAI* meta_ai);
		virtual void Update(std::shared_ptr<Character::AiController> controller);
		virtual std::shared_ptr<AiState> NextState(int difficulty);

	private:
		std::shared_ptr<Character::CharacterBase> m_character;		//自機
		std::shared_ptr<Character::CharacterBase> m_target;			//Target

		std::shared_ptr<AiState> m_trace;							//追尾Ai
		std::shared_ptr<AiState> m_attack;							//攻撃Ai
		bool m_can_attack;

		int m_difficulty;
	};
}
