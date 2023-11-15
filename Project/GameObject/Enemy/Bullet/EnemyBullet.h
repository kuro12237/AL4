#pragma once
#include"Model.h"
#include"VectorTransform.h"

class EnemyBullet
{
public:
	EnemyBullet() {};
	~EnemyBullet() {};


	void Initialize(Vector3 t,Vector3 v);

	void Update();

	void Draw(ViewProjection view);

private:

	unique_ptr<Model>model_ = nullptr;
	WorldTransform worldTransform_{};
	Vector3 velocity_ = {};

};


