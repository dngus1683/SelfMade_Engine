#pragma once

#include "../SelfMadeEngine_SOURCE/smeScript.h"
#include "smeTransform.h"

namespace sme
{
	class CameraScript : public Script
	{
	public:
		CameraScript();
		~CameraScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}

