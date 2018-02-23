//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.19
// 内容　：AiStateを管理するマネージャー
//-------------------------------------------------------------
#pragma once
#include <Character\Controller\ai_controller.h>
#include <GameObject\AI\CharaAI\ai_state.h>

namespace Character 
{
	class CharacterBase;
}

namespace AI 
{
	class AiStateManager 
	{
	public:
		AiStateManager(int difficulty, int player_num);
		AiStateManager(const AiStateManager&);
		~AiStateManager();

		///<summary>Aiの操作更新</summary>
		void Update(MetaAI* meta_ai);

		///<summary>キャラ生成する時に必要なコントローラー</summary>
		std::shared_ptr<Character::AiController> Controller();
		///<summary>実機状態を取得できるように設定</summary>
		void SetCharaInfo(std::shared_ptr<Character::CharacterBase> character);


		///<summary>操作したキャラは死んでいるか</summary>
		bool IsDead();

	private:
		void CheckDefence(MetaAI* meta_ai);

	private:
		int m_difficulty;											//強さ
		bool m_is_defence = false;
		std::shared_ptr<Character::AiController> m_controller;		//コントローラー

		std::shared_ptr<AiState> m_current_state;					//今の行動パターン
		std::shared_ptr<Character::CharacterBase> m_character;		//操作するキャラ
	};
}