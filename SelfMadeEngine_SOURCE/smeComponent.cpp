#include "smeComponent.h"


namespace sme
{
	Component::Component(enums::eComponentType InType)
		: mType(InType)
		, mOwner(nullptr)
	{
	}
	Component::~Component()
	{
	}
	void Component::Initialize()
	{
	}
	void Component::Update()
	{
	}
	void Component::LateUpdate()
	{
	}
	void Component::Render(HDC hdc)
	{
	}
}