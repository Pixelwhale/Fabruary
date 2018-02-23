//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.19
// ���e�@�FAiState���Ǘ�����}�l�[�W���[
//-------------------------------------------------------------
#pragma once
#include <Character\Controller\ai_controller.h>
#include <GameObject\AI\CharaAI\ai_state.h>

namespace Character 
{
	class CharacterBase;
}

namespace AI 
{
	class AiStateManager 
	{
	public:
		AiStateManager(int difficulty, int player_num);
		AiStateManager(const AiStateManager&);
		~AiStateManager();

		///<summary>Ai�̑���X�V</summary>
		void Update(MetaAI* meta_ai);

		///<summary>�L�����������鎞�ɕK�v�ȃR���g���[���[</summary>
		std::shared_ptr<Character::AiController> Controller();
		///<summary>���@��Ԃ��擾�ł���悤�ɐݒ�</summary>
		void SetCharaInfo(std::shared_ptr<Character::CharacterBase> character);


		///<summary>���삵���L�����͎���ł��邩</summary>
		bool IsDead();

	private:
		void CheckDefence(MetaAI* meta_ai);

	private:
		int m_difficulty;											//����
		bool m_is_defence = false;
		std::shared_ptr<Character::AiController> m_controller;		//�R���g���[���[

		std::shared_ptr<AiState> m_current_state;					//���̍s���p�^�[��
		std::shared_ptr<Character::CharacterBase> m_character;		//���삷��L����
	};
}