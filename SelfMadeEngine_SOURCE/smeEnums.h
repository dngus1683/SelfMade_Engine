#pragma once 

namespace sme
{
	namespace enums
	{
		enum class eComponentType
		{
			Transform,
			SpriteRenderer,
			Script,
			Camera,
			End,
		};

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