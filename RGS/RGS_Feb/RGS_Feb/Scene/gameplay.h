//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.22
// 内容　：GamePlayシーン
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>
#include <Scene\game_manager.h>
#include <Character\character_manager.h>
#include <GameObject\AttackSystem\attack_manager.h>
#include <GameObject\AI\MetaAI\meta_ai.h>
#include <GameObject\Background\background.h>

namespace Scene
{
	class GamePlay : public SceneBase
	{
	public:
		GamePlay(std::shared_ptr<GameManager> game_manager);
		virtual void Initialize(SceneType previous);
		void Update();
		void Draw();
		void Shutdown();

	private:
		void CheckEnd();

	private:
		std::shared_ptr<GameManager> m_game_manager;						//Game Manager

		std::shared_ptr<Character::CharacterManager> m_character_manager;	//Character Manager
		std::shared_ptr<AttackSystem::AttackManager> m_attack_manager;		//Attacke Manager
		std::shared_ptr<AI::MetaAI> m_meta_ai;								//MetaAI

		std::shared_ptr<Background> m_background;							//背景stage
	};
}