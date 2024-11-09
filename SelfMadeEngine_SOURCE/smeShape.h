#pragma once

#include "smeComponent.h"

namespace sme
{
	class Shape : public Component
	{
	public:
		void SetType(const int& InType) { mType = InType; }
		int GetType() const { return mType; }
	private:
		int mType;
	};
}

