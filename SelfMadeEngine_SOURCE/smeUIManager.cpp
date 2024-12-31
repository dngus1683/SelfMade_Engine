#include "smeUIManager.h"

namespace sme
{
	std::unordered_map<enums::eUIType, UIBase*> UIManager::mUIs = {};
	std::stack<UIBase*> UIManager::mUIBases = {};
	std::queue<enums::eUIType> UIManager::mRequestUIQueue = {};
	UIBase* UIManager::mActiveUI = nullptr;

	void UIManager::Initialize()
	{
		
	}
	void UIManager::OnLoad(enums::eUIType InType)
	{
		std::unordered_map<enums::eUIType, UIBase*>::iterator iter = mUIs.find(InType);

		if (iter == mUIs.end())
		{
			OnFail();
			return;
		}

		OnComplete(iter->second);
	}
	void UIManager::Update()
	{
		std::stack<UIBase*> uiBases = mUIBases;
		while (!uiBases.empty())
		{
			UIBase* uiBase = uiBases.top();
			if (uiBase)
			{
				uiBase->Update();
				uiBases.pop();
			}
		}


		if (mRequestUIQueue.size() > 0)
		{
			enums::eUIType requestUI = mRequestUIQueue.front();
			mRequestUIQueue.pop();
			OnLoad(requestUI);
		}
	}
	void UIManager::LateUpdate()
	{
		std::stack<UIBase*> uiBases = mUIBases;
		while (!uiBases.empty())
		{
			UIBase* uiBase = uiBases.top();
			if (uiBase)
			{
				uiBase->LateUpdate();
				uiBases.pop();
			}
		}
	}
	void UIManager::Render(HDC InHdc)
	{
		std::stack<UIBase*> uiBases = mUIBases;
		while (!uiBases.empty())
		{
			UIBase* uiBase = uiBases.top();
			if (uiBase)
			{
				uiBase->Render(InHdc);
				uiBases.pop();
			}
		}
	}
	void UIManager::OnComplete(UIBase* addUI)
	{
		if (addUI == nullptr)
		{
			return;
		}

		addUI->Initialize();
		addUI->Active();
		addUI->Update();

		if (addUI->IsFullScreen())
		{
			std::stack<UIBase*> uiBases = mUIBases;
			while (!uiBases.empty())
			{
				UIBase* uiBase = uiBases.top();
				uiBases.pop();
				if (uiBase)
				{
					uiBase->InActive();
				}
			}
		}

		mUIBases.push(addUI);
		mActiveUI = nullptr;
	}
	void UIManager::OnFail()
	{
		mActiveUI = nullptr;
	}
	void UIManager::Release()
	{
		for (auto iter : mUIs)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
	void UIManager::Push(enums::eUIType InType)
	{
		mRequestUIQueue.push(InType);
	}
	void UIManager::Pop(enums::eUIType InType)
	{
		if (mUIBases.size() <= 0)
		{
			return;
		}

		std::stack<UIBase*> tempStack;

		UIBase* uibase = nullptr;
		while (mUIBases.size() > 0)
		{
			uibase = mUIBases.top();
			mUIBases.pop();

			if (uibase->GetType() != InType)
			{
				tempStack.push(uibase);
				continue;
			}

			if (uibase->IsFullScreen())
			{
				std::stack<UIBase*> uiBases = mUIBases;
				while (!uiBases.empty())
				{
					UIBase* uiBase = uiBases.top();
					uiBases.pop();
					if (uiBase)
					{
						uiBase->Active();
						break; 
					}
				}
			}
			uibase->UIClear();
		}

		while (tempStack.size() > 0)
		{
			uibase = tempStack.top();
			tempStack.pop();
			mUIBases.push(uibase);
		}
	}
}
