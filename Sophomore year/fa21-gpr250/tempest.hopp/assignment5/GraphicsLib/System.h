#pragma once

#include <Trackable.h>

#include <allegro5/allegro.h>
#include <Vector2D.h>
#include "InputEvent.h"

class GraphicsSystem;
class InputSystem;

class System :public Trackable
{
public:
	System();
	virtual ~System();

	bool init(unsigned int width, unsigned int height);
	void cleanup();
	GraphicsSystem* getGraphicsSystem() const { return mpGraphicsSystem; };
	InputSystem* getInputSystem() const { return mpInputSystem; };
	bool isKeyPressed(Input::Key key);
	bool isMouseButtonPressed(Input::MouseButton mouse);
	Vector2D getMousePos();
private:
	bool mIsInitted = false;
	GraphicsSystem* mpGraphicsSystem = NULL;
	InputSystem* mpInputSystem = NULL;

};
