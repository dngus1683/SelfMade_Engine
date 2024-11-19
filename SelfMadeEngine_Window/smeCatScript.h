#pragma once

#include "../SelfMadeEngine_SOURCE/smeScript.h"
#include "smeTransform.h"

namespace sme
{
	class CatScript : public Script
	{
	public:
		enum class eState
		{
			SitDown,
			Walk,
			Sleep,
			LayDown,
			Attack,
		};
		enum class eDirection
		{
			Left,
			Right,
			Down,
			Up,
			End,
		};

		CatScript();
		~CatScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		void SetPlayer(GameObject* player) { mPlayer = player; }
		Vector2 mDest;

	private:
		void sitDown();
		void move();
		void LayDown();
		void playWalkAnimationByDirection(eDirection dir);
		void translate(Transform* tr);
	private:
		eState mState;
		eDirection mDirection;
		class Animator* mAnimator;
		float mTime;
		float mDeathTime;
		GameObject* mPlayer;
		float mRad;
	};
}

