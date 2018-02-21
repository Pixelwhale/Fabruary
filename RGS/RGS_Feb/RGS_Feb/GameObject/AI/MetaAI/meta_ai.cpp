//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.21
// 内容　：全体を見るAI
//-------------------------------------------------------------
#include <GameObject\AI\MetaAI\meta_ai.h>

using namespace AI;

MetaAI::MetaAI(
	std::shared_ptr<Character::CharacterManager> character_manager,
	std::shared_ptr<AttackSystem::AttackMediator> attack_manager)
{
}

MetaAI::MetaAI(const MetaAI&) {}

MetaAI::~MetaAI()
{
	Clear();
}

void MetaAI::AddCom(Math::Vector3 position, Side side, std::shared_ptr<Job::JobBase> job, int difficulty)
{
	AiStateManager ai = AiStateManager(difficulty);						//AI宣言

	std::shared_ptr<Character::CharacterBase> character =				//キャラクター生成
		m_character_manager->Add(
			position, side, ai.Controller(), job, m_attack_manager);

	ai.SetCharaInfo(character);											//AIに任す

	m_ai.push_back(ai);													//Listに追加
}

void MetaAI::Clear()
{
	m_character_manager = NULL;
	m_attack_manager = NULL;
	m_ai.clear();
}

void MetaAI::Update()
{
	//AI更新
	for(auto &ai : m_ai)
	{
		ai.Update(this);
	}

	//死んだキャラのAIを削除
	for (std::vector<AiStateManager>::iterator i = m_ai.begin(); i != m_ai.end();) 
	{
		if ((*i).IsDead()) 
		{
			m_ai.erase(i);
			continue;
		}
		i++;
	}
}

std::shared_ptr<Character::CharacterBase> MetaAI::FindNear(std::shared_ptr<Character::CharacterBase> my_chara) 
{
	std::shared_ptr<Character::CharacterBase> near_chara;
	for (auto &c : m_character_manager->GetCharacterList())
	{
		if (c == my_chara)		//同じならContinue
			continue;

		if (near_chara == NULL)	//まだ設定してない状態なら設定する
		{
			near_chara = c;
			continue;
		}

		//距離を比較する
		if ((c->GetPosition() - my_chara->GetPosition()).lengthSqrt() <
			(near_chara->GetPosition() - my_chara->GetPosition()).lengthSqrt())
		{
			near_chara = c;
		}
	}

	return near_chara;
}

std::shared_ptr<Character::CharacterBase> MetaAI::FindStrong(std::shared_ptr<Character::CharacterBase> my_chara)
{
	std::shared_ptr<Character::CharacterBase> strong_chara;
	for (auto &c : m_character_manager->GetCharacterList())
	{
		if (c == my_chara)			//同じならContinue
			continue;

		if (strong_chara == NULL)	//まだ設定してない状態なら設定する
		{
			strong_chara = c;
			continue;
		}

		//残るHPを比較する
		if (c->GetHp() > strong_chara->GetHp())
		{
			strong_chara = c;
		}
	}

	return strong_chara;
}

std::shared_ptr<Character::CharacterBase> MetaAI::FindWeak(std::shared_ptr<Character::CharacterBase> my_chara)
{
	std::shared_ptr<Character::CharacterBase> weak_chara;
	for (auto &c : m_character_manager->GetCharacterList())
	{
		if (c == my_chara)			//同じならContinue
			continue;

		if (weak_chara == NULL)	//まだ設定してない状態なら設定する
		{
			weak_chara = c;
			continue;
		}

		//残るHPを比較する
		if (c->GetHp() < weak_chara->GetHp())
		{
			weak_chara = c;
		}
	}

	return weak_chara;
}
