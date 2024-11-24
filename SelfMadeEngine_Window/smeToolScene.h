#pragma once
#include "../SelfMadeEngine_SOURCE/smeScene.h"
#include "smeTile.h"
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

		void Save();
		void Load();

	private:
		std::vector<Tile*> mTiles;
	};
}

LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);