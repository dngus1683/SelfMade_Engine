#pragma once

#include "smeComponent.h"
#include "smeAnimation.h"

namespace sme
{
	class Animator : public Component
	{
	public:
		Animator();
		~Animator();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

		/*
		* name: animation ��ü �̸�(= Ű ��)
		* spriteSheet: Animation�� ���� �ؽ���
		* leftTop: �̹��� ���Ͽ��� Animation�� ����� ������ġ
		* offset: ��ü�� �߽� ��ǥ
		* size: �̹��� ũ��
		* spriteLength: �̹����� �ڸ� ����
		* duration: Animation ��� �ݺ� �ð�
		*/ 
		
		
		void CreateAnimation(const std::wstring& name
			, graphics::Texture* spriteSheet
			, Vector2 leftTop
			, Vector2 offset
			, Vector2 size
			, UINT spriteLength
			, float duration);
		Animation* FindAnimation(const std::wstring& name);
		void PlayAnimation(const std::wstring& name, bool loop = true);

	private:
		std::map<std::wstring, Animation*> mAnimations;
		Animation* mActiveAnimation;
		bool mbLoop;
	};

}

