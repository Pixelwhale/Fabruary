//-------------------------------------------------------
// 作成者：金　淳元
// 作成日：2018.02.17
// 内容　：キャラクターマネージャー
//-------------------------------------------------------
#pragma once
#include <Device\game_device.h>
#include<Character\character_base.h>

namespace Character
{
	class CharacterManager
	{
	public:
		CharacterManager();					//コンストラクタ
		void Initialize();					//初期化
		void Add(CharacterBase* character);	//オブジェクトの追加
		void HitToCharacter();
		void RemoveDeadCharacters();
		void Update();
		void Motion();
		void AddCharacter(CharacterBase* character);


	private:
		std::vector<CharacterBase>* m_character_list;	//キャラクターリスト
		std::vector<CharacterBase>* m_add_characters;	//追加キャラクター

	};
}
