#pragma once

#include "CommonInclude.h"
#include "smeComponent.h"
#include "smeTexture.h"

namespace sme
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTexture(graphics::Texture* texture) { mTexture = texture; }
		void SetSize(math::Vector2 size) { mSize = size; }

	private:
		graphics::Texture* mTexture;
		math::Vector2 mSize;
	};
}

