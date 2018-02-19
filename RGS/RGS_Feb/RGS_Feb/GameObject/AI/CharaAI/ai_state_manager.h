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
		AiStateManager();
		AiStateManager(const AiStateManager&);
		~AiStateManager();

		void Update(std::shared_ptr<MetaAI> meta_ai);

	private:
		int m_difficulty;											//強さ
		std::shared_ptr<Character::AiController> controller;		//コントローラー

		std::shared_ptr<AiState> m_current_state;					//今の行動パターン
		std::shared_ptr<Character::CharacterBase> m_character;		//操作するキャラ
	};
}