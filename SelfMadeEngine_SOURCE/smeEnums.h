#pragma once 

namespace sme
{
	namespace enums
	{
		enum class eComponentType
		{
			Transform,
			Collider,
			Rigidbody,
			Script,
			SpriteRenderer,
			Animator,
			Camera,
			End,
		};

		enum class eColliderType
		{
			 Rect2D,
			 Circle2D,
			 End,
		};

		enum class eLayerType
		{
			None,
			BackGroud,
			Tile,
			Animal,
			Player,
			Floor,
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

		enum class eUIType
		{
			HpBar,
			Button,
			End
		};
	}
}