#pragma once

#include "..\SelfMadeEngine_SOURCE\smeResources.h"
#include "..\SelfMadeEngine_SOURCE\smeTexture.h"

namespace sme
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"BG", L"D:/Study/SelfMadeEngine/ImageSource/CloudOcean.png");
		Resources::Load<graphics::Texture>(L"Pacman", L"D:/Study/SelfMadeEngine/ImageSource/pacman.png");
		Resources::Load<graphics::Texture>(L"Chickhen", L"D:/Study/SelfMadeEngine/ImageSource/ChickenAlpha.bmp");
		Resources::Load<graphics::Texture>(L"SkillEffect", L"D:/Study/SelfMadeEngine/ImageSource/SkillEffect.png");
		Resources::Load<graphics::Texture>(L"Player", L"D:/Study/SelfMadeEngine/ImageSource/Player.bmp");
		Resources::Load<graphics::Texture>(L"SpringFloor", L"D:/Study/SelfMadeEngine/ImageSource/SpringFloor.bmp");
	}
}