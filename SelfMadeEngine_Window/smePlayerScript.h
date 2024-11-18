#pragma once

#include "../SelfMadeEngine_SOURCE/smeScript.h"

namespace sme
{
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			Idle,
			Walk,
			Sleep,
			GiveWater,
			Attack,
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void AttackEffect();

	private:
		void idle();
		void move();
		void giveWater();
	private:
		eState mState;
		class Animator* mAnimator;


	};
}

