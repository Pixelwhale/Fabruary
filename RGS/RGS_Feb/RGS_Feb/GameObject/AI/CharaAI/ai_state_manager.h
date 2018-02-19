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
		AiStateManager(int difficulty);
		AiStateManager(const AiStateManager&);
		~AiStateManager();

		void Update(std::shared_ptr<MetaAI> meta_ai);

		std::shared_ptr<Character::AiController> Controller();
		void SetCharaInfo(std::shared_ptr<Character::CharacterBase> character);

	private:
		int m_difficulty;											//����
		std::shared_ptr<Character::AiController> m_controller;		//�R���g���[���[

		std::shared_ptr<AiState> m_current_state;					//���̍s���p�^�[��
		std::shared_ptr<Character::CharacterBase> m_character;		//���삷��L����
	};
}