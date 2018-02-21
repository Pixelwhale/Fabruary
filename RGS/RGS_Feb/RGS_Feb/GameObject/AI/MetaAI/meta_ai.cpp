//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.21
// 内容　：全体を見るAI
//-------------------------------------------------------------
#include <GameObject\AI\MetaAI\meta_ai.h>

using namespace AI;

MetaAI::MetaAI(
	std::shared_ptr<Character::CharacterManager> character_manager,
	std::shared_ptr<AttackSystem::AttackManager> attack_manager)
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
}

std::shared_ptr<Character::CharacterBase> MetaAI::FindStrong() 
{
}

std::shared_ptr<Character::CharacterBase> MetaAI::FindWeak() 
{
}
