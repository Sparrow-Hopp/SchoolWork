#include "FruitManager.h"

FruitManager::FruitManager()
{
}

FruitManager::~FruitManager()
{
	for (int i = 0; i < mFruitVector.size(); i++)
		delete mFruitVector[i];
	mFruitVector.clear();
}

void FruitManager::addFruit(Fruit* fruitToAdd, string file_location)
{
	mFruitVector.push_back(fruitToAdd);
	fruitToAdd->init(file_location);
	fruitToAdd->playAudio();
}

void FruitManager::delFruit(Fruit* fruitToDelete)
{
	delete getFruit(fruitToDelete);
	for (auto i = mFruitVector.begin(); i != mFruitVector.end(); ++i)
	{
		if (*i == fruitToDelete)
		{
			mFruitVector.erase(i);
			return;
		}
	}
}

Fruit* FruitManager::getFruit(Fruit* key)
{
	for (auto i = mFruitVector.begin(); i != mFruitVector.end(); ++i)
	{
		if (*i == key)
			return *i;
	}
}

void FruitManager::clear()
{
	for (int i = 0; i < mFruitVector.size(); i++)
		delete mFruitVector[i];
	mFruitVector.clear();
}

void FruitManager::update(double deltatime)
{
	for (int i = 0; i < mFruitVector.size(); i++)
		mFruitVector[i]->Update(deltatime);
}

void FruitManager::draw()
{
	for (int i = 0; i < mFruitVector.size(); i++)
		mFruitVector[i]->Draw();
}

void FruitManager::checkForCollisions(Player* player)
{
	int playerX = player->getLocation().getX();
	int playerY = player->getLocation().getY();
	int playerWidth = 90;
	int playerHeight = 150;
	for (int i = 0; i < mFruitVector.size(); i++)
	{
		if ((mFruitVector[i]->getLocation().getX() < playerX && mFruitVector[i]->getLocation().getX() + mFruitVector[i]->getWidth() > playerX
			|| mFruitVector[i]->getLocation().getX() < playerX + 45 && mFruitVector[i]->getLocation().getX() + mFruitVector[i]->getWidth() > playerX + 45)
			&& mFruitVector[i]->getLocation().getY() < playerY
			&& mFruitVector[i]->getLocation().getY() + mFruitVector[i]->getHeight() > playerY)
			delFruit(mFruitVector[i]);
		else if (mFruitVector[i]->getLocation().getY() + mFruitVector[i]->getHeight() >= 600)
		{
			player->dockLife();
			delFruit(mFruitVector[i]);
		}
	}
}
