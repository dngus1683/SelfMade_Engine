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


	/*
	Shape* sh = GetOwner()->GetComponent<Shape>();

	switch (sh->GetType())
	{
		case 0:
		{
			HBRUSH BlueBrush = CreateSolidBrush(RGB(0, 0, 255));    // 오브젝트의 배경 색상 생성.
			HBRUSH PreBrush = (HBRUSH)SelectObject(hdc, BlueBrush); // 오브젝트 설정을 hdc에 적용. 이전 설정값 반환.

			Transform* tr = GetOwner()->GetComponent<Transform>();
			Rectangle(hdc, tr->GetX(), tr->GetY(), tr->GetX() + 100, tr->GetY() + 100);

			SelectObject(hdc, PreBrush);
			DeleteObject(BlueBrush);
		}
		break;
		case 1:
		{
			HBRUSH BlueBrush = CreateSolidBrush(RGB(0, 0, 255));    // 오브젝트의 배경 색상 생성.
			HBRUSH PreBrush = (HBRUSH)SelectObject(hdc, BlueBrush); // 오브젝트 설정을 hdc에 적용. 이전 설정값 반환.

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
