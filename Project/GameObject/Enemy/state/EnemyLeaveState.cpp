#include"EnemyLeaveState.h"

void EnemyLeaveState::Update(Enemy *state)
{
	const float kSpeed = -0.1f;
	velocity.z = kSpeed;
	velocity.y = kSpeed * -1;
	velocity.x = kSpeed;


	Vector3 translate = state->GetWorldTransform().translate;
	translate = VectorTransform::Add(translate, velocity);
	state->SetWorldTranslate(translate);

}