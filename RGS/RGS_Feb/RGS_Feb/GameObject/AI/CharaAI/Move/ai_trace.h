//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.21
// 内容　：特定のキャラを追尾するAiState
//-------------------------------------------------------------
#pragma once
#include <GameObject\AI\CharaAI\ai_state.h>

namespace Character
{
	class CharacterBase;
}

namespace AI
{
	class Trace : public AiState
	{
	public:
		Trace(
			std::shared_ptr<Character::CharacterBase> my_chara,
			std::shared_ptr<Character::CharacterBase> target);
		Trace(const Trace&);
		~Trace();

		virtual void GetBattleInfo(std::shared_ptr<MetaAI> meta_ai);
		virtual void Update(std::shared_ptr<Character::AiController> controller);
		virtual std::shared_ptr<AiState> NextState(int difficulty);
	private:
		bool InRange(float distance);

	private:
		std::shared_ptr<Character::CharacterBase> m_character;		//自機
		std::shared_ptr<Character::CharacterBase> m_target;			//ターゲット
	};
}
