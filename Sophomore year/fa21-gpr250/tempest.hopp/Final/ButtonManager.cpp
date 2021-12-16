#include "ButtonManager.h"

ButtonManager::ButtonManager()
{
}

ButtonManager::~ButtonManager()
{
	map<string, Button*>::iterator itr;
	for (itr = mButtonMap.begin(); itr != mButtonMap.end(); ++itr)
		delete itr->second;
	mButtonMap.clear();
}

void ButtonManager::addButton(string key, Button* buttonToAdd)
{
	mButtonMap[key] = buttonToAdd;
}

void ButtonManager::delButton(string key)
{
	delete getButton(key);
	mButtonMap.erase(key);
}

Button* ButtonManager::getButton(string key)
{
	return mButtonMap[key];
}

void ButtonManager::clear()
{
	map<string, Button*>::iterator itr;
	for (itr = mButtonMap.begin(); itr != mButtonMap.end(); ++itr)
		delButton(itr->first);
}

void ButtonManager::draw()
{
	map<string, Button*>::iterator itr;
	for (itr = mButtonMap.begin(); itr != mButtonMap.end(); ++itr)
		itr->second->Draw();
}

void ButtonManager::swapLanguage()
{
	map<string, Button*>::iterator itr;
	for (itr = mButtonMap.begin(); itr != mButtonMap.end(); ++itr)
		itr->second->swapLanguage();
}
