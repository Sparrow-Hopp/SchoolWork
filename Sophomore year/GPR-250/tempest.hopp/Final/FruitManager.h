#pragma once
#include <Trackable.h>
#include "Fruit.h"
#include <iostream>
#include <iterator>
#include <vector>
#include "Player.h"

using namespace std;


class FruitManager :
    public Trackable
{
    private:
        vector<Fruit*> mFruitVector;
    public:
        FruitManager();
        ~FruitManager();
        void addFruit(Fruit* fruitToAdd, string file_location);
        void delFruit(Fruit* fruitToDelete);
        Fruit* getFruit(Fruit* key);
        void clear();
        void update(double deltatime);
        void draw();
        void checkForCollisions(Player* player);
};

