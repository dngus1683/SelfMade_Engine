#pragma once

#include "smeLayer.h"
#include "smeComponent.h"
#include "smeScene.h"
#include "smeSceneManager.h"
#include "smeGameObject.h"
#include "smeTransform.h"


namespace sme
{
	template<typename T>
	static T* Instantiate(sme::eLayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template<typename T>
	static T* Instantiate(sme::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPos(position);

		return gameObject;
	}
}