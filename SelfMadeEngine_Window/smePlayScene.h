#pragma once
#include "../SelfMadeEngine_SOURCE/smeScene.h"
#include "../SelfMadeEngine_SOURCE/smeCollisionManager.h"

namespace sme
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC mHdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		class Player* mPlayer;
	};
}

