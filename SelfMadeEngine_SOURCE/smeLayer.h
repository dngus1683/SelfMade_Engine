#pragma once

#include "smeEntity.h"
#include "CommonInclude.h"
#include "smeGameObject.h"

namespace sme
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC mHdc);
		virtual void Destroy();
		
		void EraseGameObject(GameObject* eraseGameObject);
		void AddGameObject(GameObject* gameObject);
		const std::vector<GameObject*> GetGameObjects() { return mGameObjects; }
	private:
		enums::eLayerType mType;
		std::vector<GameObject*> mGameObjects;
	};
}

