#include "smeSceneManager.h"
#include "smeDontDestroyOnLoad.h"

namespace sme
{
	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;
	Scene* SceneManager::mDontDestroyOnLoad = nullptr;

	std::vector<GameObject*> SceneManager::GetGameObjects(enums::eLayerType layer)
	{
		std::vector<GameObject*> gameObjects = mActiveScene->GetLayer(layer)->GetGameObjects();
		std::vector<GameObject*> dontDestroyOnLoad = mDontDestroyOnLoad->GetLayer(layer)->GetGameObjects();
		
		gameObjects.insert(gameObjects.end(), dontDestroyOnLoad.begin(), dontDestroyOnLoad.end());
		
		return gameObjects;
	}

	void SceneManager::Initialize()
	{
		mDontDestroyOnLoad = CreateScene<DontDestroyOnLoad>(L"DontDestroyOnLoad");
	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
		mDontDestroyOnLoad->Update();
	}

	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
		mDontDestroyOnLoad->LateUpdate();
	}

	void SceneManager::Render(HDC mHdc)
	{
		mActiveScene->Render(mHdc);
		mDontDestroyOnLoad->Render(mHdc);
	}
	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		if (mActiveScene)
			mActiveScene->OnExit();

		std::map<std::wstring, Scene*>::iterator iter
			= mScene.find(name);

		if (iter == mScene.end())
			return nullptr;

		mActiveScene = iter->second;
		mActiveScene->OnEnter();

		return iter->second;
	}
	void SceneManager::Destroy()
	{
		mActiveScene->Destroy();
	}
	void SceneManager::Release()
	{
		for (auto& iter : mScene)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
}

