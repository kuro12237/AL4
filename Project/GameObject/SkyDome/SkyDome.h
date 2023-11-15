#pragma once
#include"Model.h"

class SkyDome
{
public:
	SkyDome() {};
	~SkyDome() {};

	void initialize();

	void Update();

	void Draw(ViewProjection view);

private:

	unique_ptr<Model>model_ = nullptr;
	WorldTransform worldTransform_{};
};

