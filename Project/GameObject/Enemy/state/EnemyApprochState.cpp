#include "EnemyApprochState.h"

void EnemyApprochState::Update(Enemy* state)
{
	const float kSpeed = -0.1f;
	velocity.z = kSpeed;

	Vector3 translate = state->GetWorldTransform().translate;
	translate = VectorTransform::Add(translate, velocity);
	state->SetWorldTranslate(translate);

	if (state->GetWorldTransform().translate.z < 0.0f)
	{
		state->ChangeState(new EnemyLeaveState);
	}

}
