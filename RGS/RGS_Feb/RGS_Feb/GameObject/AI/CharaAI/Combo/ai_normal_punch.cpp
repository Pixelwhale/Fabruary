//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.19
// 内容　：NormalPunchのAiState
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
	m_timer.Update();				//遅延更新
	if (!m_timer.IsTime())			//遅延中は以下実行しない
		return;
	if (!IsInAttckRange())			//範囲内か判断する
		return;

	controller->TriggerPunch();		//パンチする
	m_punch_count--;				//指定回数を減らす
	ResetTimer();

	if (m_punch_count <= 0)			//指定回数に達したら終わる
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