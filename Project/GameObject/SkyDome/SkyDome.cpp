#include "SkyDome.h"

void SkyDome::initialize()
{
	model_ = make_unique<Model>();
	model_->CreateFromObj("SkyDome");


	worldTransform_.Initialize();
}

void SkyDome::Update()
{
	worldTransform_.UpdateMatrix();
}

void SkyDome::Draw(ViewProjection view)
{
	model_->Draw(worldTransform_, view);
}
