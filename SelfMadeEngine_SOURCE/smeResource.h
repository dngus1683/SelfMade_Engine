#pragma once

#include "smeEntity.h"

namespace sme
{
	class Resource : public Entity // 추상 클래스(한 개 이상의 순수 가상 함수 존재)
	{
	public:
		Resource(enums::eResourceType InType);
		virtual ~Resource();

		// HRESULT 타입 = bool
		virtual HRESULT Load(const std::wstring& path) = 0; // 순수 가상 함수. 실제 메모리 할당 불가.

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}
