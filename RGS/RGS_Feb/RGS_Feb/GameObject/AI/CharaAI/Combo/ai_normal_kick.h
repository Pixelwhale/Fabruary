//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.19
// ���e�@�FNormalKick��AiState
//-------------------------------------------------------------
#pragma once
#include <GameObject\AI\CharaAI\ai_state.h>

namespace Character
{
	class CharacterBase;
}

namespace AI
{
	class NormalKick : public AiState
	{
	public:
		NormalKick(
			std::shared_ptr<Character::CharacterBase> my_chara,
			std::shared_ptr<Character::CharacterBase> target);
		NormalKick(const NormalKick&);
		~NormalKick();

		virtual void GetBattleInfo(std::shared_ptr<MetaAI> meta_ai);
		virtual void Update(std::shared_ptr<Character::AiController> controller);
		virtual std::shared_ptr<AiState> NextState(int difficulty);

	private:
		///<summary>�U���͈͓���</summary>
		bool IsInAttckRange();

	private:
		std::shared_ptr<Character::CharacterBase> m_character;		//���@
		std::shared_ptr<Character::CharacterBase> m_target;			//�^�[�Q�b�g
	};
}