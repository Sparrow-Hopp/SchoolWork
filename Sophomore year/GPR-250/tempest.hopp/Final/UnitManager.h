#pragma once
#include <Trackable.h>
#include <Unit.h>
#include <Vector2D.h>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class UnitManager :
    public Trackable
{
    private:
        vector<Unit*> mUnitVector;
    public:
        UnitManager();
        ~UnitManager();
        void addUnit(Unit* unitToAdd);
        void delUnit(Unit* key);
        Unit* getUnit(Unit* key);
        void clear();
        void update(double deltatime);
        void draw();
        void stopAnimation();
        void swapToDean();
        void findAndDelete(Vector2D location);
};

