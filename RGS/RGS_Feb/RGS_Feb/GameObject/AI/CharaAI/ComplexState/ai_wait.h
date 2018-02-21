//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.21
// 内容　：指定秒数を待つAiState
//-------------------------------------------------------------
#pragma once
#include <GameObject\AI\CharaAI\ai_state.h>
#include <Utility\timer.h>

namespace Character
{
	class CharacterBase;
}

namespace AI
{
	class Wait : public AiState
	{
	public:
		Wait(std::shared_ptr<Character::CharacterBase> my_character, float second);
		Wait(const Wait&);
		~Wait();

		virtual void GetBattleInfo(MetaAI* meta_ai);
		virtual void Update(std::shared_ptr<Character::AiController> controller);
		virtual std::shared_ptr<AiState> NextState(int difficulty);

	private:
		std::shared_ptr<Character::CharacterBase> m_character;		//自機

		Utility::Timer m_wait_timer;
	};
}
