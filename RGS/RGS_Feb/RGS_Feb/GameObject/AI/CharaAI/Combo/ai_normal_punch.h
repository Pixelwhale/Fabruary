//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.19
// 内容　：NormalPunchのAiState
//-------------------------------------------------------------
#pragma once
#include <GameObject\AI\CharaAI\ai_state.h>
#include <Device\game_device.h>
#include <Utility\timer.h>

namespace Character
{
	class CharacterBase;
}

namespace AI
{
	class NormalPunch : public AiState
	{
	public:
		NormalPunch(
			std::shared_ptr<Character::CharacterBase> my_chara,
			std::shared_ptr<Character::CharacterBase> target, int count);
		NormalPunch(const NormalPunch&);
		~NormalPunch();

		virtual void GetBattleInfo(MetaAI* meta_ai);
		virtual void Update(std::shared_ptr<Character::AiController> controller);
		virtual std::shared_ptr<AiState> NextState(int difficulty);

	private:
		///<summary>遅延時間をリセット</summary>
		void ResetTimer();
		///<summary>攻撃範囲内か</summary>
		bool IsInAttckRange();

	private:
		Device::Random* m_random;		//ランダム
		Utility::Timer m_timer;			//遅延時間

		std::shared_ptr<Character::CharacterBase> m_character;		//自機
		std::shared_ptr<Character::CharacterBase> m_target;			//ターゲット
		int m_punch_count;											//パンチ数
	};
}