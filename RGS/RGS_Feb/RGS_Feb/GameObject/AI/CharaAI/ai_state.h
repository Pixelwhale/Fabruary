#pragma once
#include <memory>
#include <GameObject\AI\MetaAI\meta_ai.h>

namespace AI
{
	class AiState
	{
	public:
		~AiState() {}
		virtual void GetBattleInfo(std::shared_ptr<MetaAI> meta_ai) = 0;
		virtual void Update() = 0;
		virtual std::shared_ptr<AiState> NextState() = 0;

		bool IsEnd() { return m_end_flag; }

	protected:
		bool m_end_flag;
	};
}