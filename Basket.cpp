
#include "Basket.h"


Basket::Basket()
	: Collidable(Texture::ID::Basket)
	, mCenter(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0)
	, MOVE_SPEED(100)
	, mPos(0, -(gApp->GetParam().BackBufferHeight / 2), 0)
	, goLeft(-1, 0, 0)
	, goRight(1, 0, 0)
	, movingRight(true)
	, screenWidth(gApp->GetParam().BackBufferWidth / 2)
{
	SetPivot(&mCenter);
	SetRotation(0, 0, D3DX_PI);
	SetPosition(0, -(gApp->GetParam().BackBufferHeight / 2));
}

Basket::~Basket()
{

}

void Basket::Update()
{
	float dt = gTimer->GetDeltaTime();

	Move(dt);
}

void Basket::Move(float dt)
{
	if (mPos.x <= -screenWidth + mCenter.x)
	{
		movingRight = true;
	}

	if (mPos.x <= screenWidth - mCenter.x && movingRight == true)
	{
		mPos.x += 1 * MOVE_SPEED * dt;
		SetPosition(mPos.x, -(gApp->GetParam().BackBufferHeight / 2));
	}
	else
	{
		mPos.x += -1 * MOVE_SPEED * dt;
		SetPosition(mPos.x, -(gApp->GetParam().BackBufferHeight / 2));
		movingRight = false;
	}
}