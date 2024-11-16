#include "smeSpriteRenderer.h"
#include "smeGameObject.h"
#include "smeTransform.h"
#include "smeRenderer.h"

sme::SpriteRenderer::SpriteRenderer()
	: mTexture(nullptr)
	, mSize(Vector2::One)
	, Component(enums::eComponentType::SpriteRenderer)
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
	Vector2 scale = tr->GetScale();
	float rot = tr->GetRotation();

	pos = renderer::mainCamera->CalculatePosition(pos);

	if (mTexture->GetType() == graphics::Texture::eTextureType::Bmp)
	{

		TransparentBlt(hdc, pos.x, pos.y
			, mTexture->GetWidth() * mSize.x * scale.x, mTexture->GetHeight() * mSize.y * scale.y
			, mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight()
			, RGB(255, 0, 255));
	}
	else if (mTexture->GetType() == graphics::Texture::eTextureType::Png)
	{
		Gdiplus::ImageAttributes imgAtt = {};
		imgAtt.SetColorKey(Gdiplus::Color(100, 100, 100), Gdiplus::Color(255, 255, 255));

		Gdiplus::Graphics graphics(hdc);
		
		graphics.TranslateTransform(pos.x, pos.y);
		graphics.RotateTransform(rot);
		graphics.TranslateTransform(-pos.x, -pos.y);

		graphics.DrawImage(mTexture->GetImage(),
			Gdiplus::Rect
			(
				pos.x
				, pos.y
				, mTexture->GetWidth() * mSize.x * scale.x
				, mTexture->GetHeight() * mSize.y * scale.y
			)
			, 0, 0
			, mTexture->GetWidth(), mTexture->GetHeight()
			, Gdiplus::UnitPixel
			, nullptr
		);
	}
}

