#pragma once

#include "CommonInclude.h"
#include "smeGameObject.h"

namespace sme
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND mHwnd);
		void Run();
		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		float mSpeed;


		GameObject* mPlayer[2];
	};
}


