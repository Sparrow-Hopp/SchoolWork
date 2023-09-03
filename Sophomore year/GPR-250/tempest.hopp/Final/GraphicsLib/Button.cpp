#include "Button.h"

Button::Button(GraphicsBuffer* background, string texts[3], Vector2D loc, Font* font)
{
	mpBackground = background;
	mpSmallFont = font;
	mLocation = loc;
	for (int i = 0; i < NUM_LANGUAGES; i++)
		mLocalText[i] = texts[i];
}

Button::~Button()
{
}

void Button::Draw()
{
	if (mShouldDraw)
	{
		GraphicsSystem::draw(mLocation, *mpBackground, 1);
		GraphicsSystem::writeText(mLocation, *mpSmallFont, Color(0, 0, 0, 255), mLocalText[mCurrentLanguage], Font::Alignment::LEFT);
	}
}

void Button::swapLanguage()
{
	mCurrentLanguage = (mCurrentLanguage + 1) % NUM_LANGUAGES;
}

bool Button::isPressed(Vector2D pressLoc)
{
	int buttonWidth = mpBackground->getWidth();
	int buttonHeight = mpBackground->getHeight();
	int buttonX = mLocation.getX();
	int buttonY = mLocation.getY();

	return (mShouldDraw && buttonX < pressLoc.getX() && buttonX + buttonWidth > pressLoc.getX()
		&& buttonY < pressLoc.getY() && buttonY + buttonHeight > pressLoc.getY());
}
