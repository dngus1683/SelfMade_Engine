#include "smeSpriteRenderer.h"
#include "smeGameObject.h"
#include "smeTransform.h"
#include "smeShape.h"

sme::SpriteRenderer::SpriteRenderer()
	: mImage(nullptr)
	, mWidth(0)
	, mHeight(0)
{
}

sme::SpriteRenderer::~SpriteRenderer()
{
}

void sme::SpriteRenderer::Initialize()
{
}

void sme::SpriteRenderer::Update()
{
}

void sme::SpriteRenderer::LateUpdate()
{
}

void sme::SpriteRenderer::Render(HDC hdc)
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


	/*
	Shape* sh = GetOwner()->GetComponent<Shape>();

	switch (sh->GetType())
	{
		case 0:
		{
			HBRUSH BlueBrush = CreateSolidBrush(RGB(0, 0, 255));    // ������Ʈ�� ��� ���� ����.
			HBRUSH PreBrush = (HBRUSH)SelectObject(hdc, BlueBrush); // ������Ʈ ������ hdc�� ����. ���� ������ ��ȯ.

			Transform* tr = GetOwner()->GetComponent<Transform>();
			Rectangle(hdc, tr->GetX(), tr->GetY(), tr->GetX() + 100, tr->GetY() + 100);

			SelectObject(hdc, PreBrush);
			DeleteObject(BlueBrush);
		}
		break;
		case 1:
		{
			HBRUSH BlueBrush = CreateSolidBrush(RGB(0, 0, 255));    // ������Ʈ�� ��� ���� ����.
			HBRUSH PreBrush = (HBRUSH)SelectObject(hdc, BlueBrush); // ������Ʈ ������ hdc�� ����. ���� ������ ��ȯ.

			Transform* tr = GetOwner()->GetComponent<Transform>();
			Ellipse(hdc, tr->GetX(), tr->GetY(), tr->GetX() + 100, tr->GetY() + 100);

			SelectObject(hdc, PreBrush);
			DeleteObject(BlueBrush);
		}
		default:
			break;
	}
	*/

	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetPosition();

	Gdiplus::Graphics graphics(hdc);
	graphics.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));
}

void sme::SpriteRenderer::ImageLoad(const std::wstring& path)
{
	mImage = Gdiplus::Image::FromFile(path.c_str());
	mWidth = mImage->GetWidth();
	mHeight = mImage->GetHeight();
}
