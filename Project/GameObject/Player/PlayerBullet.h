#pragma once
#include "Model.h"

#include "WorldTransform.h"

class PlayerBullet {
public:
	PlayerBullet() {};
	~PlayerBullet() {};

	void Initialize(Vector3& position, const Vector3& velocity);

	void Update();

	void Draw(const ViewProjection& viewProjection);

	static const int32_t kLifeTime = 60 * 5;
	bool IsDead() const { return isDead_; }

private:

	uint32_t modeltexHandle= 0;
	unique_ptr<Model> model_ = nullptr;
	WorldTransform worldTransform_ = {};
	Vector3 velocity_{};

	int32_t deathTimer_ = kLifeTime;
	bool isDead_ = false;
};