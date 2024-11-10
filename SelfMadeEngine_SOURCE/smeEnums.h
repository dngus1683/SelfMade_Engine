#pragma once 

namespace sme
{
	namespace enums
	{
		enum class eLayerType
		{
			None,
			BackGroud,
			Player,
			Max = 16,
		};

		enum class eResourceType
		{
			Texture,
			AudioClip,
			Prefab,
			End,
		};
	}
}