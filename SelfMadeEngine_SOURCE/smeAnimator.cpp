#include "smeAnimator.h"


namespace sme
{
	Animator::Animator()
		: Component(enums::eComponentType::Animator)
		, mAnimations{}
		, mActiveAnimation(nullptr)
		, mbLoop(true)
	{
	}
	Animator::~Animator()
	{
		for (auto& iter : mAnimations)
		{
			delete iter.second;
			iter.second = nullptr;
		}

		for (auto& iter : mEvents)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
	void Animator::Initialize()
	{
	}
	void Animator::Update()
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Update();

			Events* events = FindEvents(mActiveAnimation->GetName());
			
			if (mActiveAnimation->IsComplete() == true)
			{
				if (events)
				{
					events->completeEvent();
				}
				if (mbLoop == true)
				{
					mActiveAnimation->Reset();
				}
			}
		}
	}
	void Animator::LateUpdate()
	{
	}
	void Animator::Render(HDC hdc)
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Render(hdc);
		}
	}
	void Animator::CreateAnimation(const std::wstring& name, graphics::Texture* spriteSheet
		, Vector2 leftTop, Vector2 offset, Vector2 size, UINT spriteLength, float duration)
	{
		Animation* animation = nullptr;

		animation = FindAnimation(name);
		if (animation != nullptr)
			return;

		animation = new Animation();
		animation->SetName(name);
		animation->CreateAnimation(name, spriteSheet, leftTop, offset, size, spriteLength
			, duration);
		animation->SetAnimator(this);

		Events* events = new Events();
		mEvents.insert({ name, events });

		mAnimations.insert({ name, animation });
	}
	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		auto iter = mAnimations.find(name);
		if (iter == mAnimations.end())
		{
			return nullptr;
		}

		return iter->second;
	}
	void Animator::PlayAnimation(const std::wstring& name, bool loop)
	{
		Animation* animation = FindAnimation(name);
		if (animation == nullptr)
		{
			return;
		}

		if (mActiveAnimation)
		{
			Events* currentEvents = FindEvents(mActiveAnimation->GetName());
			currentEvents->endEvent();

			if (currentEvents)
			{
				currentEvents->endEvent();
			}
		}

		Events* nextEvents = FindEvents(animation->GetName());
		nextEvents->startEvent();

		if (nextEvents)
		{
			nextEvents->startEvent();
		}

		mActiveAnimation = animation;
		mActiveAnimation->Reset();
		mbLoop = loop;
	}

	Animator::Events* Animator::FindEvents(const std::wstring& name)
	{
		auto iter = mEvents.find(name);
		if (iter == mEvents.end())
		{
			return nullptr;
		}

		return iter->second;
	}

	std::function<void()>& Animator::GetStartEvent(const std::wstring& name)
	{
		Events* events = FindEvents(name);
		return events->startEvent.mEvent;
	}

	std::function<void()>& Animator::GetCompleteEvent(const std::wstring& name)
	{
		Events* events = FindEvents(name);
		return events->completeEvent.mEvent;
	}

	std::function<void()>& Animator::GetEndEvent(const std::wstring& name)
	{
		Events* events = FindEvents(name);
		return events->endEvent.mEvent;
	}

}