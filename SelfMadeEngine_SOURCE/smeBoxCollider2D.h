#pragma once
#include "smeCollider.h"

namespace sme
{
	class BoxCollider2D : public Collider
	{
	public:
		BoxCollider2D();
		~BoxCollider2D();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;
	private:
		Vector2 mSize;
	};

}

