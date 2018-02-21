//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.19
// ���e�@�FNormalPunch��AiState
//-------------------------------------------------------------
#include <GameObject\AI\CharaAI\Combo\ai_normal_punch.h>
#include <Character\character_base.h>

using namespace AI;

NormalPunch::NormalPunch(
	std::shared_ptr<Character::CharacterBase> my_chara,
	std::shared_ptr<Character::CharacterBase> target, int count)
	:m_character(my_chara), m_target(target), m_punch_count(count)
{
	m_end_flag = false;

	m_random = Device::GameDevice::GetInstance()->GetRandom();
	ResetTimer();
}

NormalPunch::NormalPunch(const NormalPunch&) 
{
}

NormalPunch::~NormalPunch() 
{
	m_random = NULL;
	m_character = NULL;
	m_target = NULL;
}

void NormalPunch::GetBattleInfo(MetaAI* meta_ai)
{
	return;
}

void NormalPunch::Update(std::shared_ptr<Character::AiController> controller) 
{
	m_timer.Update();				//�x���X�V
	if (!m_timer.IsTime())			//�x�����͈ȉ����s���Ȃ�
		return;
	if (!IsInAttckRange())			//�͈͓������f����
		return;

	controller->TriggerPunch();		//�p���`����
	m_punch_count--;				//�w��񐔂����炷
	ResetTimer();

	if (m_punch_count <= 0)			//�w��񐔂ɒB������I���
		m_end_flag = true;
}

std::shared_ptr<AiState> NormalPunch::NextState(int difficulty) 
{
	return std::make_shared<NormalPunch>(m_character, m_target, 3);
}

void NormalPunch::ResetTimer() 
{
	m_timer = Utility::Timer(m_random->Next(15, 25) / 60.0f);
}

bool NormalPunch::IsInAttckRange() 
{
	float distance = (m_character->GetPosition() - m_target->GetPosition()).lengthSqrt();
	return distance < (Size::kCharaX * 1.5f) * (Size::kCharaX * 1.5f);
}