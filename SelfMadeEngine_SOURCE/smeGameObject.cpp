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
		Rectangle(mHdc, 100, 100, 200, 200); // ���簢���� �׸��� �Լ�: ���簢���� �»�� ��ǥ�� ���ϴ� ��ǥ �Է�.

		SelectObject(mHdc, PreBrush);    // ���� ���������� �ǵ���.
		DeleteObject(BlueBrush);        // �޸� �Һ� ���̱� ���� �Ⱦ��� �޸� ��ȯ.

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));    // ���� ���� ����, ���� ������ ����.
		HPEN PrePen = (HPEN)SelectObject(mHdc, redPen);           // �� ������ ����.

		Ellipse(mHdc, 200, 200, 300, 300);   // ���� �׸��� �Լ�: �־��� ��ǥ�� ��������� ���簢���� �����ϴ� �� �׸�.

		SelectObject(mHdc, PrePen);    // ���� ���������� �ǵ���.
		DeleteObject(redPen);        // �޸� �Һ� ���̱� ���� �Ⱦ��� �޸� ��ȯ.

		HBRUSH GrayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);  // ���� ������Ʈ �ҷ�����.
		PreBrush = (HBRUSH)SelectObject(mHdc, GrayBrush);        // ���� ������Ʈ ���� ����.

		Ellipse(mHdc, 400, 400, 500, 500);
		SelectObject(mHdc, PreBrush);                            // �ٽ� ���� �������� ����. ���� ������Ʈ�� �̸� ������� ������Ʈ�̹Ƿ� �������� ����.
		*/

		switch (mType)
		{
		case 0:
		{
			HBRUSH BlueBrush = CreateSolidBrush(RGB(0, 0, 255));    // ������Ʈ�� ��� ���� ����.
			HBRUSH PreBrush = (HBRUSH)SelectObject(mHdc, BlueBrush); // ������Ʈ ������ hdc�� ����. ���� ������ ��ȯ.

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