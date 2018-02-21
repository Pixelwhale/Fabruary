//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.19
// 内容　：全体を見るAI
//-------------------------------------------------------------
#pragma once
#include <Character\character_manager.h>
#include <GameObject\AttackSystem\attack_manager.h>
#include <GameObject\AI\CharaAI\ai_state_manager.h>

namespace AI 
{
	class MetaAI 
	{
	public:
		MetaAI(
			std::shared_ptr<Character::CharacterManager> character_manager,
			std::shared_ptr<AttackSystem::AttackMediator> attack_manager);
		MetaAI(const MetaAI&);
		~MetaAI();

		///<summary>ai追加</summary>
		///<param name="position">位置</param>
		///<param name="side">チーム</param>
		///<param name="job">ジョッブ</param>
		///<param name="difficulty">難易度</param>
		void AddCom(Math::Vector3 position, Side side, std::shared_ptr<Job::JobBase> job, int difficulty);
		///<summary>解放処理</summary>
		void Clear();
		///<summary>更新処理</summary>
		void Update();

		std::shared_ptr<Character::CharacterBase> FindNear(std::shared_ptr<Character::CharacterBase> my_chara);
		std::shared_ptr<Character::CharacterBase> FindStrong(std::shared_ptr<Character::CharacterBase> my_chara);
		std::shared_ptr<Character::CharacterBase> FindWeak(std::shared_ptr<Character::CharacterBase> my_chara);

	private:
		std::shared_ptr<Character::CharacterManager> m_character_manager;	//キャラクター管理者
		std::shared_ptr<AttackSystem::AttackMediator> m_attack_manager;		//攻撃管理者

		vector<AiStateManager> m_ai;										//AI
	};
}