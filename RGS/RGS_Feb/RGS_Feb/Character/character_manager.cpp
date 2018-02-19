//-------------------------------------------------------
// �쐬�ҁF���@�~��
// �쐬���F2018.02.17
// ���e�@�F�L�����N�^�[�}�l�[�W���[
//-------------------------------------------------------
#include<Character\character_manager.h>

using namespace Character;

CharacterManager::CharacterManager()
{
}
void CharacterManager::Initialize()
{
	m_character_list.clear();
	m_add_characters.clear();
}

void CharacterManager::Add(CharacterBase* character)
{
	m_add_characters.push_back(character);
}

void CharacterManager::HitToCharacter()
{
	//List������o���ē��r
	for each (CharacterBase* c1 in m_character_list)
	{
		for each (CharacterBase* c2 in m_character_list)
		{
			if (c1 == c2 ||
				c1->IsDead() || c2->IsDead())
			{
				//���L�������A�L����������ł����玟��
				continue;
			}
			if (c1->Collision(c2))
			{
				//�q�b�g�ʒm
				c1->Hit(c2);
				c2->Hit(c1);
			}
		}
	}
}

//���S�L�������폜
void CharacterManager::RemoveDeadCharacters()
{
	/*for each (CharacterBase* c in m_character_list)
	{
		if (c->IsDead())
		{
			m_character_list.erase(c);
		}
	}*/
}

//�X�V
void CharacterManager::Update()
{
	//���ׂẴL�����X�V
	for each (CharacterBase* c in m_character_list)
	{
		c->Update();
	}
	//�L�����N�^�[�̒ǉ�
	for each (CharacterBase* c in m_add_characters)
	{
		m_character_list.push_back(c);
	}
	//�ǉ��I����A�ǉ����X�g�̓N���A
	m_add_characters.clear();
	//�����蔻��
	HitToCharacter();
	//���S�����L�������폜
	RemoveDeadCharacters();
}

void CharacterManager::Motion()
{
	for each (CharacterBase* c in m_character_list)
	{
		c->Motion();
	}
}

void CharacterManager::AddCharacter(CharacterBase* character)
{
	m_add_characters.push_back(character);
}
