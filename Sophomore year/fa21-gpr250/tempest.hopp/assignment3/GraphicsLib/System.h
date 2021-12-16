#pragma once

#include <Trackable.h>

#include <allegro5/allegro.h>
#include <Vector2D.h>

class GraphicsSystem;

namespace Input
{
	enum MouseButton
	{
		LEFT = 0,
		RIGHT = 1,
		CENTER = 2,
	};
	enum Key
	{
		ENTER = ALLEGRO_KEY_ENTER,
		SPACE = ALLEGRO_KEY_SPACE,
		ESCAPE = ALLEGRO_KEY_ESCAPE,
		F = ALLEGRO_KEY_F,
		S = ALLEGRO_KEY_S
	};
}

class System :public Trackable
{
public:
	System();
	virtual ~System();

	bool init(unsigned int width, unsigned int height);
	void cleanup();
	GraphicsSystem* getGraphicsSystem() const { return mpGraphicsSystem; };
	bool isKeyPressed(Input::Key key);
	bool isMouseButtonPressed(Input::MouseButton mouse);
	Vector2D getMousePos();
private:
	bool mIsInitted = false;
	GraphicsSystem* mpGraphicsSystem = NULL;

};
