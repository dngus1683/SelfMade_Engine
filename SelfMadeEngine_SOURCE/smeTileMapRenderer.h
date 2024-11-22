#pragma once

#include "CommonInclude.h"
#include "smeComponent.h"
#include "smeTexture.h"

namespace sme
{
	class TileMapRenderer : public Component
	{
	public:
		TileMapRenderer();
		~TileMapRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTexture(graphics::Texture* texture) { mTexture = texture; }
		void SetIndex(Vector2 InIndex) { mIndex = InIndex; }
		void SetSize(math::Vector2 size) { mSize = size; }
		
		static Vector2 OriginTileSize;
		static Vector2 SelectedIndex;
		static Vector2 TileSize;
	private:

		Vector2 mTileSize;
		graphics::Texture* mTexture;
		math::Vector2 mSize;
		Vector2 mIndex;
	};
}

