#include "smeLayer.h"


namespace sme
{
	Layer::Layer()
		: mType(enums::eLayerType::None)
		, mGameObjects{}
	{

	}
	Layer::~Layer()
	{
		for (auto iter : mGameObjects)
		{
			if (iter == nullptr)
				continue;
			delete iter;
			iter = nullptr;
		}
	}
	void Layer::Initialize()
	{
		for (GameObject* gameObject : mGameObjects)
		{
			if (gameObject == nullptr)
				continue;
			gameObject->Initialize();
		}
	}
	void Layer::Update()
	{
		for (GameObject* gameObject : mGameObjects)
		{
			if (gameObject == nullptr)
				continue;

			GameObject::eState state = gameObject->GetActive();
			if (state == GameObject::eState::Paused || state == GameObject::eState::Dead)
			{
				continue;
			}

			gameObject->Update();
		}
	}
	void Layer::LateUpdate()
	{
		for (GameObject* gameObject : mGameObjects)
		{
			if (gameObject == nullptr)
				continue;

			GameObject::eState state = gameObject->GetActive();
			if (state == GameObject::eState::Paused || state == GameObject::eState::Dead)
			{
				continue;
			}

			gameObject->LateUpdate();
		}
	}
	void Layer::Render(HDC mHdc)
	{
		for (GameObject* gameObject : mGameObjects)
		{
			if (gameObject == nullptr)
				continue;
			
			GameObject::eState state = gameObject->GetActive();
			if (state == GameObject::eState::Paused || state == GameObject::eState::Dead)
			{
				continue;
			}

			gameObject->Render(mHdc);
		}
	}
	void Layer::Destroy()
	{
		for (std::vector<GameObject*>::iterator iter = mGameObjects.begin(); iter != mGameObjects.end(); )
		{
			GameObject::eState active = (*iter)->GetActive();
			if (active == GameObject::eState::Dead)
			{
				GameObject* deathObj = (*iter);
				iter = mGameObjects.erase(iter);

				delete deathObj;
				deathObj = nullptr;

				continue;
			}

			iter++;
		}

	}
	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;

		mGameObjects.push_back(gameObject);
	}
	void Layer::EraseGameObject(GameObject* eraseGameObject)
	{
		std::erase_if(mGameObjects,
			[=](GameObject* gameObj)
			{
				return gameObj == eraseGameObject;
			});
	}
}