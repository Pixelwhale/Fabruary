//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.19
// ���e�@�FAiState���Ǘ�����}�l�[�W���[
//-------------------------------------------------------------
#include <GameObject\AI\CharaAI\ai_state_manager.h>
#include <GameObject\AI\CharaAI\ComplexState\ai_wait.h>
#include <Character\character_base.h>

using namespace AI;

AiStateManager::AiStateManager(int difficulty)
	:m_difficulty(difficulty)
{
	m_controller = std::make_shared<Character::AiController>();
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
	m_controller->Update();									//�L�[���ɍX�V

	m_current_state->GetBattleInfo(meta_ai);				//������^����
	m_current_state->Update(m_controller);					//AI�v�l
	
	if (m_current_state->IsEnd())							//AI�ύX
	{
		m_current_state = m_current_state->NextState(m_difficulty);
	}
}

std::shared_ptr<Character::AiController> AiStateManager::Controller() 
{
	return m_controller;
}

void AiStateManager::SetCharaInfo(std::shared_ptr<Character::CharacterBase> character) 
{
	m_character = character;
	m_current_state = std::make_shared<Wait>(m_character, 1.0f);
}

bool AiStateManager::IsDead()
{
	return m_character->IsDead();
}