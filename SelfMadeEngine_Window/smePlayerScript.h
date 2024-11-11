#pragma once

#include "../SelfMadeEngine_SOURCE/smeScript.h"

namespace sme
{
	class PlayerScript : public Script
	{
	public:
		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:

	};
}

