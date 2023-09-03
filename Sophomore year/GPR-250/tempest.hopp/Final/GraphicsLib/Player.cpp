#include "Player.h"

Player::Player(GraphicsBuffer* sprite, Vector2D location, Font* font)
{
	mTimeUntilSecond = mSecondInFrames;
	mpSmallFont = font;
	mpSprite = sprite;
	mLocation = location;
	mMaxTime = 10;
	mTime = mMaxTime;
}

void Player::Draw()
{
	GraphicsSystem::draw(mLocation, *mpSprite);
	GraphicsSystem::writeText(Vector2D(50, 25), *mpSmallFont, Color(0, 0, 0, 255), to_string(mLives) + " lives", Font::Alignment::LEFT);
	GraphicsSystem::writeText(Vector2D(750, 25), *mpSmallFont, Color(0, 0, 0, 255), to_string(mTime), Font::Alignment::RIGHT);

}

void Player::Update()
{
	mTimeUntilSecond -= 1;
	if (mTimeUntilSecond <= 0)
	{
		mTimeUntilSecond = mSecondInFrames;
		mTime--;			
	}
}

void Player::restart()
{
	mLives = MAX_LIVES;
	mTime = mMaxTime;
}

void Player::levelUp()
{
	mMaxTime += 5;
}
