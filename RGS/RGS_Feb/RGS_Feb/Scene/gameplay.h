//-------------------------------------------------------
// ì¬ÒFœ@Œ[Ÿ
// ì¬“úF2018.02.05
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>
#include <Character\character_manager.h>
#include <GameObject\AttackSystem\attack_manager.h>
#include <GameObject\AI\MetaAI\meta_ai.h>

namespace Scene
{
	class GamePlay : public SceneBase
	{
	public:
		GamePlay();
		virtual void Initialize(SceneType previous);
		void Update();
		void Draw();
		void Shutdown();
		void CheckEnd();

	private:
		std::shared_ptr<Character::CharacterManager> m_character_manager;	//Character Manager
		std::shared_ptr<AttackSystem::AttackManager> m_attack_manager;		//Attacke Manager
		std::shared_ptr<AI::MetaAI> m_meta_ai;								//MetaAI
	};
}