#pragma once
#include"Model.h"
#include"state/EnemyApprochState.h"
#include"state/EnemyLeaveState.h"

class Enemy
{
public:
	Enemy() {};
	~Enemy() {};

	void Initialize();

	void Update();
	
	void Draw(ViewProjection view);

#pragma region Set

	void SetWorldTranslate(Vector3 t) { worldTransform_.translate = t; }

#pragma endregion
#pragma region get

	WorldTransform GetWorldTransform() { return worldTransform_; }
#pragma endregion

	void ChangeState(IEnemyState* state);

private:

	unique_ptr<Model>model_ = nullptr;
	WorldTransform worldTransform_{};
	uint32_t TexHandle_ = 0;

	IEnemyState* state_ = nullptr;

};
