//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.02.05
// 内容：CollisionBoxの更新と描画
//-------------------------------------------------------
#include "attack_manager.h";

using namespace AttackSystem;

AttackManager::AttackManager()
{
	m_atk_list.clear();
}

AttackManager::~AttackManager()
{
	m_atk_list.clear();
}

void AttackManager::Initialize()
{
	m_atk_list.clear();
}