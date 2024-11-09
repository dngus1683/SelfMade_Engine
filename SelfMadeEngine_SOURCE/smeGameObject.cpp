#include "smeGameObject.h"
#include "smeInput.h"
#include "smeTime.h"

namespace sme
{
	GameObject::GameObject()
	{
	}
	GameObject::~GameObject()
	{
		for (Component* comp : mComponents)
		{
			delete comp;
			comp = nullptr;
		}
	}

	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			comp->Initialize();
		}
	}
	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			comp->Update();
		}

		/*
		const int speed = 100.f;
		if (mType == 0)
		{
			if (Input::GetKey(eKeyCode::UP))
			{
				mY -= speed * Time::DeltaTime();
			}
			if (Input::GetKey(eKeyCode::DOWN))
			{
				mY += speed * Time::DeltaTime();
			}
			if (Input::GetKey(eKeyCode::LEFT))
			{
				mX -= speed * Time::DeltaTime();
			}
			if (Input::GetKey(eKeyCode::RIGHT))
			{
				mX += speed * Time::DeltaTime();
			}
		}
		if (mType == 1)
		{
			if (Input::GetKey(eKeyCode::W))
			{
				mY -= speed * Time::DeltaTime();
			}
			if (Input::GetKey(eKeyCode::S))
			{
				mY += speed * Time::DeltaTime();
			}
			if (Input::GetKey(eKeyCode::A))
			{
				mX -= speed * Time::DeltaTime();
			}
			if (Input::GetKey(eKeyCode::D))
			{
				mX += speed * Time::DeltaTime();
			}
		}
		*/
		

	}
	void GameObject::LateUpdate()
	{
		for (Component* comp : mComponents)
		{
			comp->LateUpdate();
		}
	}
	void GameObject::Render(HDC mHdc)
	{
		for (Component* comp : mComponents)
		{
			comp->Render(mHdc);
		}
	}
}