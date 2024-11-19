#pragma once
#include "smeCollider.h"

namespace sme
{
	class CircleCollider2D : public Collider
	{
	public:
		CircleCollider2D();
		~CircleCollider2D();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;
	private:
		float mRadius;
	};

}

