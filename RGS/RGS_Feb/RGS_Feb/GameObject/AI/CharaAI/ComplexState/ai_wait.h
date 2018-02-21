//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.21
// ���e�@�F�w��b����҂�AiState
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
		std::shared_ptr<Character::CharacterBase> m_character;		//���@

		Utility::Timer m_wait_timer;
	};
}
