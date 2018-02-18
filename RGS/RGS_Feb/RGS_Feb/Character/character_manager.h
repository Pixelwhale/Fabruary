//-------------------------------------------------------
// �쐬�ҁF���@�~��
// �쐬���F2018.02.17
// ���e�@�F�L�����N�^�[�}�l�[�W���[
//-------------------------------------------------------
#pragma once
#include <Device\game_device.h>
#include<Character\character_base.h>

namespace Character
{
	class CharacterManager
	{
	public:
		CharacterManager();					//�R���X�g���N�^
		void Initialize();					//������
		void Add(CharacterBase* character);	//�I�u�W�F�N�g�̒ǉ�
		void HitToCharacter();				//�I�u�W�F�N�g���m�̏Փ�
		void RemoveDeadCharacters();		//���S�L�������폜
		void Update();						//�X�V
		void Motion();						//���[�V����
		void AddCharacter(CharacterBase* character);//���[�V����


	private:
		std::vector<CharacterBase*> m_character_list;	//�L�����N�^�[���X�g
		std::vector<CharacterBase*> m_add_characters;	//�ǉ��L�����N�^�[

	};
}
