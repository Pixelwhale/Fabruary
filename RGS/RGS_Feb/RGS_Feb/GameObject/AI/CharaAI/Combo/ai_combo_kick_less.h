#pragma once
#include <GameObject\AI\CharaAI\ai_state.h>
#include <Device\game_device.h>
#include <Utility\timer.h>

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
		///<summary>�x�����Ԃ����Z�b�g</summary>
		void ResetTimer();

	private:
		enum class Combo 
		{
			kPunch1 = 0,
			kPunch2,
			kDefence,
			kKick,
			kEnd,
		};

	private:
		Combo m_current_combo;			//���݂̒i�K
		Device::Random* m_random;		//�����_��
		Utility::Timer m_timer;			//�x������
	};
}