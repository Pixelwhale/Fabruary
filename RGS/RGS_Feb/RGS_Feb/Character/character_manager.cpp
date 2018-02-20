//-------------------------------------------------------
// �쐬�ҁF���@�~��
// �쐬���F2018.02.17
// ���e�@�F�L�����N�^�[�}�l�[�W���[
//-------------------------------------------------------
#include<Character\character_manager.h>

using namespace Character;

CharacterManager::CharacterManager()
{
	m_id = 0;
}
void CharacterManager::Initialize()
{
	m_character_list.clear();
	m_add_characters.clear();
}

std::shared_ptr<CharacterBase> CharacterManager::Add(Math::Vector3 position, Side side,int hp,
			std::shared_ptr<VirtualController> controller,
			std::shared_ptr<Job::JobBase> job,
			std::shared_ptr<AttackSystem::AttackMediator> attackMediator)
{
	std::shared_ptr<CharacterBase>character = std::make_shared<CharacterBase>
											(position, side, m_id, hp, controller,job, attackMediator);
	m_add_characters.push_back(character);
	m_id++;
	return character;
}


//���S�L�������폜
void CharacterManager::RemoveDeadCharacters()
{
	std::vector<std::shared_ptr<CharacterBase>>::iterator it;
	for (it = m_character_list.begin(); it != m_character_list.end();)
	{
		if ((*it)->IsDead())
		{
			it = m_character_list.erase(it);
		}
		else
		{
			++it;
		}
	}
}

//�X�V
void CharacterManager::Update()
{
	//���ׂẴL�����X�V
	for (auto c : m_character_list)
	{
		c->Update();
	}
	//�L�����N�^�[�̒ǉ�
	for (auto c : m_add_characters)
	{
		m_character_list.push_back(c);
	}
	//�ǉ��I����A�ǉ����X�g�̓N���A
	m_add_characters.clear();
	//���S�����L�������폜
	RemoveDeadCharacters();
}

std::vector<std::shared_ptr<CharacterBase>>& CharacterManager::GetCharacterList()
{
	return m_character_list;
}
