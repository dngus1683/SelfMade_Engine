#include "smeApplication.h"
#include "smeInput.h"
#include "smeTime.h"

namespace sme
{
	Application::Application() : mHwnd(nullptr), mHdc(nullptr), mSpeed(0.f)
	{
	}
	Application::~Application()
	{
	}
	void Application::Initialize(HWND InHwnd)
	{
		mHwnd = InHwnd;
		mHdc = GetDC(mHwnd);

		Input::Initialize();

		mPlayer[0] = new GameObject(100.f, 100.f, 0);
		mPlayer[1] = new GameObject(500.f, 500.f, 1);

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
		Time::Update();
		for (int i = 0; i < 2; i++)
		{
			mPlayer[i]->Update();
		}
	}
	void Application::LateUpdate()
	{
	}
	void Application::Render()
	{
		Time::Render(mHdc);
		for (int i = 0; i < 2; i++)
		{
			mPlayer[i]->Render(mHdc);
		}
	}
}