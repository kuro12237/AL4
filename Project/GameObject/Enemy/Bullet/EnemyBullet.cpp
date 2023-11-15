#include "EnemyBullet.h"

void EnemyBullet::Initialize(Vector3 t, Vector3 v)
{
	worldTransform_.Initialize();
	worldTransform_.translate = t;
	worldTransform_.UpdateMatrix();

	velocity_ = v;

	model_ = make_unique<Model>();
	model_->CreateFromObj("Bullet");
}

void EnemyBullet::Update()
{
	worldTransform_.translate = VectorTransform::Add(worldTransform_.translate, velocity_);
	worldTransform_.UpdateMatrix();
}

void EnemyBullet::Draw(ViewProjection view)
{
	model_->Draw(worldTransform_, view);
}
