#include "smeInput.h"
#include "smeApplication.h"

extern sme::Application application;

namespace sme
{
	std::vector<Input::Key> Input::mKeys = {};
	Vector2 Input::mMousePosition = Vector2::One;

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M', 
		VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,
		VK_LBUTTON, VK_MBUTTON, VK_RBUTTON
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

		if (GetFocus())
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
			getMousePositionByWindow();
		}
		else
		{
			clearKeys();
		}
	}
	void Input::clearKeys()
	{
		for (Key& key : mKeys)
		{
			if (key.state == eKeyState::Down || key.state == eKeyState::Pressed)
			{
				key.state = eKeyState::Up;
			}
			else if (key.state == eKeyState::Up)
			{
				key.state = eKeyState::None;
			}
			key.bPressed = false;
		}
	}
	void Input::getMousePositionByWindow()
	{
		POINT mousePos = {};
		GetCursorPos(&mousePos);
		ScreenToClient(application.GetHwnd(), &mousePos);

		UINT width = application.GetWidth();
		UINT height = application.GetHeight();

		mMousePosition.x = -1.f;
		mMousePosition.y = -1.f;
		if (mousePos.x < width && mousePos.x > 0)
		{
			mMousePosition.x = mousePos.x;
		}
		if (mousePos.y < height && mousePos.y > 0)
		{
			mMousePosition.y = mousePos.y;
		}
	}
}