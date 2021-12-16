#include "UnitManager.h"

UnitManager::UnitManager()
{
}

UnitManager::~UnitManager()
{
	for (int i = 0; i < mUnitVector.size(); i++)
		delete mUnitVector[i];
	mUnitVector.clear();
}

void UnitManager::addUnit(Unit* unitToAdd)
{
	mUnitVector.push_back(unitToAdd);
}

void UnitManager::delUnit(Unit* key)
{
	delete getUnit(key);
	for (auto i = mUnitVector.begin(); i != mUnitVector.end(); ++i)
	{
		if (*i == key)
		{
			mUnitVector.erase(i);
			return;
		}
	}
}

Unit* UnitManager::getUnit(Unit* key)
{
	for (auto i = mUnitVector.begin(); i != mUnitVector.end(); ++i)
	{
		if (*i == key)
			return *i;
	}
}

void UnitManager::clear()
{
	for (int i = 0; i < mUnitVector.size(); i++)
		delete mUnitVector[i];
	mUnitVector.clear();
}

void UnitManager::update(double deltatime)
{
	for (int i = 0; i < mUnitVector.size(); i++)
		mUnitVector[i]->Update(deltatime);
}

void UnitManager::draw()
{
	for (int i = 0; i < mUnitVector.size(); i++)
		mUnitVector[i]->Draw();
}

void UnitManager::stopAnimation()
{
	for (int i = 0; i < mUnitVector.size(); i++)
		mUnitVector[i]->shouldAnimate();
}

void UnitManager::swapToDean()
{
	mUnitVector[mUnitVector.size() - 1]->setAnimation();
}

void UnitManager::findAndDelete(Vector2D location)
{
	for (int i = 0; i < mUnitVector.size(); i++)
	{
		if ((mUnitVector[i]->getLocation().getX() < location.getX() 
			&& mUnitVector[i]->getLocation().getX() + 32 > location.getX())
			&& (mUnitVector[i]->getLocation().getY() < location.getY() 
				&& mUnitVector[i]->getLocation().getY() + 60 > location.getY()))
		{
			delUnit(mUnitVector[i]);
			return;
		}
	}
}
