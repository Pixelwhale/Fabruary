//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.19
// 内容　：AiStateのインターフェース
//-------------------------------------------------------------
#pragma once
#include <memory>
#include <Character\Controller\ai_controller.h>

namespace AI
{
	class MetaAI;

	class AiState
	{
	public:
		~AiState() {}
		virtual void GetBattleInfo(std::shared_ptr<MetaAI> meta_ai) = 0;
		virtual void Update(std::shared_ptr<Character::AiController>) = 0;
		virtual std::shared_ptr<AiState> NextState() = 0;

		bool IsEnd() { return m_end_flag; }

	protected:
		bool m_end_flag;
	};
}