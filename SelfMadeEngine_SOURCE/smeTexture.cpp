#include "smeTexture.h"
#include "smeApplication.h"
#include "smeResources.h"

// 해당 전역변수가 존재함(main.cpp에)을 알리는 키워드.
extern sme::Application application;

namespace sme::graphics
{

	Texture* Texture::Create(const std::wstring& name, UINT width, UINT height)
	{
		Texture* image = Resources::Find<Texture>(name);
		if (image)
			return image;

		image = new Texture();
		image->SetName(name);
		image->SetWidth(width);
		image->SetHeight(height);

		HDC hdc = application.GetHdc();
		HWND hwnd = application.GetHwnd();

	
		image->mBitmap = CreateCompatibleBitmap(hdc, width, height);
		image->mHdc = CreateCompatibleDC(hdc);

		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);
		Rectangle(image->mHdc
			, -1
			, -1
			, image->GetWidth() + 1
			, image->GetHeight() + 1
		);
		SelectObject(image->mHdc, oldBrush);


		HBITMAP oldBitmap = (HBITMAP)SelectObject(image->mHdc, image->mBitmap);
		DeleteObject(oldBitmap);

		Resources::Insert(name+L"Image", image);
		return image;
	}
	Texture::Texture()
		: Resource(enums::eResourceType::Texture)
		, mType(eTextureType::None)
		, mImage(nullptr)
		, mBitmap(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mbAlpha(false)
	{
	}
	Texture::~Texture()
	{
	}
	HRESULT Texture::Load(const std::wstring& path)
	{
		// 확장자 가져오기.
		std::wstring ext = path.substr(path.find_last_of(L".") + 1);

		// bmp 일 때.
		if (ext == L"bmp")
		{
			mType = eTextureType::Bmp;
			mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0,
				LR_LOADFROMFILE | LR_CREATEDIBSECTION);

			// 로드 실패할 경우.
			if (mBitmap == nullptr)
			{
				return S_FALSE;
			}

			BITMAP info = {};
			GetObject(mBitmap, sizeof(BITMAP), &info);

			mWidth = info.bmWidth;
			mHeight = info.bmHeight;
			
			if (info.bmBitsPixel == 32)
			{
				mbAlpha = true;
			}
			else if (info.bmBitsPixel == 24)
			{
				mbAlpha = false;
			}

			HDC mainDC = application.GetHdc();
			mHdc = CreateCompatibleDC(mainDC);

			// 각 이미지(비트맵)에 대응하는 DC 생성. (1대1 대응)
			HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
			DeleteObject(oldBitmap);
		}
		// png 일 때.
		else if (ext == L"png")
		{
			mType = eTextureType::Png;
			mImage = Gdiplus::Image::FromFile(path.c_str());
			// 로드 실패할 경우.
			if (mImage == nullptr)
			{
				return S_FALSE;
			}
			mWidth = mImage->GetWidth();
			mHeight = mImage->GetHeight();
		}
		return S_OK;
	}
}
