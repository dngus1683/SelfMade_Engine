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

		// 윈도우의 작업 크기를 rect로.
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);

		// 윈도우 해상도에 맞는 백버퍼 생성
		mBackBuffer = CreateCompatibleBitmap(mHdc, width, height);

		// 백버퍼를 가리킬 DC 생성
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
		// 화면 초기화
		HBRUSH grayBrush = (HBRUSH)CreateSolidBrush(RGB(128, 128, 128));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHdc, grayBrush);

		Rectangle(mBackHdc, -1, -1, mWidth+1, mHeight+1);

		SelectObject(mBackHdc, oldBrush);
		DeleteObject(grayBrush);

		Time::Render(mBackHdc);
		CollisionManager::Render(mBackHdc);
		SceneManager::Render(mBackHdc);

		// 백버퍼에 그려진 화면을 원본 버퍼에 복사
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