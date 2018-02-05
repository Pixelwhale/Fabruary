//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：昔作ったものをクラス化して持ってきた
// 内容　：Random
//-------------------------------------------------------
#pragma once

namespace Device 
{
	class Random 
	{
	public:
		Random();
		Random(const Random&);
		~Random();

		///<summary>0以上の整数を返す</summary>
		int Next();
		///<summary>0以上max未満の整数を返す</summary>
		///<param name="max">最大値</param>
		int Next(int max);
		///<summary>min以上max未満の整数を返す</summary>
		///<param name="min">最小値</param>
		///<param name="max">最大値</param>
		int Next(int min, int max);

		///<summary>0から1のDoubleを返す</summary>
		double NextDouble();
	};
}