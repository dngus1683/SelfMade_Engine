#include "smeInput.h"


namespace sme
{
	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M', 
		VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,
	};

	void Input::Initialize()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = true;
			key.KeyCode = (eKeyCode)i;
			key.state = eKeyState::None;

			mKeys.push_back(key);
		}
	}
	void Input::Update()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			// 키가 눌려짐.
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				// Pressed: 이전에 키가 눌려져 있는데 여전히 눌려져 있다.
				if (mKeys[i].bPressed == true)
				{
					mKeys[i].state = eKeyState::Pressed;
				}
				// Down: 이전에 키가 안눌려져 있었지만 지금 눌러졌다.
				else
				{
					mKeys[i].state = eKeyState::Down;
				}
				mKeys[i].bPressed = true;
			}
			// 키가 안누름.
			else
			{
				// Up: 이전에 키가 눌려져 있는데, 지금 떼어 졌다.
				if (mKeys[i].bPressed == true)
				{
					mKeys[i].state = eKeyState::Up;
				}
				// None: 이전에도, 지금도 키가 눌려지지 않았다.
				else
				{
					mKeys[i].state = eKeyState::None;
				}
				mKeys[i].bPressed = false;
			}
		}
	}
}