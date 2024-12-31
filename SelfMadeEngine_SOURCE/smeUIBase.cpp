#include "smeUIBase.h"

namespace sme
{
	UIBase::UIBase(enums::eUIType type)
		: mType(type)
	{
	}
	UIBase::~UIBase()
	{
	}
	void UIBase::Initialize()
	{
		OnInit();
	}
	void UIBase::Active()
	{
		mbEnabled = true;
		OnActive();
	}
	void UIBase::InActive()
	{
		mbEnabled = false;
		OnInActive();
	}
	void UIBase::Update()
	{
		if (mbEnabled)
		{
			OnUpdate();
		}
	}
	void UIBase::LateUpdate()
	{
	}
	void UIBase::Render(HDC mHdc)
	{
	}
	void UIBase::UIClear()
	{
		OnClear();
	}
	void UIBase::OnInit()
	{
	}
	void UIBase::OnActive()
	{
	}
	void UIBase::OnInActive()
	{
	}
	void UIBase::OnUpdate()
	{
	}
	void UIBase::OnLateUpdate()
	{
	}
	void UIBase::OnRender(HDC mHdc)
	{
	}
	void UIBase::OnClear()
	{
	}
}
