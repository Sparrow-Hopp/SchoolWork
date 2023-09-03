#include "Animation.h"

Animation::Animation()
{
	mpSprites = new Sprite[SPRITE_LIST_LENGTH];
	mTimeUntilNextFrame = 0;
	mCurrentSprite = 0;
	mFramesPerSecond = 0;
	msPerFrame = 0;
}

Animation::Animation(Sprite sprites[], int count)
{
	mpSprites = new Sprite[count];
	for (int i = 0; i < count; i++)
		mpSprites[i] = sprites[i];
	mFramesPerSecond = 60;
	mTimeUntilNextFrame = mFramesPerSecond;
	mCurrentSprite = 0;
	msPerFrame = 180;
}

Animation::~Animation()
{
	delete [] mpSprites;
}

void Animation::Update(int deltaTime)
{
	mTimeUntilNextFrame -= deltaTime;
	if (mTimeUntilNextFrame <= 0)
	{
		mTimeUntilNextFrame = msPerFrame;
		if (mCurrentSprite != SPRITE_LIST_LENGTH - 1)
			mCurrentSprite++;
		else
			mCurrentSprite = 0;
	}
}

Sprite Animation::getCurrentSprite()
{
	return mpSprites[mCurrentSprite];
}

void Animation::changeSpeed(int speedModifier)
{
	msPerFrame += speedModifier;
}
