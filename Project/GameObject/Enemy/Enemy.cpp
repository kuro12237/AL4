#include "Enemy.h"

void Enemy::Initialize()
{
	model_ = make_unique<Model>();
	TexHandle_ = TextureManager::LoadTexture("Resources/Green.png");
	model_->SetTexHandle(TexHandle_);
	model_->Initialize(new ModelSphereState);
	
	worldTransform_.Initialize();
	worldTransform_.translate.z = 40;
	worldTransform_.UpdateMatrix();
	state_ =  new EnemyApprochState;
}

void Enemy::Update()
{
	state_->Update(this);
	worldTransform_.UpdateMatrix();
}

void Enemy::Draw(ViewProjection view)
{
	model_->Draw(worldTransform_, view);
}

void Enemy::ChangeState(IEnemyState* state)
{
	//delete state;
	this->state_ = state;
	return;
}
