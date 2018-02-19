//-------------------------------------------------------
// �쐬�ҁF���@�~��
// �쐬���F2018.02.17
// ���e�@�F�L�����N�^�[�}�l�[�W���[
//-------------------------------------------------------
#pragma once
#include <Device\game_device.h>
#include<Character\character_base.h>
#include<Math\vector3.h>

namespace Character
{
	class CharacterManager
	{
	public:
		CharacterManager();					//�R���X�g���N�^
		void Initialize();					//������
		void Add(Math::Vector3 position, Side side, int hp);	//�I�u�W�F�N�g�̒ǉ�
		void Collide();						//�I�u�W�F�N�g���m�̏Փ�
		void RemoveDeadCharacters();		//���S�L�������폜
		void Update();						//�X�V
		void Motion();						//���[�V����

	private:
		std::vector<std::shared_ptr<CharacterBase>> m_character_list;	//�L�����N�^�[���X�g
		std::vector<std::shared_ptr<CharacterBase>> m_add_characters;	//�ǉ��L�����N�^�[

		static int m_id;
	};
}
