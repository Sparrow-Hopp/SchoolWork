#include "Unit.h"

Unit::Unit()
{
	mpDeanAnim = new Animation();
	mpSmurfAnim = new Animation();
	mSmurfRunning = true;
	mLocation = Vector2D(0, 0);
}

Unit::Unit(Sprite deanSprites[], Sprite smurfSprites[], Vector2D loc)
{
	mpDeanAnim = new Animation(deanSprites, 16);
	mpSmurfAnim = new Animation(smurfSprites, 16);
	mSmurfRunning = true;
	mLocation = loc;
}

Unit::~Unit()
{
	delete mpDeanAnim;
	delete mpSmurfAnim;
}

void Unit::Update(int deltaTime)
{
	mpDeanAnim->Update(deltaTime);
	mpSmurfAnim->Update(deltaTime);
}

void Unit::Draw()
{
	if (mSmurfRunning)
		GraphicsSystem::draw(mLocation, mpSmurfAnim->getCurrentSprite(), 1);
	else
		GraphicsSystem::draw(mLocation, mpDeanAnim->getCurrentSprite(), 1);
}

void Unit::setAnimation()
{
	if (mSmurfRunning)
		mSmurfRunning = false;
	else
		mSmurfRunning = true;
}

void Unit::changeSpeed(int speedModifier)
{
	mpDeanAnim->changeSpeed(speedModifier);
	mpSmurfAnim->changeSpeed(speedModifier);
}

void Unit::setLocation(Vector2D newLoc)
{
	mLocation = newLoc;
}
