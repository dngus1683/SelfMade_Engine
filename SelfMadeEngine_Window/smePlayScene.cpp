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
		// main camera
		GameObject* camera = Instantiate<GameObject>(enums::eLayerType::None, Vector2(336.f, 423.f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;



		// 플레이어
		mPlayer = Instantiate<Player>(enums::eLayerType::Player);
		PlayerScript* plScript = mPlayer->AddComponent<PlayerScript>(); 

		cameraComp->SetTarget(mPlayer);

		graphics::Texture* playerTexture = Resources::Find<graphics::Texture>(L"Player");
		Animator* playerAnimator = mPlayer->AddComponent<Animator>();
		playerAnimator->CreateAnimation(L"Idle", playerTexture
			, Vector2(2000.f, 250.f), Vector2::Zero, Vector2(250.f, 250.f), 1, 0.1f);
		playerAnimator->CreateAnimation(L"FrontGiveWater", playerTexture
			, Vector2(0.f, 2000.f), Vector2::Zero, Vector2(250.f, 250.f), 12, 0.1f);
	
		playerAnimator->PlayAnimation(L"Idle", false);

		playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::AttackEffect, plScript);

		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(100.f, 100.f));




		// 고양이
		Cat* cat = Instantiate<Cat>(enums::eLayerType::Animal);
		cat->AddComponent<CatScript>();

		graphics::Texture* catTexture = Resources::Find<graphics::Texture>(L"Chickhen");
		Animator* catAnimator = cat->AddComponent<Animator>();
		catAnimator->CreateAnimation(L"DownWalk", catTexture
			, Vector2(0.f, 0.f), Vector2::Zero, Vector2(32.f, 32.f), 4, 0.1f);
		catAnimator->CreateAnimation(L"RightWalk", catTexture
			, Vector2(0.f, 32.f), Vector2::Zero, Vector2(32.f, 32.f), 4, 0.1f);
		catAnimator->CreateAnimation(L"UpWalk", catTexture
			, Vector2(0.f, 64.f), Vector2::Zero, Vector2(32.f, 32.f), 4, 0.1f);
		catAnimator->CreateAnimation(L"LeftWalk", catTexture
			, Vector2(0.f, 96.f), Vector2::Zero, Vector2(32.f, 32.f), 4, 0.1f);
		catAnimator->CreateAnimation(L"SitDown", catTexture
			, Vector2(0.f, 128.f), Vector2::Zero, Vector2(32.f, 32.f), 4, 0.1f);
		catAnimator->CreateAnimation(L"Grooming", catTexture
			, Vector2(0.f, 160.f), Vector2::Zero, Vector2(32.f, 32.f), 4, 0.1f);
		catAnimator->CreateAnimation(L"LayDown", catTexture
			, Vector2(0.f, 192.f), Vector2::Zero, Vector2(32.f, 32.f), 4, 0.1f);

		catAnimator->PlayAnimation(L"SitDown", false);

		cat->GetComponent<Transform>()->SetPosition(Vector2(250.f, 100.f));
		cat->GetComponent<Transform>()->SetRotation(180.f);
		cat->GetComponent<Transform>()->SetScale(Vector2(1.f, 1.f));





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