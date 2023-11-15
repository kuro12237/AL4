#pragma once
#include"Model.h"
#include"state/EnemyApprochState.h"
#include"state/EnemyLeaveState.h"
#include"state/EnemyWaiteState.h"
#include"GameObject/Enemy/Bullet/EnemyBullet.h"

enum EnemyState
{
	WAITE,
	MOVE
};

class Enemy
{
public:
	Enemy() {};
	~Enemy() {};

	void Initialize(EnemyState s,Vector3 t);

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

	void Attack();

	unique_ptr<Model>model_ = nullptr;
	WorldTransform worldTransform_{};
	uint32_t TexHandle_ = 0;

	IEnemyState* state_ = nullptr;
	list<shared_ptr<EnemyBullet>>bullets_ = {};

	uint32_t bulletTimer = 0;

};
