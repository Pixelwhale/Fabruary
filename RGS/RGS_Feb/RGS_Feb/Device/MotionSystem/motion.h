//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.8
// 内容　：SpriteStudioの機能を簡単にまとめたモーションクラス
//-------------------------------------------------------------
#pragma once
#include <ssbpLib\SS5Player.h>
#include <Device\projector.h>
#include <Color\color.h>
#include <Math\vector3.h>
#include <Math\vector2.h>

namespace MotionSystem
{
	class Motion 
	{
	public:
		///<summary>モーションクラス</summary>
		///<param name="asset_name">ssbpファイル名（拡張子抜き）</param>
		Motion(string asset_name);
		Motion(const Motion&);
		~Motion();

		///<summary>Positionなどの初期値を設定</summary>
		void Initialize();
		///<summary>データ解放</summary>
		void Release();
		///<summary>プレイするモーション</summary>
		///<param name="motion_name">ssaeファイル名（拡張子抜き）/ Animation名</param>
		///<param name="loop">何回ループするか(無限 = 0)</param>
		void Play(string motion_name, int loop = 0);
		///<summary>データ解放</summary>
		void ChangeSpriteSheet(string sheet_name);

		///<summary>更新処理</summary>
		void Update(float frame = 1 / 60.0f);
		///<summary>描画処理</summary>
		void Draw();

		///<summary>位置設定</summary>
		void SetPosition(Math::Vector3 position);
		///<summary>色設定</summary>
		void SetColor(Color color);
		///<summary>大きさ設定</summary>
		void SetScale(Math::Vector2 scale);
		///<summary>反転するか</summary>
		///<param name="x">x軸に対して反転するか</param>
		///<param name="y">y軸に対して反転するか</param>
		void Flip(bool x, bool y);
		///<summary>アニメーション再生終了か（無限ループは無効）</summary>
		bool IsCurrentMotionEnd();

		///<summary>Frame数設定</summary>
		void SetFrame(int frame);

	private:
		ss::Player* m_motion_player;						//motion Player
		std::string m_current_motion;						//現在のモーション
		std::shared_ptr<Device::Projector> m_projector;		//描画修正用（Camera）

		Math::Vector3 m_position;							//位置
		Math::Vector2 m_scale;								//大きさ
	};
}