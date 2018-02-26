//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.22
// ���e�@�FGamePlay�V�[��
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>
#include <Scene\game_manager.h>
#include <Character\character_manager.h>
#include <GameObject\AttackSystem\attack_manager.h>
#include <GameObject\AI\MetaAI\meta_ai.h>
#include <GameObject\Background\background.h>
#include <GameObject\Background\change_scene_effect.h>

namespace Scene
{
	class GamePlay : public SceneBase
	{
	public:
		GamePlay(shared_ptr<Background> background, std::shared_ptr<SceneEffect> scene_effect,
			std::shared_ptr<GameManager> game_manager);
		virtual void Initialize(SceneType previous);
		void Update();
		void Draw();
		void Shutdown();

	private:
		///<summary>�I���`�F�b�N</summary>
		void CheckEnd();
		///<summary>�L�����ǉ�</summary>
		void AddCharacter();
		///<summary>�����҂��L�^</summary>
		void SetWinner();

	private:
		std::shared_ptr<GameManager> m_game_manager;						//Game Manager

		std::shared_ptr<Character::CharacterManager> m_character_manager;	//Character Manager
		std::shared_ptr<AttackSystem::AttackManager> m_attack_manager;		//Attacke Manager
		std::shared_ptr<AI::MetaAI> m_meta_ai;								//MetaAI

		std::shared_ptr<Background> m_background;							//�w�istage
		std::shared_ptr<SceneEffect> m_scene_effect;						//Change Scene Effect
	};
}