#pragma once
#include "CommonInclude.h"
#include "smeUIBase.h"

namespace sme
{
	class UIManager
	{
	public:
		static void Initialize();
		static void OnLoad(enums::eUIType InType);
		static void Update();
		static void LateUpdate();
		static void Render(HDC InHdc);
		static void OnComplete(UIBase* addUI);
		static void OnFail();
		static void Release();

		static void Push(enums::eUIType InType);
		static void Pop(enums::eUIType InType);
	private:
		static std::unordered_map<enums::eUIType, UIBase*> mUIs;
		static std::stack<UIBase*> mUIBases;
		static std::queue<enums::eUIType> mRequestUIQueue;
		static UIBase* mActiveUI;
	};
}