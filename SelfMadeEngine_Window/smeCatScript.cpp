#include "smeCatScript.h"
#include "smeTime.h"
#include "smeInput.h"
#include "smeTransform.h"
#include "smeGameObject.h"
#include "smeAnimator.h"

namespace sme
{
	CatScript::CatScript()
		: mState(CatScript::eState::SitDown)
		, mAnimator(nullptr)
		, mTime(0.f)
	{
	}
	CatScript::~CatScript()
	{
	}
	void CatScript::Initialize()
	{
	}
	void CatScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case eState::SitDown:
		{
			sitDown();
		}
		break;
		case eState::Attack:
		{

		}
		break;
		case eState::LayDown:
		{
			LayDown();
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
	void CatScript::LateUpdate()
	{
	}
	void CatScript::Render(HDC hdc)
	{
	}
	void CatScript::sitDown()
	{		
		mTime += Time::DeltaTime();

		if (mTime > 3.f)
		{
			mState = CatScript::eState::Walk;
			int direction = rand() % 4;
			mDirection = (eDirection)direction;

			playWalkAnimationByDirection(mDirection);
			mTime = 0.f;
		}
	}
	void CatScript::move()
	{
		mTime += Time::DeltaTime();

		if (mTime > 2.f)
		{
			int isLayDown = rand() % 2;
			if (isLayDown)
			{
				mState = CatScript::eState::LayDown;
				mAnimator->PlayAnimation(L"LayDown", false);
			}
			else
			{
				mState = CatScript::eState::SitDown;
				mAnimator->PlayAnimation(L"SitDown", false);
			}
			mTime = 0.f;
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();

		translate(tr);
	}
	void CatScript::LayDown()
	{

	}
	void CatScript::playWalkAnimationByDirection(eDirection dir)
	{
		switch (dir)
		{
		case sme::CatScript::eDirection::Left:
			mAnimator->PlayAnimation(L"LeftWalk", true);
			break;
		case sme::CatScript::eDirection::Right:
			mAnimator->PlayAnimation(L"RightWalk", true);
			break;
		case sme::CatScript::eDirection::Down:
			mAnimator->PlayAnimation(L"DownWalk", true);
			break;
		case sme::CatScript::eDirection::Up:
			mAnimator->PlayAnimation(L"UpWalk", true);
			break;
		default:
			assert(false);
			break;
		}

	}
	void CatScript::translate(Transform* tr)
	{
		Vector2 pos = tr->GetPosition();

		switch (mDirection)
		{
		case sme::CatScript::eDirection::Left:
			pos.x -= 100.f * Time::DeltaTime();
			break;
		case sme::CatScript::eDirection::Right:
			pos.x += 100.f * Time::DeltaTime();
			break;
		case sme::CatScript::eDirection::Down:
			pos.y += 100.f * Time::DeltaTime();
			break;
		case sme::CatScript::eDirection::Up:
			pos.y -= 100.f * Time::DeltaTime();
			break;
		default:
			break;
		}

		tr->SetPosition(pos);
		
	}
}