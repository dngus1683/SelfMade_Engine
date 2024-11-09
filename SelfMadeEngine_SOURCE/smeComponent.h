#pragma once

#include "CommonInclude.h"
#include "smeEntity.h"

namespace sme
{
	// GameObject <-> Component의 헤더 참조의 순환을 방지하기 위한 전방 선언
	class GameObject;
	class Component : public Entity
	{
	public:
		Component();
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(GameObject* owner) { mOwner = owner; }
		GameObject* GetOwner() { return mOwner; }

	private:
		GameObject* mOwner;

	};

}
