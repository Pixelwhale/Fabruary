//-------------------------------------------------------
// 作成者：金　淳元
// 作成日：2018.02.17
// 内容　：キャラクターマネージャー
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

//死亡キャラを削除
void CharacterManager::RemoveDeadCharacters()
{
	
}

//更新
void CharacterManager::Update()
{
	//すべてのキャラ更新
	for (auto c : m_character_list)
	{
		c->Update();
	}
	//キャラクターの追加
	for (auto c : m_add_characters)
	{
		m_character_list.push_back(c);
	}
	//追加終了後、追加リストはクリア
	m_add_characters.clear();
	//あたり判定
	Collide();
	//死亡したキャラを削除
	RemoveDeadCharacters();
}

void CharacterManager::Motion()
{
	for (auto c : m_character_list)
	{
		c->Motion();
	}
}

