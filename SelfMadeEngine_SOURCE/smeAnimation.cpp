#include "smeAnimation.h"
#include "smeTime.h"
#include "smeTransform.h"
#include "smeGameObject.h"
#include "smeAnimator.h"
#include "smeRenderer.h"

namespace sme
{
	Animation::Animation()
		: Resource(enums::eResourceType::Animation)
		, mAnimator(nullptr)
		, mTexture(nullptr)
		, mAnimationSheet{}
		, mIndex(-1)
		, mTime(0.f)
		, mbComplete(false)
	{
	}
	Animation::~Animation()
	{
	}
	void Animation::Update()
	{
		if (mbComplete)
			return;

		mTime += Time::DeltaTime();
		
		if (mAnimationSheet[mIndex].duration < mTime)
		{
			mTime = 0.f;
			if (mIndex < mAnimationSheet.size()-1)
			{
				mIndex++;
			}
			else
			{
				mbComplete = true;
			}
		}
	}
	void Animation::Render(HDC hdc)
	{
		// 알파블렌드 쓸 수 있는 조건 -> 해당 이미지 알파 채널이 있어야 한다.
		
		if (mTexture == nullptr)
		{
			return;
		}

		// 게임 오브젝트 불러오기.
		GameObject* gameObj = mAnimator->GetOwner();
		Transform* tr = gameObj->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Vector2 scale = tr->GetScale();
		float rot = tr->GetRotation();

		// 메인 카메라가 있다면 해당 카메라에 대한 좌표 계산.
		if (renderer::mainCamera)
		{
			pos = renderer::mainCamera->CalculatePosition(pos);
		}

		graphics::Texture::eTextureType type = mTexture->GetType();
		Sprite sprite = mAnimationSheet[mIndex];
		if (type == graphics::Texture::eTextureType::Bmp)
		{
			HDC imgHdc = mTexture->GetHdc();

			if (mTexture->IsAlpha())
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

				AlphaBlend(hdc
					, pos.x - (sprite.size.x / 2.f) + sprite.offset.x
					, pos.y - (sprite.size.y / 2.f) + sprite.offset.y
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
					, imgHdc
					, sprite.leftTop.x
					, sprite.leftTop.y
					, sprite.size.x
					, sprite.size.y
					, func);
			}
			else
			{
				TransparentBlt(hdc
					, pos.x - (sprite.size.x / 2.f) + sprite.offset.x
					, pos.y - (sprite.size.y / 2.f) + sprite.offset.y
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
					, imgHdc
					, sprite.leftTop.x
					, sprite.leftTop.y
					, sprite.size.x
					, sprite.size.y
					, RGB(255,0,255));
			}

		}
		else if (type == graphics::Texture::eTextureType::Png)
		{
			// 내가 원하는 픽셀을 투명화 시킬 때
			Gdiplus::ImageAttributes imgAtt = {};

			// 투명화 시킬 픽셀의 색 범위
			imgAtt.SetColorKey(Gdiplus::Color(100, 100, 100), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(hdc);

			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-pos.x, -pos.y);

			graphics.DrawImage(mTexture->GetImage(),
				Gdiplus::Rect
				(
					pos.x - (sprite.size.x / 2.f) + sprite.offset.x
					, pos.y - (sprite.size.y / 2.f) + sprite.offset.y
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
				)
				, sprite.leftTop.x
				, sprite.leftTop.y
				, sprite.size.x
				, sprite.size.y
				, Gdiplus::UnitPixel
				, nullptr
			);
		}
		 
	}
	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}
	void Animation::CreateAnimation(const std::wstring& name, graphics::Texture* spriteSheet
		, Vector2 leftTop, Vector2 offset, Vector2 size, UINT spriteLength, float duration)
	{
		mTexture = spriteSheet;
		for (size_t i = 0; i < spriteLength; i++)
		{
			Sprite sprite = {};
			sprite.leftTop.x = leftTop.x + (size.x * i);
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			mAnimationSheet.push_back(sprite);
		}
	}
	void Animation::Reset()
	{
		mTime = 0.f;
		mIndex = 0;
		mbComplete = false;
	}
}