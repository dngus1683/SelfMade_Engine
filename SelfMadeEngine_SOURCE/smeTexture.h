#pragma once

#include "smeResource.h"

namespace sme
{
	namespace graphics
	{
		class Texture : public Resource
		{
		public:
			enum class eTextureType
			{
				Bmp,
				Png,
				None,
			};

			static Texture* Create(const std::wstring& name, UINT width, UINT height);

			Texture();
			~Texture();

			virtual HRESULT Load(const std::wstring& path) override;

			UINT GetWidth() { return mWidth; }
			void SetWidth(UINT width) { mWidth = width; }
			UINT GetHeight() { return mHeight; }
			void SetHeight(UINT height) { mHeight = height; }
			bool IsAlpha() { return mbAlpha; }
			HDC GetHdc() { return mHdc; }
			eTextureType GetType() {return mType;}
			void SetType(Texture::eTextureType InType) { mType = InType; }
			Gdiplus::Image* GetImage() { return mImage; }

		private:
			bool mbAlpha;
			eTextureType mType;
			Gdiplus::Image* mImage;
			HBITMAP mBitmap;
			HDC mHdc;

			UINT mWidth;
			UINT mHeight;
		};
	}
}

