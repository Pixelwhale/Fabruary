//-------------------------------------------------------
// 作成者：金　淳元
// 作成日：2018.02.17
// 内容　：キャラクターマネージャー
//-------------------------------------------------------
#include<Character\character_manager.h>
#include<Def\character_color.h>

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
	m_ui_list.clear();
	m_hp_ui = std::make_shared<UI::HpUI>();
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
	m_ui_list.push_back(character);
	m_id++;
	return character;
}


//死亡キャラを削除
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

	for (auto c : m_character_list)
	{
		m_winner_list.push_back(c);
		//勝利キャラクター設定
		c->SetWinner(true);
	}

	m_isEnd = true;
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
	//死亡したキャラを削除
	RemoveDeadCharacters();
}

//描画
void CharacterManager::Draw()
{
	for (auto c:m_character_list)
	{
		c->Draw();
	}
	for (auto c : m_ui_list)
	{
		m_hp_ui->SetPosition(CharacterColor::GetUIPosition(c->GetSide()));
		m_hp_ui->SetColor(CharacterColor::GetTeamColor(c->GetSide()),
			              CharacterColor::GetIconColor(c->GetSide()));
		if (c->IsDead())
		{
			Color colorDead = Color(88,88,88);
			m_hp_ui->SetColor(colorDead,colorDead);
		}
		m_hp_ui->Draw((float)c->GetHp() / (float)c->GetMaxHp(),
					  (float)c->GetMp() / 6000.0f, c->GetFaceNum());
	}
	
}

//Clear
void CharacterManager::Clear()
{
	std::vector<std::shared_ptr<CharacterBase>>::iterator it;
	for (it = m_character_list.begin(); it != m_character_list.end();)
	{
		(*it) = NULL;
	}
	m_character_list.clear();
	for (it = m_add_characters.begin(); it != m_add_characters.end();)
	{
		(*it) = NULL;
	}
	m_add_characters.clear();
	for (it = m_ui_list.begin(); it != m_ui_list.end();)
	{
		(*it) = NULL;
	}
	m_ui_list.clear();

	m_hp_ui = NULL;
}

//キャラクターリストの取得
std::vector<std::shared_ptr<CharacterBase>>& CharacterManager::GetCharacterList()
{
	return m_character_list;
}

//勝利キャラクターリストの取得
std::vector<std::shared_ptr<CharacterBase>>& CharacterManager::GetWinnerList()
{
	return m_winner_list;
}

bool CharacterManager::GetEnd()
{
	return m_isEnd;
}
