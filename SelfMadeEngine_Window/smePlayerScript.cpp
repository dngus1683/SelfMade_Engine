#include "smePlayerScript.h"
#include "smeTime.h"
#include "smeInput.h"
#include "smeTransform.h"
#include "smeGameObject.h"
#include "smeAnimator.h"

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
		int a = 0;
	}
	void PlayerScript::idle()
	{
		if (Input::GetKey(eKeyCode::LButton))
		{
			mState = PlayerScript::eState::GiveWater;
			mAnimator->PlayAnimation(L"FrontGiveWater", false);

			Vector2 mousePos = Input::GetMousePosition();
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