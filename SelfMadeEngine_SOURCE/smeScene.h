#pragma once

#include "CommonInclude.h"
#include "smeEntity.h"
#include "smeGameObject.h"
#include "smeLayer.h"

namespace sme
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC mHdc);

		// Scene에 들어갈 때 설정.
		virtual void OnEnter();
		// Scene에서 나올 때 설정.
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj, const enums::eLayerType type);
		Layer* GetLayer(const enums::eLayerType type) { return mLayers[(UINT)type]; }

	private:
		std::vector<Layer*> mLayers;
	};
}

