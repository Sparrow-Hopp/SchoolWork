#include "Fruit.h"

Fruit::Fruit(GraphicsBuffer* buffer, Vector2D location)
{
	mpBuffer = buffer;
	mLocation = location;
}

Fruit::~Fruit()
{
	al_destroy_sample(mpSample);
}

void Fruit::init(string file_location)
{
	if (!al_reserve_samples(1))
	{
		cout << "error - samples not reserved";
		system("pause");
		return;
	}
	mpSample = al_load_sample((file_location).c_str());
	assert(mpSample);
}

void Fruit::Draw()
{
	GraphicsSystem::draw(mLocation, *mpBuffer, 0.5);
}

void Fruit::Update(double deltaTime)
{
	mTimeUntilNextFrame -= deltaTime;
	if (mTimeUntilNextFrame <= 0)
	{
		mTimeUntilNextFrame = msPerFrame;
		mLocation.setY(mLocation.getY() + 5);
	}
}
