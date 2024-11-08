#pragma once

#include "..\SelfMadeEngine_SOURCE\smeSceneManager.h"
#include "smePlayScene.h"

namespace sme
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}