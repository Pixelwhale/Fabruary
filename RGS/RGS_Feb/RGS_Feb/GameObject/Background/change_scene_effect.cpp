//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.24
// 内容　：SceneChangeのEffect
//-------------------------------------------------------
#include <GameObject\Background\change_scene_effect.h>

SceneEffect::SceneEffect()
{
	m_renderer = Device::GameDevice::GetInstance()->GetRenderer();

	m_is_zoom = false;
	m_rate = 1.0f;
	m_pivot = Math::Vector2();
}

SceneEffect::SceneEffect(const SceneEffect&)
{
}

SceneEffect::~SceneEffect()
{
	m_renderer = NULL;
}

void SceneEffect::SetZoomRate(float zoom_rate)
{
	m_rate = zoom_rate;
}

void SceneEffect::Zoom(bool is_zoom)
{
	m_is_zoom = is_zoom;
}

void SceneEffect::Update()
{
	if (m_is_zoom) 
	{
		m_rate += 0.1f;
		if (m_rate >= 5.0f)
		{
			m_rate = 5.0f;
		}
	}
	else 
	{
		m_rate -= 0.1f;
		if (m_rate <= 1.0f)
		{
			m_rate = 1.0f;
		}
	}

	m_pivot = m_pivot.Lerp(Math::Vector2(), Math::Vector2(257, 118), (m_rate - 1) / 4.0f);
}

void SceneEffect::DrawOnEffect()
{
	m_renderer->DrawOnResizeFilter();
}

void SceneEffect::DrawEffect()
{
	m_renderer->DrawResize(Math::Vector2(), Math::Vector2(m_rate), m_pivot);
}

bool SceneEffect::IsEnd(bool zoom_in)
{
	if (zoom_in)
		return m_rate >= 5.0f;

	return m_rate <= 1.0f;
}