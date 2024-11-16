#include "smeTransform.h"


namespace sme
{
	Transform::Transform()
		: Component(enums::eComponentType::Transform)
		, mRotation(0.f)
		, mScale(Vector2::One)
		, mPosition(Vector2::Zero)
	{
	}
	Transform::~Transform()
	{
	}
	void Transform::Initialize()
	{
	}
	void Transform::Update()
	{
	}
	void Transform::LateUpdate()
	{
	}
	void Transform::Render(HDC hdc)
	{
	}
}