//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2018.02.22
//-------------------------------------------------------
#include "chara_select.h"

using namespace Scene;

CharaSelect::CharaSelect()
{
}

void CharaSelect::Update()
{
}

void CharaSelect::Draw()
{
	m_renderer->DrawString("CharaSelect", Math::Vector2(150, 0));
}

void CharaSelect::Shutdown()
{
}