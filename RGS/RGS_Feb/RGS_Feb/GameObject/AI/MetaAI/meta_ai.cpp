//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.21
// ���e�@�F�S�̂�����AI
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
	AiStateManager ai = AiStateManager(difficulty);						//AI�錾

	std::shared_ptr<Character::CharacterBase> character =				//�L�����N�^�[����
		m_character_manager->Add(
			position, side, ai.Controller(), job, m_attack_manager);

	ai.SetCharaInfo(character);											//AI�ɔC��

	m_ai.push_back(ai);													//List�ɒǉ�
}

void MetaAI::Clear()
{
	m_character_manager = NULL;
	m_attack_manager = NULL;
	m_ai.clear();
}

void MetaAI::Update()
{
	//AI�X�V
	for(auto &ai : m_ai)
	{
		ai.Update(this);
	}

	//���񂾃L������AI���폜
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
