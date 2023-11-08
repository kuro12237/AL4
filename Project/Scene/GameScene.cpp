#include "GameScene.h"

void GameScene::Initialize()
{
	viewProjection_.Initialize();
	viewProjection_.translation_.z = -20;
	viewProjection_.UpdateMatrix();

	player_ = make_unique<Player>();
	player_->Initialize();
	shared_ptr<Enemy>e1 = make_shared<Enemy>();
	e1->Initialize();
	enemys_.push_back(e1);

}

void GameScene::Update(GameManager* Scene)
{
	Scene;
	player_->Update();

	for (shared_ptr<Enemy>enemy : enemys_)
	{
		enemy->Update();
	}
	viewProjection_.UpdateMatrix();
}

void GameScene::Back2dSpriteDraw()
{
}

void GameScene::Object3dDraw()
{

	player_->Draw(viewProjection_);
	for (shared_ptr<Enemy>enemy : enemys_)
	{
		enemy->Draw(viewProjection_);
	}
}

void GameScene::Flont2dSpriteDraw()
{
}
