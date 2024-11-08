#pragma once

#include "CommonInclude.h"

namespace sme
{
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

		static bool GetKeyDown(eKeyCode InCode) { return mKeys[(UINT)InCode].state == eKeyState::Down; }
		static bool GetKeyUp(eKeyCode InCode) { return mKeys[(UINT)InCode].state == eKeyState::Up; }
		static bool GetKey(eKeyCode InCode) { return mKeys[(UINT)InCode].state == eKeyState::Pressed; }

	private:
		static std::vector<Key> mKeys;

	};
}

