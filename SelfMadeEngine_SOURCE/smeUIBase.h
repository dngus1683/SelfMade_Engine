#pragma once
#include "CommonInclude.h"
#include "smeEntity.h"

namespace sme
{
	class UIBase
	{
	public:
		UIBase(enums::eUIType type);
		~UIBase();
		
		void Initialize();
		void Active();
		void InActive();
		void Update();
		void LateUpdate();
		void Render(HDC mHdc);
		void UIClear();

		virtual void OnInit();
		virtual void OnActive();
		virtual void OnInActive();
		virtual void OnUpdate();
		virtual void OnLateUpdate();
		virtual void OnRender(HDC mHdc);
		virtual void OnClear();

		enums::eUIType GetType() { return mType; }
		void SetFullScreen(bool enable) { mbFullScreen == enable; }
		bool IsFullScreen() { return mbFullScreen; }
	private:
		enums::eUIType mType;
		bool mbFullScreen;
		bool mbEnabled;

	};

}
