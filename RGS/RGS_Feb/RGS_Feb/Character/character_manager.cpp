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

void CharacterManager::Add(Math::Vector3 position, Side side,int hp)
{
	std::shared_ptr<CharacterBase>character = std::make_shared<CharacterBase>(position, side, m_id, hp);
	m_add_characters.push_back(character);
	m_id++;
}

void CharacterManager::Collide()
{
	for (auto c : m_character_list)
	{
		c->Collide();
	}
}

//���S�L�������폜
void CharacterManager::RemoveDeadCharacters()
{
	
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
	//�����蔻��
	Collide();
	//���S�����L�������폜
	RemoveDeadCharacters();
}

void CharacterManager::Motion()
{
	for (auto c : m_character_list)
	{
		c->Motion();
	}
}

