#include "smeSpriteRenderer.h"
#include "smeGameObject.h"
#include "smeTransform.h"
#include "smeShape.h"

sme::SpriteRenderer::SpriteRenderer()
	: mTexture(nullptr)
	, mSize(Vector2::One)
{
}

sme::SpriteRenderer::~SpriteRenderer()
{
}

void sme::SpriteRenderer::Initialize()
{
}

void sme::SpriteRenderer::Update()
{
}

void sme::SpriteRenderer::LateUpdate()
{
}

void sme::SpriteRenderer::Render(HDC hdc)
{
	if (mTexture == nullptr)
	{
		assert(false);
	}

	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetPosition();

	if (mTexture->GetType() == graphics::Texture::eTextureType::Bmp)
	{
		TransparentBlt(hdc, pos.x, pos.y
			, mTexture->GetWidth(), mTexture->GetHeight()
			, mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight()
			, RGB(255, 0, 255));
	}
	else if (mTexture->GetType() == graphics::Texture::eTextureType::Png)
	{
		Gdiplus::Graphics graphics(hdc);
		graphics.DrawImage(mTexture->GetImage(),
			Gdiplus::Rect(pos.x, pos.y
				, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y));
	}
}

