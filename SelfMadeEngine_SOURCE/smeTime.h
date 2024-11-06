#pragma once

#include "CommonInclude.h"

namespace sme
{
	class Time
	{
	public: 
		static void Initialize();
		static void Update();
		static void Render(HDC InHdc);
		static float DeltaTime() { return DeltaTimeValue; }
	private:
		static LARGE_INTEGER CpuFrequency;
		static LARGE_INTEGER PreFrequency;
		static LARGE_INTEGER CurrentFrequency;
		static float DeltaTimeValue;
	};
}

