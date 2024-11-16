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
		// camera->AddComponent<PlayerScript>();


		mPlayer = Instantiate<Player>(enums::eLayerType::Player);
		mPlayer->AddComponent<PlayerScript>(); 


		//graphics::Texture* chickhenTexture = Resources::Find<graphics::Texture>(L"SkillEffect");
		//Animator* animator = mPlayer->AddComponent<Animator>();
		//animator->CreateAnimation(L"ChickhenMove", chickhenTexture
		//	, Vector2(0.f, 0.f), Vector2::Zero, Vector2(602.f, 368.f), 8, 0.1f);

		//animator->PlayAnimation(L"ChickhenMove", true);

		graphics::Texture* chickhenTexture = Resources::Find<graphics::Texture>(L"Chickhen");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"DownWalk", chickhenTexture
			, Vector2(0.f, 0.f), Vector2::Zero, Vector2(32.f, 32.f),4, 0.1f);
		animator->CreateAnimation(L"RightWalk", chickhenTexture
			, Vector2(0.f, 32.f), Vector2::Zero, Vector2(32.f, 32.f), 4, 0.1f);
		animator->CreateAnimation(L"UpWalk", chickhenTexture
			, Vector2(0.f, 64.f), Vector2::Zero, Vector2(32.f, 32.f), 4, 0.1f);
		animator->CreateAnimation(L"LeftWalk", chickhenTexture
			, Vector2(0.f, 96.f), Vector2::Zero, Vector2(32.f, 32.f), 4, 0.1f);
		animator->CreateAnimation(L"SitDown", chickhenTexture
			, Vector2(0.f, 128.f), Vector2::Zero, Vector2(32.f, 32.f), 4, 0.1f);
		animator->CreateAnimation(L"Grooming", chickhenTexture
			, Vector2(0.f, 160.f), Vector2::Zero, Vector2(32.f, 32.f), 4, 0.1f);


		animator->PlayAnimation(L"SitDown", false);


		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(100.f, 100.f));
		mPlayer->GetComponent<Transform>()->SetRotation(180.f);
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(1.f, 1.f));

		GameObject* bg = Instantiate<GameObject>(enums::eLayerType::BackGroud, Vector2(0.f, 0.f));
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetName(L"SR");
		bgsr->SetTexture(Resources::Find<graphics::Texture>(L"BG"));

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