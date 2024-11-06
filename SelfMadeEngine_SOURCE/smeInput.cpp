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
			// Ű�� ������.
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				// Pressed: ������ Ű�� ������ �ִµ� ������ ������ �ִ�.
				if (mKeys[i].bPressed == true)
				{
					mKeys[i].state = eKeyState::Pressed;
				}
				// Down: ������ Ű�� �ȴ����� �־����� ���� ��������.
				else
				{
					mKeys[i].state = eKeyState::Down;
				}
				mKeys[i].bPressed = true;
			}
			// Ű�� �ȴ���.
			else
			{
				// Up: ������ Ű�� ������ �ִµ�, ���� ���� ����.
				if (mKeys[i].bPressed == true)
				{
					mKeys[i].state = eKeyState::Up;
				}
				// None: ��������, ���ݵ� Ű�� �������� �ʾҴ�.
				else
				{
					mKeys[i].state = eKeyState::None;
				}
				mKeys[i].bPressed = false;
			}
		}
	}
}