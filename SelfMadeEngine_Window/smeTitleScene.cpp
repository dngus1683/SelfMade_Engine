#include "smeTitleScene.h"
#include "smeInput.h"
#include "smePlayScene.h"
#include "smeSceneManager.h"

namespace sme
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		Scene::Initialize();
	}
	void TitleScene::Update()
	{
		Scene::Update();
	}
	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}
	void TitleScene::Render(HDC mHdc)
	{
		Scene::Render(mHdc);
		wchar_t str[50] = L"Title Scene";
		TextOut(mHdc, 0, 0, str, wcsnlen_s(str, 50));
	}
}