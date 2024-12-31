#pragma once
#include "smeUIBase.h"
#include "smeTexture.h"

namespace sme
{
	class UIHUD : public UIBase
	{
	public:
		UIHUD();
		~UIHUD();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnUpdate() override;
		virtual void OnLateUpdate() override;
		virtual void OnRender(HDC mHdc) override;
		virtual void OnClear() override;

	private:
		graphics::Texture* mTexture;
	};
}