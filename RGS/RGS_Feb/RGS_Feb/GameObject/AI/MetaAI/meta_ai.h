//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.19
// ���e�@�F�S�̂�����AI
//-------------------------------------------------------------
#pragma once
#include <Character\character_manager.h>
#include <GameObject\AttackSystem\attack_manager.h>
#include <GameObject\AI\CharaAI\ai_state_manager.h>

namespace AI 
{
	class MetaAI 
	{
	public:
		MetaAI(
			std::shared_ptr<Character::CharacterManager> character_manager,
			std::shared_ptr<AttackSystem::AttackMediator> attack_manager);
		MetaAI(const MetaAI&);
		~MetaAI();

		///<summary>ai�ǉ�</summary>
		///<param name="position">�ʒu</param>
		///<param name="side">�`�[��</param>
		///<param name="job">�W���b�u</param>
		///<param name="difficulty">��Փx</param>
		void AddCom(Math::Vector3 position, Side side, std::shared_ptr<Job::JobBase> job, int difficulty);
		///<summary>�������</summary>
		void Clear();
		///<summary>�X�V����</summary>
		void Update();

		std::shared_ptr<Character::CharacterBase> FindNear(std::shared_ptr<Character::CharacterBase> my_chara);
		std::shared_ptr<Character::CharacterBase> FindStrong(std::shared_ptr<Character::CharacterBase> my_chara);
		std::shared_ptr<Character::CharacterBase> FindWeak(std::shared_ptr<Character::CharacterBase> my_chara);

	private:
		std::shared_ptr<Character::CharacterManager> m_character_manager;	//�L�����N�^�[�Ǘ���
		std::shared_ptr<AttackSystem::AttackMediator> m_attack_manager;		//�U���Ǘ���

		vector<AiStateManager> m_ai;										//AI
	};
}