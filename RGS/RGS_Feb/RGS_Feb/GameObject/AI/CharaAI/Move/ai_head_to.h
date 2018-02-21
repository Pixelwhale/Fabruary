//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.19
// 内容　：指定の場所を向くAiState
//-------------------------------------------------------------
#pragma once
#include <GameObject\AI\CharaAI\ai_state.h>

namespace Character
{
	class CharacterBase;
}

namespace AI
{
	class HeadDestination : public AiState
	{
	public:
		HeadDestination(
			std::shared_ptr<Character::CharacterBase> my_chara,
			Math::Vector3 destination);
		HeadDestination(const HeadDestination&);
		~HeadDestination();

		virtual void GetBattleInfo(MetaAI* meta_ai);
		virtual void Update(std::shared_ptr<Character::AiController> controller);
		virtual std::shared_ptr<AiState> NextState(int difficulty);
	private:
		bool InRange(float distance);

	private:
		std::shared_ptr<Character::CharacterBase> m_character;		//自機
		Math::Vector3 m_destination;								//目標地
	};
}