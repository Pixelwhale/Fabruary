//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.19
// ���e�@�FNormalPunch��AiState
//-------------------------------------------------------------
#pragma once
#include <GameObject\AI\CharaAI\ai_state.h>
#include <Device\game_device.h>
#include <Utility\timer.h>

namespace Character
{
	class CharacterBase;
}

namespace AI
{
	class NormalPunch : public AiState
	{
	public:
		NormalPunch(
			std::shared_ptr<Character::CharacterBase> my_chara,
			std::shared_ptr<Character::CharacterBase> target, int count);
		NormalPunch(const NormalPunch&);
		~NormalPunch();

		virtual void GetBattleInfo(MetaAI* meta_ai);
		virtual void Update(std::shared_ptr<Character::AiController> controller);
		virtual std::shared_ptr<AiState> NextState(int difficulty);

	private:
		///<summary>�x�����Ԃ����Z�b�g</summary>
		void ResetTimer();
		///<summary>�U���͈͓���</summary>
		bool IsInAttckRange();

	private:
		Device::Random* m_random;		//�����_��
		Utility::Timer m_timer;			//�x������

		std::shared_ptr<Character::CharacterBase> m_character;		//���@
		std::shared_ptr<Character::CharacterBase> m_target;			//�^�[�Q�b�g
		int m_punch_count;											//�p���`��
	};
}