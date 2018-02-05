//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.12
// 内容　：透明のあるテクスチャはソートして描画する必要が
//			あるので、そのためのクラス
//-------------------------------------------------------
#include <Device\depth_sort.h>
#include <algorithm>

using namespace Device;

DepthSort::DepthSort(){}
DepthSort::DepthSort(const DepthSort&){}
DepthSort::~DepthSort(){}

void DepthSort::AddTransparentObj(TransparentObj obj)
{
	m_draw_list.push_back(obj);
}

void DepthSort::Clear()
{
	m_draw_list.clear();
}

void DepthSort::Sort(Math::Vector3 projector_pos)
{
	for (auto& obj:m_draw_list)		//カメラとの距離を計算
	{
		obj.projection_dis = (projector_pos - obj.position).lengthSqrt();
	}

	std::sort(m_draw_list.begin(), m_draw_list.end(), [](const TransparentObj& first, const TransparentObj& second)
	{
		return first.projection_dis > second.projection_dis;		//Sort
	});
}

std::vector<TransparentObj>& DepthSort::DrawList()
{
	return m_draw_list;
}