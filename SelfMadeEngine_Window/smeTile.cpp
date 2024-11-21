#include "smeTile.h"
#include "smeInput.h"
#include "smeTransform.h"
#include "smeTime.h"
#include "smeTileMapRenderer.h"

namespace sme
{
	void Tile::Initialize()
	{
		GameObject::Initialize();
	}

	void Tile::Update()
	{
		GameObject::Update();
	}

	void Tile::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Tile::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Tile::SetPosition(int x, int y)
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos;
		pos.x = x * TileMapRenderer::TileSize.x;
		pos.y = y * TileMapRenderer::TileSize.y;
		tr->SetPosition(Vector2(pos.x, pos.y));
	}
}
