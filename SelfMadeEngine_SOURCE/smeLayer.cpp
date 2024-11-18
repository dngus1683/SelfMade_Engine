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

			GameObject::eState state = gameObject->GetState();
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
			gameObject->LateUpdate();
		}
	}
	void Layer::Render(HDC mHdc)
	{
		for (GameObject* gameObject : mGameObjects)
		{
			if (gameObject == nullptr)
				continue;
			gameObject->Render(mHdc);
		}
	}
	void Layer::Destroy()
	{
		for (GameObject* gameObject : mGameObjects)
		{
			if (gameObject == nullptr)
				continue;
		}
		for (std::vector<GameObject*>::iterator iter = mGameObjects.begin(); iter != mGameObjects.end(); )
		{
			GameObject::eState active = (*iter)->GetState();
			if (active == GameObject::eState::Dead)
			{
				GameObject* deathObj = (*iter);
				mGameObjects.erase(iter);

				delete deathObj;
				deathObj = nullptr;

				if (mGameObjects.empty())
					break;
				else
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
}