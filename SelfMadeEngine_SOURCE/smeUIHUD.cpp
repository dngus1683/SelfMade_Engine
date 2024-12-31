#include "smeUIHUD.h"
#include "smeResources.h"

namespace sme
{
	UIHUD::UIHUD()
		: UIBase(enums::eUIType::HpBar)
	{
	}
	UIHUD::~UIHUD()
	{
	}
	void UIHUD::OnInit()
	{
		mTexture = Resources::Find<graphics::Texture>(L"HPBAR"); 
	}
	void UIHUD::OnActive()
	{
	}
	void UIHUD::OnInActive()
	{
	}
	void UIHUD::OnUpdate()
	{
	}
	void UIHUD::OnLateUpdate()
	{
	}
	void UIHUD::OnRender(HDC mHdc)
	{
		TransparentBlt(mHdc
			, 0, 0
			, mTexture->GetWidth()
			, mTexture->GetHeight()
			, mTexture->GetHdc()
			, 0, 0
			, mTexture->GetWidth()
			, mTexture->GetHeight()
			, RGB(255, 0, 255)
		);
	}
	void UIHUD::OnClear()
	{
	}
}