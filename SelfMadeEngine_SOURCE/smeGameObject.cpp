#include "smeGameObject.h"
#include "smeInput.h"
#include "smeTime.h"
#include "smeTransform.h"

namespace sme
{
	GameObject::GameObject()
	{
		mComponents.resize((UINT)enums::eComponentType::End);
		initializeTransform();
	}
	GameObject::~GameObject()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			delete comp;
			comp = nullptr;
		}
	}

	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			comp->Initialize();
		}
	}
	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			comp->Update();
		}
	}
	void GameObject::LateUpdate()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			comp->LateUpdate();
		}
	}
	void GameObject::Render(HDC mHdc)
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			comp->Render(mHdc);
		}
	}

	void GameObject::initializeTransform()
	{
		AddComponent<Transform>();
	}
}