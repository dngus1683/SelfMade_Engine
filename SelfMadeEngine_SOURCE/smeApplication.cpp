#include "smeApplication.h"



namespace sme
{
	Application::Application() : mHwnd(nullptr), mHdc(nullptr), mSpeed(0.f), mX(0.0), mY(0.0)
	{
	}
	Application::~Application()
	{
	}
	void Application::Initialize(HWND InHwnd)
	{
		mHwnd = InHwnd;
		mHdc = GetDC(mHwnd);
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
		mSpeed = 0.01f;
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mY -= mSpeed;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mY += mSpeed;
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mX -= mSpeed;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mX += mSpeed;
		}
	}
	void Application::LateUpdate()
	{
	}
	void Application::Render()
	{
		HBRUSH BlueBrush = CreateSolidBrush(RGB(0, 0, 255));    // 오브젝트의 배경 색상 생성.

		HBRUSH PreBrush = (HBRUSH)SelectObject(mHdc, BlueBrush); // 오브젝트 설정을 hdc에 적용. 이전 설정값 반환.

		Rectangle(mHdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		/*
		Rectangle(mHdc, 100, 100, 200, 200); // 직사각형을 그리는 함수: 직사각형의 좌상단 좌표와 우하단 좌표 입력.

		SelectObject(mHdc, PreBrush);    // 이전 설정값으로 되돌림.
		DeleteObject(BlueBrush);        // 메모리 소비를 줄이기 위해 안쓰는 메모리 반환.

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));    // 선의 모양과 길이, 색상 설정을 정함.
		HPEN PrePen = (HPEN)SelectObject(mHdc, redPen);           // 선 설정을 적용.

		Ellipse(mHdc, 200, 200, 300, 300);   // 원을 그리는 함수: 주어진 좌표로 만들어지는 직사각형에 외접하는 원 그림.

		SelectObject(mHdc, PrePen);    // 이전 설정값으로 되돌림.
		DeleteObject(redPen);        // 메모리 소비를 줄이기 위해 안쓰는 메모리 반환.

		HBRUSH GrayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);  // 스톡 오브젝트 불러오기.
		PreBrush = (HBRUSH)SelectObject(mHdc, GrayBrush);        // 스톡 오브젝트 설정 적용.

		Ellipse(mHdc, 400, 400, 500, 500);
		SelectObject(mHdc, PreBrush);                            // 다시 원래 설정으로 적용. 스톡 오브젝트는 미리 만들어진 오브젝트이므로 제거하지 않음.
		*/
	}
}