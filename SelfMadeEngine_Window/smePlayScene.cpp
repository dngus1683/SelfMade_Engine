#include "smePlayScene.h"
#include "smeGameObject.h"
#include "smeTransform.h"
#include "smeSpriteRenderer.h"
#include "smePlayer.h"
#include "smeShape.h"

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

		Player* bg = new Player();
		
		Transform* tr = bg->AddComponent<Transform>();
		tr->SetPos(Vector2(0.f, 0.f));
		tr->SetName(L"TR");
		
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"D:/Study/SelfMadeEngine/ImageSource/CloudOcean.png");

		AddGameObject(bg);
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