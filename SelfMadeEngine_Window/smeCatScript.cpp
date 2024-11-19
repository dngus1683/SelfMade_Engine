#include "smeCatScript.h"
#include "smeTime.h"
#include "smeInput.h"
#include "smeTransform.h"
#include "smeGameObject.h"
#include "smeAnimator.h"
#include "smeObject.h"

namespace sme
{
	CatScript::CatScript()
		: mState(CatScript::eState::SitDown)
		, mAnimator(nullptr)
		, mTime(0.f)
		, mDeathTime(0.f)
		, mDest(Vector2::Zero)
		, mRad(0.f)
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
		mDeathTime += Time::DeltaTime();

		if (mDeathTime > 6.f)
		{
			Destroy(GetOwner());	
		}

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

		if (mTime > 2.f)
		{
			//Destroy(GetOwner());
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		
		// 마우스 위치로의 이동 (벡터의 뺄셈 활용).
		/*Transform* plTr = mPlayer->GetComponent<Transform>();
		Vector2 dest = mDest - plTr->GetPosition();
		pos += dest.normalize() * (100.f * Time::DeltaTime());*/

		// 삼각함수를 통한 이동.
		//mRad += 5.f * Time::DeltaTime();
		//pos += Vector2(1.f, 5.f*cosf(mRad)) * (100*Time::DeltaTime());

		// 마우스 위치 방향으로 회전 후 마우스 위치 이동.
		//Transform* plTr = mPlayer->GetComponent<Transform>();
		//Vector2 dest = mDest - plTr->GetPosition(); 
		//dest.normalize();

		//float rotDegree = Vector2::Dot(dest, Vector2::Right); // cos세타
		//rotDegree = ConvertDegree(acosf(rotDegree));
		//pos += dest.normalize() * (100.f * Time::DeltaTime());
		//
		//tr->SetPosition(pos);
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