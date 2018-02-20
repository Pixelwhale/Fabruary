//-------------------------------------------------------
// �쐬�ҁF���@�~��
// �쐬���F2018.02.17
// ���e�@�F�L�����N�^�[�}�l�[�W���[
//-------------------------------------------------------
#pragma once
#include <Device\game_device.h>
#include <Character\character_base.h>
#include <Math\vector3.h>

namespace Character
{
	class CharacterManager
	{
	public:
		CharacterManager();					//�R���X�g���N�^
		void Initialize();					//������
		std::shared_ptr<CharacterBase> Add(Math::Vector3 position, Side side, 
			std::shared_ptr<VirtualController> controller,std::shared_ptr<Job::JobBase> job, 
			std::shared_ptr<AttackSystem::AttackMediator> attackMediator);	//�I�u�W�F�N�g�̒ǉ�
		void Update();						//�X�V
		bool GetEnd();
		std::vector<std::shared_ptr<CharacterBase>>& GetCharacterList();//�L�����N�^�[���X�g�̎擾

	private:
		void RemoveDeadCharacters();		//���S�L�������폜

	private:
		std::vector<std::shared_ptr<CharacterBase>> m_character_list;	//�L�����N�^�[���X�g
		std::vector<std::shared_ptr<CharacterBase>> m_add_characters;	//�ǉ��L�����N�^�[

		bool m_isEnd;
		int m_id;
	};
}
