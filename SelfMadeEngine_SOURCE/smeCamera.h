#pragma once

#include "smeComponent.h"

namespace sme
{
	using namespace math;
	class Camera : public Component
	{
	public:
		Vector2 CalculatePosition(Vector2 pos) { return pos - mDistance; };
		
		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTarget(GameObject* InTarget) { mTarget = InTarget; }

	private:
		Vector2 mDistance;
		Vector2 mResolution;
		Vector2 mLookPosition;
		class GameObject* mTarget;

	};
}

