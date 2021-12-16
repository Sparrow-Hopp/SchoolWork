#pragma once
#include <Trackable.h>
#include "GraphicsBuffer.h"
#include <Vector2D.h>
#include <iostream>
#include <iterator>
#include <map>

using namespace std; 

class GraphicsBufferManager :
    public Trackable
{
    private:
        map <string, GraphicsBuffer*> mGraphicsBufferMap;
    public:
        GraphicsBufferManager();
        ~GraphicsBufferManager();
        void addBuffer(string key, GraphicsBuffer* bufferToAdd);
        void delBuffer(string key);
        GraphicsBuffer* getBuffer(string key);
        void clear();
};

