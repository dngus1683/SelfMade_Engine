#pragma once

#include "..\SelfMadeEngine_SOURCE\smeSceneManager.h"

#include "smePlayScene.h"
#include "smeTitleScene.h"

namespace sme
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");


		SceneManager::LoadScene(L"TitleScene");
	}
}