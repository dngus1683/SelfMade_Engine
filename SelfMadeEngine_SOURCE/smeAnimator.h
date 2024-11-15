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
		* name: animation 객체 이름(= 키 값)
		* spriteSheet: Animation에 사용될 텍스쳐
		* leftTop: 이미지 파일에서 Animation에 사용할 시작위치
		* offset: 객체의 중심 좌표
		* size: 이미지 크기
		* spriteLength: 이미지를 자를 개수
		* duration: Animation 재생 반복 시간
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

