#pragma once
#include"Model.h"
#include"Input.h"
#include"GameObject/Player/PlayerBullet.h"
#include"VectorTransform.h"
#include"MatrixTransform.h"

class Player {
public:
	Player() {};
	~Player() {};

	void Initialize();

	void Update();

	void Draw(ViewProjection view);

private:

	void Attack();

	void keyControl();

	void BulletsUpdate();

	Vector3 position_ = {};
	uint32_t texHandle_ = 0;
	unique_ptr<Model> model_ = nullptr;
	unique_ptr<Model> lineModel_ = nullptr;

	WorldTransform worldTransform_{};
	WorldTransform ReticleWorldTransform_{};
	WorldTransform lineWorldTransform_{};
	
	const float kPlayerSpeed_ = 0.05f;

	bool isFire = false;
	uint32_t FireCoolTime = 0;
	const uint32_t MaxFireCoolTime = 60;
	list<shared_ptr<PlayerBullet>> bullets_;
};


