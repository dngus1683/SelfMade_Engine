#include "smeLayer.h"


namespace sme
{
	Layer::Layer()
		: mType(eLayerType::None)
		, mGameObjects{}
	{

	}
	Layer::~Layer()
	{

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
	void Layer::AddGameObject(GameObject* gameObject)
	{
		mGameObjects.push_back(gameObject);
	}
}