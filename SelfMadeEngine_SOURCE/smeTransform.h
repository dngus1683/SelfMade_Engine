#pragma once

#include "smeComponent.h"

namespace sme
{
	using namespace math;
	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPosition(Vector2 pos) { mPosition.x = pos.x; mPosition.y = pos.y; }
		void SetRotation(float rot) { mRotation = rot; }
		void SetScale(Vector2 scale) { mScale.x = scale.x; mScale.y = scale.y; }

		Vector2 GetPosition() const { return mPosition; }
		float GetRotation() const { return mRotation; }
		Vector2 GetScale() const { return mScale; }

	private:
		float mRotation;
		Vector2 mScale;
		Vector2 mPosition;
	};
}

