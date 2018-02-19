//-------------------------------------------------------
// 作成者：金　淳元
// 作成日：2018.02.17
// 内容　：キャラクターマネージャー
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
	//Listから取り出して二つ比較
	for each (CharacterBase* c1 in m_character_list)
	{
		for each (CharacterBase* c2 in m_character_list)
		{
			if (c1 == c2 ||
				c1->IsDead() || c2->IsDead())
			{
				//同キャラか、キャラが死んでいたら次へ
				continue;
			}
			if (c1->Collision(c2))
			{
				//ヒット通知
				c1->Hit(c2);
				c2->Hit(c1);
			}
		}
	}
}

//死亡キャラを削除
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

//更新
void CharacterManager::Update()
{
	//すべてのキャラ更新
	for each (CharacterBase* c in m_character_list)
	{
		c->Update();
	}
	//キャラクターの追加
	for each (CharacterBase* c in m_add_characters)
	{
		m_character_list.push_back(c);
	}
	//追加終了後、追加リストはクリア
	m_add_characters.clear();
	//あたり判定
	HitToCharacter();
	//死亡したキャラを削除
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
