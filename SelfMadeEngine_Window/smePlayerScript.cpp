#include "smePlayerScript.h"
#include "smeTime.h"
#include "smeInput.h"
#include "smeTransform.h"
#include "smeGameObject.h"

namespace sme
{
	PlayerScript::PlayerScript()
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
		if (Input::GetKey(eKeyCode::RIGHT))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x += 100.f * Time::DeltaTime();
			tr->SetPos(pos);
		}
		if (Input::GetKey(eKeyCode::LEFT))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x -= 100.f * Time::DeltaTime();
			tr->SetPos(pos);
		}
		if (Input::GetKey(eKeyCode::UP))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.y -= 100.f * Time::DeltaTime();
			tr->SetPos(pos);
		}
		if (Input::GetKey(eKeyCode::DOWN))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.y += 100.f * Time::DeltaTime();
			tr->SetPos(pos);
		}
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
}