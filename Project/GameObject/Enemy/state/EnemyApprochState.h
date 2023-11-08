#pragma once
#include"IEnemyState.h"
#include"GameObject/Enemy/Enemy.h"
#include"GameObject/Enemy/state/EnemyLeaveState.h"

class EnemyApprochState:public IEnemyState
{
public:
	~EnemyApprochState() {};

	void Update(Enemy* state)override;

private:
	Vector3 velocity{};

};

