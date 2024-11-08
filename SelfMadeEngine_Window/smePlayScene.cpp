#include "smePlayScene.h"
#include "smeGameObject.h"

namespace sme
{
	PlayScene::PlayScene()
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		GameObject* obj = new GameObject();
		AddGameObject(obj);
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void PlayScene::Render(HDC mHdc)
	{
		Scene::Render(mHdc);
	}

}