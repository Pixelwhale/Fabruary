#pragma once
#include <GameObject\AI\CharaAI\ai_state.h>

namespace AI 
{
	class KickComboWeak : public AiState
	{
	public:
		KickComboWeak();
		KickComboWeak(const KickComboWeak&);
		~KickComboWeak();

		virtual void GetBattleInfo(std::shared_ptr<MetaAI> meta_ai);
		virtual void Update(std::shared_ptr<Character::AiController> controller);
		virtual std::shared_ptr<AiState> NextState();

	private:
		enum Combo 
		{
			kPunch1,
			kPunch2,
			kDefence,
			kKick,
			kEnd,
		};

	private:
		Combo combo;
	};
}