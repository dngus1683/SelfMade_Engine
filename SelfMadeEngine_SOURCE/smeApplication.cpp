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
		HBRUSH BlueBrush = CreateSolidBrush(RGB(0, 0, 255));    // ������Ʈ�� ��� ���� ����.

		HBRUSH PreBrush = (HBRUSH)SelectObject(mHdc, BlueBrush); // ������Ʈ ������ hdc�� ����. ���� ������ ��ȯ.

		Rectangle(mHdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		/*
		Rectangle(mHdc, 100, 100, 200, 200); // ���簢���� �׸��� �Լ�: ���簢���� �»�� ��ǥ�� ���ϴ� ��ǥ �Է�.

		SelectObject(mHdc, PreBrush);    // ���� ���������� �ǵ���.
		DeleteObject(BlueBrush);        // �޸� �Һ� ���̱� ���� �Ⱦ��� �޸� ��ȯ.

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));    // ���� ���� ����, ���� ������ ����.
		HPEN PrePen = (HPEN)SelectObject(mHdc, redPen);           // �� ������ ����.

		Ellipse(mHdc, 200, 200, 300, 300);   // ���� �׸��� �Լ�: �־��� ��ǥ�� ��������� ���簢���� �����ϴ� �� �׸�.

		SelectObject(mHdc, PrePen);    // ���� ���������� �ǵ���.
		DeleteObject(redPen);        // �޸� �Һ� ���̱� ���� �Ⱦ��� �޸� ��ȯ.

		HBRUSH GrayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);  // ���� ������Ʈ �ҷ�����.
		PreBrush = (HBRUSH)SelectObject(mHdc, GrayBrush);        // ���� ������Ʈ ���� ����.

		Ellipse(mHdc, 400, 400, 500, 500);
		SelectObject(mHdc, PreBrush);                            // �ٽ� ���� �������� ����. ���� ������Ʈ�� �̸� ������� ������Ʈ�̹Ƿ� �������� ����.
		*/
	}
}