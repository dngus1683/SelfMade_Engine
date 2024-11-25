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
			mActiveScene = scene;
			scene->Initialize();

			mScene.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name);
		static Scene* GetActiveScene() { return mActiveScene; }
		static Scene* GetDontDestroyOnLoad() { return mDontDestroyOnLoad; }
		static std::map<std::wstring, Scene*> GetmScene() { return mScene; }
		static std::vector<GameObject*> GetGameObjects(enums::eLayerType layer);

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC mHdc);
		static void Destroy();
		static void Release();

	private:
		static std::map<std::wstring, Scene*> mScene;
		// 현재 실행되고 있는 씬
		static Scene* mActiveScene;
		static Scene* mDontDestroyOnLoad;
	};
}

