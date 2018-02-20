//-------------------------------------------------------
// 作成者：金　淳元
// 作成日：2018.02.17
// 内容　：キャラクターマネージャー
//-------------------------------------------------------
#pragma once
#include <Device\game_device.h>
#include <Character\character_base.h>
#include <Math\vector3.h>

namespace Character
{
	class CharacterManager
	{
	public:
		CharacterManager();					//コンストラクタ
		void Initialize();					//初期化
		std::shared_ptr<CharacterBase> Add(Math::Vector3 position, Side side, int hp,
			std::shared_ptr<VirtualController> controller,std::shared_ptr<Job::JobBase> job, 
			std::shared_ptr<AttackSystem::AttackMediator> attackMediator);	//オブジェクトの追加
		void RemoveDeadCharacters();		//死亡キャラを削除
		void Update();						//更新
		std::vector<std::shared_ptr<CharacterBase>>& GetCharacterList();//キャラクターリストの取得

	private:
		std::vector<std::shared_ptr<CharacterBase>> m_character_list;	//キャラクターリスト
		std::vector<std::shared_ptr<CharacterBase>> m_add_characters;	//追加キャラクター

		int m_id;
	};
}
