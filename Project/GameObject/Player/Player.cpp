#include"Player.h"

void Player::Initialize()
{
	model_ = make_unique<Model>();
	model_->Initialize(new ModelSphereState);
	lineModel_ = make_unique<Model>();
	lineModel_->Initialize(new ModelLineState,{0,0,0,1},{0,0,1.0f,1});

	texHandle_ = TextureManager::LoadTexture("Resources/uvChecker.png");
	model_->SetTexHandle(texHandle_);
	worldTransform_.Initialize();
	
	lineWorldTransform_.parent = &worldTransform_;
}

void Player::Update()
{
	keyControl();
	Attack();
	BulletsUpdate();

	worldTransform_.UpdateMatrix();
	lineWorldTransform_.UpdateMatrix();
}

void Player::Draw(ViewProjection view)
{
	for (shared_ptr<PlayerBullet>& bullet : bullets_)
	{
		bullet->Draw(view);
	}

	model_->Draw(worldTransform_, view);
	lineModel_->Draw(lineWorldTransform_, view);
}

void Player::Attack()
{
	if (Input::GetInstance()->PushKeyPressed(DIK_SPACE))
	{
		const float kbulletSpeed = 1.0f;
		Vector3 velocity = { 0,0,kbulletSpeed };
		velocity = VectorTransform::TransformNormal(velocity, worldTransform_.matWorld);

		shared_ptr<PlayerBullet>bullet = make_shared<PlayerBullet>();
		bullet->Initialize(worldTransform_.translate, velocity);
		bullets_.push_back(bullet);
	}
}

void Player::keyControl()
{
	if (Input::GetInstance()->PushKey(DIK_W))
	{
		worldTransform_.translate.y += kPlayerSpeed_;
	}else if (Input::GetInstance()->PushKey(DIK_S))
	{
		worldTransform_.translate.y -= kPlayerSpeed_;
	}

	if (Input::GetInstance()->PushKey(DIK_A))
	{
		worldTransform_.translate.x -= kPlayerSpeed_;
	}
	else if (Input::GetInstance()->PushKey(DIK_D))
	{
		worldTransform_.translate.x += kPlayerSpeed_;
	}

	//rotate
	if (Input::GetInstance()->PushKey(DIK_LEFT))
	{
		worldTransform_.rotation.y += kPlayerSpeed_;
	}else if (Input::GetInstance()->PushKey(DIK_RIGHT))
	{
		worldTransform_.rotation.y -= kPlayerSpeed_;
	}

}

void Player::BulletsUpdate()
{
	bullets_.remove_if([](shared_ptr<PlayerBullet> bullet) {
		if (bullet->IsDead()) {
			bullet.reset();
			return true;
		}
		return false;
		});

	for (shared_ptr<PlayerBullet>& bullet : bullets_)
	{
		bullet->Update();
	}
}
