//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.21
// ���e�@�F�����^�[�Q�b�g�Ɛ키AiState
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
		std::shared_ptr<Character::CharacterBase> m_character;		//���@
		std::shared_ptr<Character::CharacterBase> m_target;			//Target

		std::shared_ptr<AiState> m_trace;							//�ǔ�Ai
		std::shared_ptr<AiState> m_attack;							//�U��Ai
		bool m_can_attack;

		int m_difficulty;
	};
}
