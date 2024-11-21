#pragma once
#include "../SelfMadeEngine_SOURCE/smeScene.h"

namespace sme
{
	class ToolScene : public Scene
	{
	public:
		ToolScene();
		~ToolScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC mHdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
	};
}

LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);