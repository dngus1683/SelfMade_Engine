#include "smeGameObject.h"
#include "smeInput.h"
#include "smeTime.h"

namespace sme
{
	GameObject::GameObject() : mX(0.f), mY(0.f), mType(0)
	{
	}
	GameObject::GameObject(float InX, float InY, int InType) : mX(InX), mY(InY), mType(InType)
	{
	}
	GameObject::~GameObject()
	{
	}
	void GameObject::Update()
	{
		const int speed = 100.f;
		if (mType == 0)
		{
			if (Input::GetKey(eKeyCode::UP))
			{
				mY -= speed * Time::DeltaTime();
			}
			if (Input::GetKey(eKeyCode::DOWN))
			{
				mY += speed * Time::DeltaTime();
			}
			if (Input::GetKey(eKeyCode::LEFT))
			{
				mX -= speed * Time::DeltaTime();
			}
			if (Input::GetKey(eKeyCode::RIGHT))
			{
				mX += speed * Time::DeltaTime();
			}
		}
		if (mType == 1)
		{
			if (Input::GetKey(eKeyCode::W))
			{
				mY -= speed * Time::DeltaTime();
			}
			if (Input::GetKey(eKeyCode::S))
			{
				mY += speed * Time::DeltaTime();
			}
			if (Input::GetKey(eKeyCode::A))
			{
				mX -= speed * Time::DeltaTime();
			}
			if (Input::GetKey(eKeyCode::D))
			{
				mX += speed * Time::DeltaTime();
			}
		}
	}
	void GameObject::LateUpdate()
	{

	}
	void GameObject::Render(HDC mHdc)
	{
		/*
		Rectangle(mHdc, 100, 100, 200, 200); // 직사각형을 그리는 함수: 직사각형의 좌상단 좌표와 우하단 좌표 입력.

		SelectObject(mHdc, PreBrush);    // 이전 설정값으로 되돌림.
		DeleteObject(BlueBrush);        // 메모리 소비를 줄이기 위해 안쓰는 메모리 반환.

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));    // 선의 모양과 길이, 색상 설정을 정함.
		HPEN PrePen = (HPEN)SelectObject(mHdc, redPen);           // 선 설정을 적용.

		Ellipse(mHdc, 200, 200, 300, 300);   // 원을 그리는 함수: 주어진 좌표로 만들어지는 직사각형에 외접하는 원 그림.

		SelectObject(mHdc, PrePen);    // 이전 설정값으로 되돌림.
		DeleteObject(redPen);        // 메모리 소비를 줄이기 위해 안쓰는 메모리 반환.

		HBRUSH GrayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);  // 스톡 오브젝트 불러오기.
		PreBrush = (HBRUSH)SelectObject(mHdc, GrayBrush);        // 스톡 오브젝트 설정 적용.

		Ellipse(mHdc, 400, 400, 500, 500);
		SelectObject(mHdc, PreBrush);                            // 다시 원래 설정으로 적용. 스톡 오브젝트는 미리 만들어진 오브젝트이므로 제거하지 않음.
		*/

		switch (mType)
		{
		case 0:
		{
			HBRUSH BlueBrush = CreateSolidBrush(RGB(0, 0, 255));    // 오브젝트의 배경 색상 생성.
			HBRUSH PreBrush = (HBRUSH)SelectObject(mHdc, BlueBrush); // 오브젝트 설정을 hdc에 적용. 이전 설정값 반환.

			Rectangle(mHdc, mX, mY, mX + 100, mY + 100);

			SelectObject(mHdc, PreBrush);
			DeleteObject(BlueBrush);
		}
		break;
		case 1:
		{
			HBRUSH RedBrush = CreateSolidBrush(RGB(255, 0, 0));
			HBRUSH PreBrush = (HBRUSH)SelectObject(mHdc, RedBrush);

			Ellipse(mHdc, mX, mY, mX + 100, mY + 100);

			SelectObject(mHdc, PreBrush);
			DeleteObject(RedBrush);
		}
		break;
		default:
			break;
		}

	}
}