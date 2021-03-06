//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.19
// 内容　：AiStateを管理するマネージャー
//-------------------------------------------------------------
#include <GameObject\AI\CharaAI\ai_state_manager.h>
#include <GameObject\AI\CharaAI\ComplexState\ai_wait.h>
#include <GameObject\AI\MetaAI\meta_ai.h>
#include <GameObject\AI\CharaAI\Defence\ai_defence.h>
#include <Character\character_base.h>

using namespace AI;

AiStateManager::AiStateManager(int difficulty, std::shared_ptr<Character::VirtualController> controller)
	:m_difficulty(difficulty), m_controller(std::static_pointer_cast<Character::AiController>(controller))
{
}

AiStateManager::AiStateManager(const AiStateManager&) 
{
}

AiStateManager::~AiStateManager() 
{
	m_controller = NULL;
	m_current_state = NULL;
	m_character = NULL;
}

void AiStateManager::Update(MetaAI* meta_ai) 
{
	m_controller->Update();									//キーを先に更新

	CheckDefence(meta_ai);
	m_current_state->GetBattleInfo(meta_ai);				//戦場情報を与える
	m_current_state->Update(m_controller);					//AI思考
	
	if (m_current_state->IsEnd())							//AI変更
	{
		m_current_state = m_current_state->NextState(m_difficulty);
	}
}


void AiStateManager::SetCharaInfo(std::shared_ptr<Character::CharacterBase> character) 
{
	m_character = character;
	m_current_state = std::make_shared<Wait>(m_character, 0.3f);
}

bool AiStateManager::IsDead()
{
	return m_character->IsDead();
}

void AiStateManager::CheckDefence(MetaAI* meta_ai)
{
	if (meta_ai->NeedToDefence(m_character) && !m_is_defence) 
	{
		m_current_state = std::make_shared<Defence>(m_current_state, m_difficulty);
		m_is_defence = true;
	}
	else if(m_is_defence)
	{
		m_current_state = m_current_state->NextState(m_difficulty);
		m_is_defence = false;
	}
}