#include"PlayerBullet.h"

void PlayerBullet::Initialize(Vector3& position, const Vector3& velocity)
{
	model_ = make_unique<Model>();
	model_->Initialize(new ModelCubeState);
	modeltexHandle = TextureManager::LoadTexture("Resources/uvChecker.png");
	model_->SetTexHandle(modeltexHandle);
	worldTransform_.Initialize();
	worldTransform_.translate = position;
	velocity_ = velocity;
}

void PlayerBullet::Update()
{
	deathTimer_--;
	if (deathTimer_ <= 0)
	{
		isDead_ = true;
	}
	velocity_ = VectorTransform::Normalize(velocity_);
	velocity_ = VectorTransform::Multiply(velocity_, 0.4f);

	worldTransform_.translate = VectorTransform::Add(worldTransform_.translate, velocity_);
	worldTransform_.UpdateMatrix();
}

void PlayerBullet::Draw(const ViewProjection& viewProjection)
{
	model_->Draw(worldTransform_, viewProjection);
}
