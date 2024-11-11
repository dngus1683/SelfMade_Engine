#pragma once

#include "..\SelfMadeEngine_SOURCE\smeResources.h"
#include "..\SelfMadeEngine_SOURCE\smeTexture.h"

namespace sme
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"BG", L"D:/Study/SelfMadeEngine/ImageSource/CloudOcean.png");
		Resources::Load<graphics::Texture>(L"Pacman", L"D:/Study/SelfMadeEngine/ImageSource/pacman.png");
	}
}