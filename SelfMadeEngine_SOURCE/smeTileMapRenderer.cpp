#include "smeTileMapRenderer.h"
#include "smeGameObject.h"
#include "smeTransform.h"
#include "smeRenderer.h"


namespace sme
{
	Vector2 TileMapRenderer::TileSize = Vector2::One;;

	TileMapRenderer::TileMapRenderer()
		: mTexture(nullptr)
		, mSize(Vector2(3.f, 3.f))
		, Component(enums::eComponentType::SpriteRenderer)
		, mIndex(Vector2::One)
		, mTileSize(16.f, 16.f)
	{
		TileSize = mTileSize * mSize;
	}

	TileMapRenderer::~TileMapRenderer()
	{
	}

	void TileMapRenderer::Initialize()
	{
	}

	void TileMapRenderer::Update()
	{
	}

	void TileMapRenderer::LateUpdate()
	{
	}


	void TileMapRenderer::Render(HDC hdc)
	{
		if (mTexture == nullptr)
		{
			assert(false);
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Vector2 scale = tr->GetScale();
		float rot = tr->GetRotation();

		pos = renderer::mainCamera->CalculatePosition(pos);

		if (mTexture->GetType() == graphics::Texture::eTextureType::Bmp)
		{
			if (mTexture->IsAlpha())
			{
				BLENDFUNCTION func = {};
				func.BlendFlags = 0;
				func.BlendOp = AC_SRC_OVER;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255;
				AlphaBlend(hdc
					, pos.x
					, pos.y
					, TileSize.x * scale.x
					, TileSize.y * scale.y
					, mTexture->GetHdc()
					, mIndex.x * mTileSize.x
					, mIndex.y * mTileSize.y
					, mTileSize.x
					, mTileSize.y
					, func );
			}
			else
			{
				TransparentBlt(hdc
					, pos.x
					, pos.y
					, TileSize.x * scale.x
					, TileSize.y * scale.y
					, mTexture->GetHdc()
					, mIndex.x * mTileSize.x
					, mIndex.y * mTileSize.y
					, mTileSize.x
					, mTileSize.y
					, RGB(255, 0, 255));
			}
		}
	}
}
