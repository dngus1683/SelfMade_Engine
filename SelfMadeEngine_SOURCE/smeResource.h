#pragma once

#include "smeEntity.h"

namespace sme
{
	class Resource : public Entity // �߻� Ŭ����(�� �� �̻��� ���� ���� �Լ� ����)
	{
	public:
		Resource(enums::eResourceType InType);
		virtual ~Resource();

		// HRESULT Ÿ�� = bool
		virtual HRESULT Load(const std::wstring& path) = 0; // ���� ���� �Լ�. ���� �޸� �Ҵ� �Ұ�.

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}
