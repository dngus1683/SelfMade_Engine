#include "smeCollisionManager.h"
#include "smeScene.h"
#include "smeSceneManager.h"
#include "smeGameObject.h"
#include "smeCollider.h"
#include "smeTransform.h"

namespace sme
{
	std::bitset<(UINT)enums::eLayerType::Max> CollisionManager::mCollisionLayerMatrix[(UINT)enums::eLayerType::Max] = {};
	std::unordered_map<UINT64, bool> CollisionManager::mCollisionMap = {};

	void CollisionManager::Initialize()
	{
	}
	void CollisionManager::Update()
	{
		Scene* scene = SceneManager::GetActiveScene();
		for (UINT row = 0; row < (UINT)eLayerType::Max; row++)
		{
			for (UINT col = 0; col < (UINT)eLayerType::Max; col++)
			{
				if (mCollisionLayerMatrix[row][col] == true)
				{
					LayerCollision(scene, (eLayerType)row, (eLayerType)col);
				}
			}
		}
	}
	void CollisionManager::LateUpdate()
	{
	}
	void CollisionManager::Render(HDC hdc)
	{
	}
	void CollisionManager::CollisionLayerCheck(eLayerType left, eLayerType right, bool enable)
	{
		int row = 0;
		int col = 0;

		if (left <= right)
		{
			row = (UINT)left;
			col = (UINT)right;
		}
		else
		{
			row = (UINT)right;
			col = (UINT)left; 
		}

		mCollisionLayerMatrix[row][col] = enable;

	}
	void CollisionManager::LayerCollision(Scene* scene, eLayerType left, eLayerType right)
	{
		const std::vector<GameObject*>& lefts = scene->GetLayer(left)->GetGameObjects();
		const std::vector<GameObject*>& rights = scene->GetLayer(right)->GetGameObjects();

		for (GameObject* left : lefts)
		{
			if (left->IsActive() == false)
			{
				continue;
			}

			Collider* leftCol = left->GetComponent<Collider>();
			if (leftCol == nullptr)
			{
				continue;
			}
			for (GameObject* right : rights)
			{
				if (right->IsActive() == false)
				{
					continue;
				}

				Collider* rightCol = right->GetComponent<Collider>();
				if (rightCol == nullptr)
				{
					continue;
				}
				if (left == right)
				{
					continue;
				}
				ColliderCollision(leftCol, rightCol);
			}
		}

	}
	void CollisionManager::ColliderCollision(Collider* left, Collider* right)
	{
		CollisionID id = {};
		id.left = left->GetID();
		id.right = right->GetID();

		auto iter = mCollisionMap.find(id.id);
		if (iter == mCollisionMap.end())
		{
			mCollisionMap.insert({ id.id, false });
			iter = mCollisionMap.find(id.id);
		}
		
		// 충돌 체크
		if (Intersect(left, right))
		{
			// 처음 충돌했을 때
			if (iter->second == false)
			{
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);
				iter->second = true;
			}
			// 이미 충돌 중일 때
			else
			{
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}
		}
		else
		{
			// 충돌 중에서 벗어났을 때
			if (iter->second == true)
			{
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);
				iter->second = false;
			}
		}
	}
	bool CollisionManager::Intersect(Collider* left, Collider* right)
	{
		Transform* leftTr = left->GetOwner()->GetComponent<Transform>();
		Transform* rightTr = right->GetOwner()->GetComponent<Transform>();

		Vector2 leftPos = leftTr->GetPosition() + left->GetOffset();
		Vector2 rightPos = rightTr->GetPosition() + right->GetOffset();

		// size 1,1 일 기본 크기가 100 픽셀
		Vector2 leftSize = left->GetSize() * 100.f;
		Vector2 rightSize = right->GetSize() * 100.f;

		// AABB 충돌
		enums::eColliderType leftType = left->GetColliderType();
		enums::eColliderType rightType = right->GetColliderType();

		if (leftType == enums::eColliderType::Rect2D
			&& rightType == enums::eColliderType::Rect2D)
		{
			if (fabs(leftPos.x - rightPos.x) < fabs(leftSize.x / 2.f + rightSize.x / 2.f)
				&& fabs(leftPos.y - rightPos.y) < fabs(leftSize.y / 2.f + rightSize.y / 2.f))
			{
				return true;
			}

		}
		if (leftType == enums::eColliderType::Circle2D
			&& rightType == enums::eColliderType::Circle2D)
		{
			Vector2 leftCirclePos = leftPos + (leftSize / 2.f);
			Vector2 rightCirclePos = rightPos + (rightSize / 2.f);

			float distance = (leftCirclePos - rightCirclePos).length();
			if (distance <= (leftSize.x/2.f + rightSize.x /2.f))
			{
				return true;
			}
		}


		return false;
	}
}