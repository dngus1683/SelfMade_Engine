#include "smeTransform.h"


namespace sme
{
	Transform::Transform()
		: mPosition(0.f, 0.f)
		, Component(enums::eComponentType::Transform)
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