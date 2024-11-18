#pragma once 

namespace sme
{
	namespace enums
	{
		enum class eComponentType
		{
			Transform,
			SpriteRenderer,
			Animator,
			Script,
			Camera,
			End,
		};

		enum class eLayerType
		{
			None,
			BackGroud,
			Animal,
			Player,
			Particle,
			Max = 16,
		};

		enum class eResourceType
		{
			Texture,
			AudioClip,
			Animation,
			Prefab,
			End,
		};
	}
}