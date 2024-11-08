#pragma once
#include "../SelfMadeEngine_SOURCE/smeScene.h"

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
	private:

	};
}

