#pragma once

#include "../SelfMadeEngine_SOURCE/smeGameObject.h"

namespace sme
{
	class Floor : public GameObject
	{
	public:
		Floor();
		~Floor();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:


	};
}

