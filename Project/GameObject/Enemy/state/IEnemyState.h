#pragma once

class Enemy;
class IEnemyState
{
public:
	virtual ~IEnemyState() {};

	virtual void Update(Enemy * state) = 0;
private:

};