#include "smeTexture.h"
#include "smeApplication.h"

// 해당 전역변수가 존재함(main.cpp에)을 알리는 키워드.
extern sme::Application application;

namespace sme
{
	namespace graphics
	{
		Texture::Texture()
			: Resource(enums::eResourceType::Texture)
			, mType(eTextureType::None)
			, mImage(nullptr)
			, mBitmap(nullptr)
			, mHdc(nullptr)
			, mWidth(0)
			, mHeight(0)
		{
		}
		Texture::~Texture()
		{
		}
		HRESULT Texture::Load(const std::wstring& path)
		{
			// 확장자 가져오기.
			std::wstring ext = path.substr(path.find_last_of(L".")+1);
			
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
}
