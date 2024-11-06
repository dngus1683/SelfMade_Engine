#include "smeTime.h"

namespace sme
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PreFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue = 0.f;

	void Time::Initialize()
	{
		// CPU 고유 진동수
		QueryPerformanceFrequency(&CpuFrequency);

		// 프로그램이 시작했을 때 현재 진동수
		QueryPerformanceCounter(&PreFrequency);
	}
	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		float differenceFrequency = static_cast<float>(CurrentFrequency.QuadPart - PreFrequency.QuadPart);
		
		DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);
		PreFrequency.QuadPart = CurrentFrequency.QuadPart;
	}

	void Time::Render(HDC InHdc)
	{
		static float time = 0.f;
		static float fps = 0.f;

		time += DeltaTimeValue;
		fps = 1.0f / DeltaTimeValue;

		wchar_t strTime[50] = L""; // wchar_t를 const 초기화 하는 방법: L""
		swprintf_s(strTime, 50, L"Time : %d", (int)time);
		int lenTIme = wcsnlen_s(strTime, 50);

		wchar_t strFPS[50] = L""; // wchar_t를 const 초기화 하는 방법: L""
		swprintf_s(strFPS, 50, L"FPS : %d", (int)fps);
		int lenFPS = wcsnlen_s(strFPS, 50);

		// 텍스트를 화면에 출력해주는 함수 TextOut()
		TextOut(InHdc, 0, 0, strTime, lenTIme);
		TextOut(InHdc, 0, 20, strFPS, lenFPS);
	}

}