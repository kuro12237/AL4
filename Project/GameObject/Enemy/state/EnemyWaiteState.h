#pragma once
#include"IEnemyState.h"
#include"GameObject/Enemy/Enemy.h"

class EnemyWaiteState : public IEnemyState
{
public:

	~EnemyWaiteState() {};

	void Update(Enemy* enemy)override;

private:

};