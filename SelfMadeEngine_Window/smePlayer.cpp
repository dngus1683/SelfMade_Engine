#include "smePlayer.h"
#include "smeInput.h"
#include "smeTransform.h"
#include "smeTime.h"

namespace sme
{
	void Player::Initialize()
	{
		GameObject::Initialize();
	}

	void Player::Update()
	{
		GameObject::Update();
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();

		if (Input::GetKey(eKeyCode::RIGHT))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x += 100.f * Time::DeltaTime();
			tr->SetPos(pos);
		}
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
