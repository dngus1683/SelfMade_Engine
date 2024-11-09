#pragma once

#include "../SelfMadeEngine_SOURCE/smeGameObject.h"

namespace sme
{
	class Player : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:


	};
}

