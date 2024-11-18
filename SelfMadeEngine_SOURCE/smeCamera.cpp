#include "smeCamera.h"
#include "smeGameObject.h"
#include "smeTransform.h"
#include "smeApplication.h"

extern sme::Application application;

namespace sme
{
	Camera::Camera()
		:Component(enums::eComponentType::Camera)
		, mDistance(Vector2::Zero)
		, mResolution({ 1600.f, 900.f })
		, mLookPosition(Vector2::Zero)
		, mTarget(nullptr)
	{
	}
	Camera::~Camera()
	{
	}
	void Camera::Initialize()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
	}
	void Camera::Update()
	{
		if (mTarget)
		{
			Transform* tr = mTarget->GetComponent<Transform>();
			mLookPosition = tr->GetPosition();

		}
		else
		{
			Transform* cameraTr = GetOwner()->GetComponent<Transform>();
			mLookPosition = cameraTr->GetPosition();
		}
		mDistance = mLookPosition - (mResolution / 2.f);
	}
	void Camera::LateUpdate()
	{

	}
	void Camera::Render(HDC hdc)
	{
	}
}
