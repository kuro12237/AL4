#include "Enemy.h"

void Enemy::Initialize(EnemyState s,Vector3 t)
{
	model_ = make_unique<Model>();
	TexHandle_ = TextureManager::LoadTexture("Resources/Green.png");
	model_->SetTexHandle(TexHandle_);
	model_->Initialize(new ModelSphereState);

	worldTransform_.Initialize();
	worldTransform_.translate = t;
	worldTransform_.UpdateMatrix();
	if (s == WAITE)
	{
		state_ = new EnemyWaiteState();
	}
	if (s == MOVE)
	{
		state_ = new EnemyApprochState;
	}
}

void Enemy::Update()
{
	state_->Update(this);
	
	for (shared_ptr<EnemyBullet>bullet : bullets_)
	{
		bullet->Update();
	}

	bulletTimer++;

	if (bulletTimer > 120)
	{
		Attack();
		bulletTimer = 0;
	}
	worldTransform_.UpdateMatrix();

}

void Enemy::Draw(ViewProjection view)
{
	model_->Draw(worldTransform_, view);
	for (shared_ptr<EnemyBullet>bullet : bullets_)
	{
		bullet->Draw(view);
	}

}

void Enemy::ChangeState(IEnemyState* state)
{
	//delete state;
	this->state_ = state;
	return;
}

void Enemy::Attack()
{
	shared_ptr<EnemyBullet>b1 = make_shared<EnemyBullet>();

	b1->Initialize(worldTransform_.translate, { 0,0,-1 });
	bullets_.push_back(b1);
}
