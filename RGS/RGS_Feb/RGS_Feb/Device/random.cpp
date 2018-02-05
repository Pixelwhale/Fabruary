//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：昔作ったものをクラス化して持ってきた
// 内容　：Random
//-------------------------------------------------------
#include <Device\random.h>
#include <random>
#include <ctime>

using namespace Device;

Random::Random()
{
	srand((int)time(NULL));	//ランダムを今のタイムで初期化
}

Random::Random(const Random&)
{
}

Random::~Random()
{
}

int Random::Next()
{
	return rand();
}

int Random::Next(int max)
{
	int random = rand() % max;	//最大値を含まない 0 以上の数
	return random;
}

int Random::Next(int min, int max)
{
	int count = max - min;		//範囲内の数
	int random_min = 0 - min;	//最小値
								//余りで範囲を決定、全体を最小値で平行移動
	int random = rand() % count - random_min;
	return random;
}

double Random::NextDouble()
{
	//		int		 int 最大値
	return (rand() / (RAND_MAX * 1.0));
}