#include "smeApplication.h"
#include "smeInput.h"
#include "smeTime.h"
#include "smeSceneManager.h"

namespace sme
{
	Application::Application() 
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mSpeed(0.f)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(NULL)
		, mBackBuffer(NULL)
	{
	}
	Application::~Application()
	{
	}
	void Application::Initialize(HWND InHwnd, UINT width, UINT height)
	{
		mHwnd = InHwnd;
		mHdc = GetDC(mHwnd);

		RECT rect = { 0, 0, width, height };
		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		// �������� �۾� ũ�⸦ rect��.
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);

		// ������ �ػ󵵿� �´� ����� ����
		mBackBuffer = CreateCompatibleBitmap(mHdc, width, height);

		// ����۸� ����ų DC ����
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(oldBitmap);

		Input::Initialize();
		SceneManager::Initialize();
		Time::Initialize();
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
		Input::Update();
		SceneManager::Update();
		Time::Update();

	}
	void Application::LateUpdate()
	{
		SceneManager::LateUpdate();
	}
	void Application::Render()
	{
		// ȭ�� �ʱ�ȭ
		Rectangle(mBackHdc, -1, -1, mWidth+1, mHeight+1);

		Time::Render(mBackHdc);

		SceneManager::Render(mBackHdc);

		// ����ۿ� �׷��� ȭ���� ���� ���ۿ� ����
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
}