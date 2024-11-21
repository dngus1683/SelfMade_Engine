#pragma once
#pragma once

#include "../SelfMadeEngine_SOURCE/smeGameObject.h"

namespace sme
{
	class Tile : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPosition(int x, int y);
	private:


	};
}

