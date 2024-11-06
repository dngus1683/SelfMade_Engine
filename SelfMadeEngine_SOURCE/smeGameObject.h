#pragma once

#include "CommonInclude.h"

namespace sme
{
	class GameObject
	{
	public:
		GameObject();
		GameObject(float InX, float InY, int InType);
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC mHdc);


		void SetPosition(const float& x, const float& y)
		{
			mX = x;
			mY = y;
		}
		const float GetPositionX() const 
		{
			return mX;
		}
		const float GetPositionY() const
		{
			return mY;
		}


		void SetType(const int& InType)
		{
			mType = InType;
		}
		const int GetType() const
		{
			return mType;
		}

	private:

		// ���� ������Ʈ ��ǥ
		float mX; 
		float mY;

		// ���� ������Ʈ ����
		int mType;
	};
}