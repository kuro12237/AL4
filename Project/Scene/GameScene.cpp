#include "GameScene.h"

void GameScene::Initialize()
{
	viewProjection_.Initialize();
	player_ = make_unique<Player>();
	player_->Initialize();

}

void GameScene::Update(GameManager* Scene)
{
	Scene;
	player_->Update();
	viewProjection_.UpdateMatrix();
}

void GameScene::Back2dSpriteDraw()
{
}

void GameScene::Object3dDraw()
{
	player_->Draw(viewProjection_);
}

void GameScene::Flont2dSpriteDraw()
{
}
