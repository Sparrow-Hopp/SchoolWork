#include "GraphicsBufferManager.h"

GraphicsBufferManager::GraphicsBufferManager()
{
}

GraphicsBufferManager::~GraphicsBufferManager()
{
	map<string, GraphicsBuffer*>::iterator itr;
	for (itr = mGraphicsBufferMap.begin(); itr != mGraphicsBufferMap.end(); ++itr)
		delete itr->second;
	mGraphicsBufferMap.clear();
}

void GraphicsBufferManager::addBuffer(string key, GraphicsBuffer* bufferToAdd)
{
	mGraphicsBufferMap[key] = bufferToAdd;
}

void GraphicsBufferManager::delBuffer(string key)
{
	delete getBuffer(key);
	mGraphicsBufferMap.erase(key);
}

GraphicsBuffer* GraphicsBufferManager::getBuffer(string key)
{
	return mGraphicsBufferMap[key];
}

void GraphicsBufferManager::clear()
{
	map<string, GraphicsBuffer*>::iterator itr;
	for (itr = mGraphicsBufferMap.begin(); itr != mGraphicsBufferMap.end(); ++itr)
		delBuffer(itr->first);
}
