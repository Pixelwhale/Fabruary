//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2017.02.15
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

	private:
		int m_limit_time;	// 何秒ですか？
		int m_current_time;	// 時間の今の状態
	};
}