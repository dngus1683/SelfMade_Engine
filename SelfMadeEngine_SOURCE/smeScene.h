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

		// Scene�� �� �� ����.
		virtual void OnEnter();
		// Scene���� ���� �� ����.
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj, const enums::eLayerType type);
		Layer* GetLayer(const enums::eLayerType type) { return mLayers[(UINT)type]; }

	private:
		std::vector<Layer*> mLayers;
	};
}

