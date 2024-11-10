#include "smeTexture.h"
#include "smeApplication.h"

// �ش� ���������� ������(main.cpp��)�� �˸��� Ű����.
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
			// Ȯ���� ��������.
			std::wstring ext = path.substr(path.find_last_of(L".")+1);
			
			// bmp �� ��.
			if (ext == L"bmp")
			{
				mType = eTextureType::Bmp;
				mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0,
					LR_LOADFROMFILE | LR_CREATEDIBSECTION);
				
				// �ε� ������ ���.
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

				// �� �̹���(��Ʈ��)�� �����ϴ� DC ����. (1��1 ����)
				HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
				DeleteObject(oldBitmap);
			}
			// png �� ��.
			else if (ext == L"png")
			{
				mType = eTextureType::Png;
				mImage = Gdiplus::Image::FromFile(path.c_str());
				// �ε� ������ ���.
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