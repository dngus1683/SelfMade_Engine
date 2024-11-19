#pragma once

#include "CommonInclude.h"

namespace sme
{
	using namespace math;

	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};
	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		LEFT, RIGHT, UP, DOWN,
		LButton, MBUtton, RButton,
		End,
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode KeyCode;
			eKeyState state;
			bool bPressed;
		};
		static void Initialize();
		static void Update();

		__forceinline static bool GetKeyDown(eKeyCode InCode) { return mKeys[(UINT)InCode].state == eKeyState::Down; }
		__forceinline static bool GetKeyUp(eKeyCode InCode) { return mKeys[(UINT)InCode].state == eKeyState::Up; }
		__forceinline static bool GetKey(eKeyCode InCode) { return mKeys[(UINT)InCode].state == eKeyState::Pressed; }
		__forceinline static Vector2 GetMousePosition() { return mMousePosition; }

	private:
		static void clearKeys();
		static void getMousePositionByWindow();
	private:
		static std::vector<Key> mKeys;
		static Vector2 mMousePosition;

	};
}

