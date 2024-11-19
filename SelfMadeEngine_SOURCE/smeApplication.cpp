#include "smeApplication.h"
#include "smeInput.h"
#include "smeTime.h"
#include "smeSceneManager.h"
#include "smeResources.h"
#include "smeCollisionManager.h"

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
		CollisionManager::Initialize();
		SceneManager::Initialize();
		Time::Initialize();
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
		Destroy();
	}
	void Application::Update()
	{
		Input::Update();
		CollisionManager::Update();
		SceneManager::Update();
		Time::Update();
	}
	void Application::LateUpdate()
	{
		CollisionManager::LateUpdate();
		SceneManager::LateUpdate();
	}
	void Application::Render()
	{
		// ȭ�� �ʱ�ȭ
		HBRUSH grayBrush = (HBRUSH)CreateSolidBrush(RGB(128, 128, 128));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHdc, grayBrush);

		Rectangle(mBackHdc, -1, -1, mWidth+1, mHeight+1);

		SelectObject(mBackHdc, oldBrush);
		DeleteObject(grayBrush);

		Time::Render(mBackHdc);
		CollisionManager::Render(mBackHdc);
		SceneManager::Render(mBackHdc);

		// ����ۿ� �׷��� ȭ���� ���� ���ۿ� ����
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
	void Application::Destroy()
	{
		SceneManager::Destroy();
	}
	void Application::Release()
	{
		SceneManager::Release();
		Resources::Release();
	}
}