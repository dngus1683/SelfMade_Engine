#include "smePlayerScript.h"
#include "smeTime.h"
#include "smeInput.h"
#include "smeTransform.h"
#include "smeGameObject.h"
#include "smeAnimator.h"
#include "smeCat.h"
#include "smeCatScript.h"
#include "smeObject.h"
#include "smeResources.h"

namespace sme
{
	PlayerScript::PlayerScript()
		: mState(PlayerScript::eState::Idle)
		, mAnimator(nullptr)
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{
	}
	void PlayerScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case eState::Idle:
		{
			idle();
		}
		break;
		case eState::Attack:
		{

		}
		break;
		case eState::Sleep:
		{

		}
		break;
		case eState::GiveWater:
		{
			giveWater();
		}
		break;
		case eState::Walk:
		{
			move();
		}
		break;
		default:
			break;

		}
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
	void PlayerScript::AttackEffect()
	{
		
	}
	void PlayerScript::idle()
	{
		if (Input::GetKey(eKeyCode::LButton))
		{

			Cat* cat = Instantiate<Cat>(enums::eLayerType::Animal);
			CatScript* catSrc = cat->AddComponent<CatScript>();

			catSrc->SetPlayer(GetOwner());

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

			Transform* tr = GetOwner()->GetComponent<Transform>();
			cat->GetComponent<Transform>()->SetPosition(tr->GetPosition());

			Vector2 mousePos = Input::GetMousePosition();
			catSrc->mDest = mousePos;
		}

		if (Input::GetKey(eKeyCode::RIGHT))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"RightWalk"); 
		}
		if (Input::GetKey(eKeyCode::LEFT))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"LeftWalk");
		}
		if (Input::GetKey(eKeyCode::UP))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"UpWalk");
		}
		if (Input::GetKey(eKeyCode::DOWN))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"DownWalk");
		}
	}
	void PlayerScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::RIGHT))
		{
			pos.x += 100.f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::LEFT))
		{
			pos.x -= 100.f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::UP))
		{
			pos.y -= 100.f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::DOWN))
		{
			pos.y += 100.f * Time::DeltaTime();
		}

		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::RIGHT) || Input::GetKeyUp(eKeyCode::LEFT)
			|| Input::GetKeyUp(eKeyCode::UP) || Input::GetKeyUp(eKeyCode::DOWN))
		{
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"SitDown", false);
		}
	}
	void PlayerScript::giveWater()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"Idle", false);
		}
	}
}