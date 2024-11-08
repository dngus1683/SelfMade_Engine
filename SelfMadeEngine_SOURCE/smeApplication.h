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

		void Initialize(HWND mHwnd, UINT width, UINT height);
		void Run();
		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		// ���� ���۸� �� DC
		HDC mBackHdc;
		HBITMAP mBackBuffer;
		
		// �ػ�
		UINT mWidth;
		UINT mHeight;

		float mSpeed;

	};
}


