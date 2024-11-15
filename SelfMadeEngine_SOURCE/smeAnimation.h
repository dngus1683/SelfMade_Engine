#pragma once

#include "smeResource.h"
#include "smeTexture.h"

namespace sme
{
	class Animation : public Resource
	{
	public:
		struct Sprite
		{
			Vector2 leftTop;
			Vector2 size;
			Vector2 offset;
			float duration;

			Sprite()
				: leftTop(Vector2::Zero)
				, size(Vector2::Zero)
				, offset(Vector2::Zero)
				, duration(0.f)
			{
			}
		};

		Animation();
		~Animation();

		void Update();
		void Render(HDC hdc);

		HRESULT Load(const std::wstring& path) override;

		void CreateAnimation(const std::wstring& name
			, graphics::Texture* spriteSheet
			, Vector2 leftTop
			, Vector2 offset
			, Vector2 size
			, UINT spriteLength
			, float duration);

		void Reset();
		bool IsComplete() { return mbComplete; }
		void SetAnimator(class Animator* animator) { mAnimator = animator; }

	private:
		class Animator* mAnimator;
		graphics::Texture* mTexture;

		std::vector<Sprite> mAnimationSheet;
		int mIndex;
		float mTime;
		bool mbComplete;

	};

}

