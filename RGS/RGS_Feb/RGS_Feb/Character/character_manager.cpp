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
	m_isEnd = false;
}
void CharacterManager::Initialize()
{
	m_character_list.clear();
	m_add_characters.clear();
}

std::shared_ptr<CharacterBase> CharacterManager::Add(Math::Vector3 position, Side side,
			std::shared_ptr<VirtualController> controller,
			std::shared_ptr<Job::JobBase> job,
			std::shared_ptr<AttackSystem::AttackMediator> attackMediator)
{
	std::shared_ptr<CharacterBase>character = std::make_shared<CharacterBase>
											(position, side, m_id,controller,job, attackMediator);
	character->Initialize(position);
	m_add_characters.push_back(character);
	m_id++;
	return character;
}


//���S�L�������폜
void CharacterManager::RemoveDeadCharacters()
{
	bool isDelete = false;
	std::vector<std::shared_ptr<CharacterBase>>::iterator it;
	for (it = m_character_list.begin(); it != m_character_list.end();)
	{
		if ((*it)->IsDead())
		{
			it = m_character_list.erase(it);
			isDelete = true;
		}
		else
		{
			++it;
		}
	}

	if (!isDelete)
	{
		return;
	}
	for (auto c1 : m_character_list)
	{
		for (auto c2 : m_character_list)
		{
			if (c1->GetSide() != c2->GetSide())
			{
				return;
			}
		}
	}
	
	m_isEnd = true;
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

//�`��
void CharacterManager::Draw()
{
	for (auto c:m_character_list)
	{
		c->Draw();
	}
}

std::vector<std::shared_ptr<CharacterBase>>& CharacterManager::GetCharacterList()
{
	return m_character_list;
}

bool CharacterManager::GetEnd()
{
	return m_isEnd;
}
