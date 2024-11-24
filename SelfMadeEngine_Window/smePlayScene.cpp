#include "smePlayScene.h"
#include "smeGameObject.h"
#include "smeTransform.h"
#include "smeSpriteRenderer.h"
#include "smePlayer.h"
#include "smeInput.h"
#include "smeTitleScene.h"
#include "smeSceneManager.h"
#include "smeObject.h"
#include "smeTexture.h"
#include "smeResources.h"
#include "smePlayerScript.h"
#include "smeCamera.h"
#include "smeRenderer.h"
#include "smeAnimator.h"
#include "smeCat.h"
#include "smeCatScript.h"
#include "smeBoxCollider2D.h"
#include "smeCollisionManager.h"
#include "smeCircleCollider2D.h"
#include "smeTile.h"
#include "smeTileMapRenderer.h"

namespace sme
{
	PlayScene::PlayScene()
		: mPlayer(nullptr)
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		FILE* pFile = nullptr;
		_wfopen_s(&pFile, L"..\\test", L"rb");

		while (true)
		{
			int idxX = 0;
			int idxY = 0;
			int posX = 0;
			int posY = 0;

			if (fread(&idxX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&idxY, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posY, sizeof(int), 1, pFile) == NULL)
				break;


			Tile* tile = Instantiate<Tile>(enums::eLayerType::Tile, Vector2(posX, posY));
			TileMapRenderer* tmr = tile->AddComponent<TileMapRenderer>();
			tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));
			tmr->SetIndex(Vector2(idxX, idxY));

		}
		fclose(pFile);

		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Animal, true);
	
		// main camera
		GameObject* camera = Instantiate<GameObject>(enums::eLayerType::None, Vector2(336.f, 423.f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;



		// 플레이어
		mPlayer = Instantiate<Player>(enums::eLayerType::Player);
		DontDestroyOnLoad(mPlayer);

		PlayerScript* plScript = mPlayer->AddComponent<PlayerScript>(); 

		CircleCollider2D* plCircleCol = mPlayer->AddComponent<CircleCollider2D>();
		plCircleCol->SetOffset(Vector2(-50.f, -50.f));

		//cameraComp->SetTarget(mPlayer);

		graphics::Texture* playerTexture = Resources::Find<graphics::Texture>(L"Player");
		Animator* playerAnimator = mPlayer->AddComponent<Animator>();
		playerAnimator->CreateAnimation(L"Idle", playerTexture
			, Vector2(2000.f, 250.f), Vector2::Zero, Vector2(250.f, 250.f), 1, 0.1f);
		playerAnimator->CreateAnimation(L"FrontGiveWater", playerTexture
			, Vector2(0.f, 2000.f), Vector2::Zero, Vector2(250.f, 250.f), 12, 0.1f);
	
		playerAnimator->PlayAnimation(L"Idle", false);

		playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::AttackEffect, plScript);

		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(350.f, 300.f));



		// 주황버섯
		GameObject* mushroom = Instantiate<Cat>(enums::eLayerType::Animal);
		CatScript* mushroomScript = mushroom->AddComponent<CatScript>();
		CircleCollider2D* mushroomCircleCol = mushroom->AddComponent<CircleCollider2D>();
		mushroomCircleCol->SetOffset(Vector2(-50.f, -50.f));
		Animator* mushroomAnimator = mushroom->AddComponent<Animator>();
		mushroomAnimator->SetName(L"mushroom");
		mushroomAnimator->CreateAnimationByFolder(L"MushroomIdle"
			, L"D:\\Study\\SelfMadeEngine\\ImageSource\\Mushroom"
			, Vector2::Zero
			, 0.1f);

		mushroomAnimator->PlayAnimation(L"MushroomIdle");
		mushroom->GetComponent<Transform>()->SetPosition(Vector2(100.f, 200.f));

		


		// 배경
		/*GameObject* bg = Instantiate<GameObject>(enums::eLayerType::BackGroud, Vector2(0.f, 0.f));
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetName(L"SR");
		bgsr->SetTexture(Resources::Find<graphics::Texture>(L"BG"));*/

	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}

	}

	void PlayScene::Render(HDC mHdc)
	{
		Scene::Render(mHdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(mHdc, 0, 0, str, wcsnlen_s(str, 50));
	}

	void PlayScene::OnEnter()
	{
	}

	void PlayScene::OnExit()
	{
		/*
		Transform* tr = mPlayer->GetComponent<Transform>();
		tr->SetPosition(Vector2(0.f, 0.f));
		*/
	}

}