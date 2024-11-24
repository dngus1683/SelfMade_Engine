#pragma once

#include "..\SelfMadeEngine_SOURCE\smeSceneManager.h"

#include "smePlayScene.h"
#include "smeTitleScene.h"
#include "smeToolScene.h"

namespace sme
{
	void LoadScenes()
	{
		//SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<ToolScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}