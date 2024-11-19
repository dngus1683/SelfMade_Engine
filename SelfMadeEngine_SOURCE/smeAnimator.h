#pragma once

#include "smeComponent.h"
#include "smeAnimation.h"

namespace sme
{
	class Animator : public Component
	{
	public:
		struct Event
		{
			void operator= (std::function<void()> func)
			{
				mEvent = std::move(func);
			}

			void operator() ()
			{
				if (mEvent)
					mEvent();
			}
			std::function<void()> mEvent;
		};
		struct Events
		{
			Event startEvent;
			Event completeEvent;
			Event endEvent;
		};


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
		void CreateAnimationByFolder(const std::wstring& name
			, const std::wstring& path
			, Vector2 offset
			, float duration);

		Animation* FindAnimation(const std::wstring& name);
		void PlayAnimation(const std::wstring& name, bool loop = true);

		Events* FindEvents(const std::wstring& name);
		std::function<void()>& GetStartEvent(const std::wstring& name);
		std::function<void()>& GetCompleteEvent(const std::wstring& name);
		std::function<void()>& GetEndEvent(const std::wstring& name);


		bool IsComplete() { return mActiveAnimation->IsComplete(); }

	private:
		std::map<std::wstring, Animation*> mAnimations;
		Animation* mActiveAnimation;
		bool mbLoop;

		// Event
		std::map<std::wstring, Events*> mEvents;
	};

}

