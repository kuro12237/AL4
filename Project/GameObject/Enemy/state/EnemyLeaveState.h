#pragma once
#include"IEnemyState.h"
#include"GameObject/Enemy/Enemy.h"
#include"VectorTransform.h"

class EnemyLeaveState : public IEnemyState
{
public:
	~EnemyLeaveState() {};

	void Update(Enemy * state)override;

private:

	Vector3 velocity = {};

};