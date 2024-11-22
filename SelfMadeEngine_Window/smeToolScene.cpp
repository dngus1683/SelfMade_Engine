#include "smeToolScene.h"
#include "smeObject.h"
#include "smeTile.h"
#include "smeTileMapRenderer.h"
#include "smeTexture.h"
#include "smeResources.h"
#include "smeCamera.h"
#include "smeRenderer.h"
#include "smeInput.h"

namespace sme
{
	ToolScene::ToolScene()
	{
	}
	ToolScene::~ToolScene()
	{
	}
	void ToolScene::Initialize()
	{
		// main camera
		GameObject* camera = Instantiate<GameObject>(enums::eLayerType::None, Vector2(336.f, 423.f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		Tile* tile = Instantiate<Tile>(enums::eLayerType::Tile);
		TileMapRenderer* tmr = tile->AddComponent<TileMapRenderer>();
		tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));

		Scene::Initialize();
	}
	void ToolScene::Update()
	{
		Scene::Update();
	}
	void ToolScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::LButton))
		{
			Vector2 pos = Input::GetMousePosition();
			
			int idxX = pos.x / TileMapRenderer::TileSize.x;
			int idxY = pos.y / TileMapRenderer::TileSize.y;

			Tile* tile = Instantiate<Tile>(enums::eLayerType::Tile);
			TileMapRenderer* tmr = tile->AddComponent<TileMapRenderer>();
			tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));
			tmr->SetIndex(TileMapRenderer::SelectedIndex);

			tile->SetPosition(idxX, idxY);
		}
	}
	void ToolScene::Render(HDC mHdc)
	{
		Scene::Render(mHdc);

		for (size_t i = 0; i < 50; i++)
		{
			MoveToEx(mHdc, TileMapRenderer::TileSize.x * i, 0, NULL);
			LineTo(mHdc, TileMapRenderer::TileSize.x * i, 1000);
		}

		for (size_t i = 0; i < 50; i++)
		{
			MoveToEx(mHdc, 0, TileMapRenderer::TileSize.y * i, NULL);
			LineTo(mHdc, 1000, TileMapRenderer::TileSize.y * i);
		}
	}
	void ToolScene::OnEnter()
	{
		Scene::OnEnter();
	}
	void ToolScene::OnExit()
	{
		Scene::OnExit();
	}


}

LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
		POINT mousePos = {};
		GetCursorPos(&mousePos);
		ScreenToClient(hWnd, &mousePos);

		sme::math::Vector2 mousePosition;
		mousePosition.x = mousePos.x;
		mousePosition.y = mousePos.y;

		int idxX = mousePosition.x / sme::TileMapRenderer::OriginTileSize.x;
		int idxY = mousePosition.y / sme::TileMapRenderer::OriginTileSize.y;

		sme::TileMapRenderer::SelectedIndex = sme::math::Vector2(idxX, idxY);
		
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code that uses hdc here...
		sme::graphics::Texture* texture
			= sme::Resources::Find<sme::graphics::Texture>(L"SpringFloor");
		TransparentBlt(hdc
			, 0
			, 0
			, texture->GetWidth()
			, texture->GetHeight()
			, texture->GetHdc()
			, 0
			, 0
			, texture->GetWidth()
			, texture->GetHeight()
			, RGB(255, 0, 255));


		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}