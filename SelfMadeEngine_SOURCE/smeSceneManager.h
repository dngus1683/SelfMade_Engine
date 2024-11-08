#pragma once

#include "smeScene.h"

namespace sme
{
	class SceneManager
	{
	public:
		template <typename T> 
		static Scene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			scene->Initialize();

			mScene.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name)
		{
			std::map<std::wstring, Scene*>::iterator iter = mScene.find(name);
			if (iter == mScene.end())
			{
				return nullptr;
			}

			mActiveScene = iter->second;

			return iter->second;
		}

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC mHdc);

	private:
		static std::map<std::wstring, Scene*> mScene;
		// 현재 실행되고 있는 씬
		static Scene* mActiveScene;
	};
}

