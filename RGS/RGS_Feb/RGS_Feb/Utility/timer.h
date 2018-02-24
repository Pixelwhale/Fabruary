//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.15
// 内容　：カウントダウンのタイマー
//-------------------------------------------------------

#pragma once
#include <memory>

namespace Utility
{
	class Timer
	{
	public:
		Timer();
		Timer(float seconds);
		Timer(const Timer&);
		~Timer();
		///<summary>タイマーを更新</summary>
		void Update();
		///<summary>タイマーをリセット</summary>
		void Reset();
		///<summary>零になったか？</summary>
		bool IsTime();
		float GetCurrentTimes() const { return m_current_time; }
		float Rate();

	private:
		float m_limit_time = 0;	// 何秒ですか？
		float m_current_time = 0;	// 時間の今の状態
	};
}