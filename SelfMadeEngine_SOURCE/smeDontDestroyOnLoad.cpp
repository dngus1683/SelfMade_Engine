#include "smeDontDestroyOnLoad.h"

namespace sme
{
	DontDestroyOnLoad::DontDestroyOnLoad()
	{
	}
	DontDestroyOnLoad::~DontDestroyOnLoad()
	{
	}
	void DontDestroyOnLoad::Initialize()
	{
		Scene::Initialize();
	}
	void DontDestroyOnLoad::Update()
	{
		Scene::Update();
	}
	void DontDestroyOnLoad::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void DontDestroyOnLoad::Render(HDC mHdc)
	{
		Scene::Render(mHdc);
	}
	void DontDestroyOnLoad::OnEnter()
	{

	}
	void DontDestroyOnLoad::OnExit()
	{
	}
}