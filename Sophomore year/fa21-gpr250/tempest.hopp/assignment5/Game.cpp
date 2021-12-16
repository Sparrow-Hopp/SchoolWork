#include "Game.h"
#include "InputSystem.h"

Game* Game::mGame = new Game;

Game::Game()
{
	EventSystem::initInstance();
	EventSystem* pEventSystem = EventSystem::getInstance();
	pEventSystem->init();
	pEventSystem->addListener((EventType)ADD_UNIT, this);
	pEventSystem->addListener((EventType)DEL_UNIT, this);
	pEventSystem->addListener((EventType)FREEZE_UNITS, this);
	pEventSystem->addListener((EventType)EXIT_GAME, this);
	pEventSystem->addListener((EventType)MOVE_GAME, this);
	mGraphicsBufferManager = new GraphicsBufferManager();
	mUnitManager = new UnitManager();
	mpSystem = new System();
	mpInputTranslator = new InputTranslator();
	mIsRunning = false;
	mTimePerFrame = 0;
}

Game::~Game()
{
	Cleanup();
}

void Game::Init(int width, int height, double fps)
{

	mpSystem->init(width, height);

	mGraphicsBufferManager->addBuffer("Dean", new GraphicsBuffer(ASSET_PATH + DEAN_FILENAME));
	mGraphicsBufferManager->addBuffer("Smurf", new GraphicsBuffer(ASSET_PATH + SMURF_FILENAME));
	mGraphicsBufferManager->addBuffer("Woods", new GraphicsBuffer(ASSET_PATH + WOODS_FILENAME));

	mTimePerFrame = fps;
	mIsRunning = true;
	defineUnit(Vector2D(390, 290));
}

void Game::defineUnit(Vector2D location)
{
	const unsigned int PIXEL_WIDTH = 60;
	const unsigned int PIXEL_HEIGHT = 60;
	const unsigned int SPRITES_ACROSS = 4;
	const unsigned int SPRITES_DOWN = 4;
	Sprite smurfSprites[SPRITES_ACROSS * SPRITES_DOWN];
	Sprite deanSprites[SPRITES_ACROSS * SPRITES_DOWN];
	unsigned int spriteNum = 0;

	for (unsigned int y = 0; y < SPRITES_DOWN; y++)
	{
		for (unsigned int x = 0; x < SPRITES_ACROSS; x++)
		{
			Sprite sprite(mGraphicsBufferManager->getBuffer("Smurf"), Vector2D((int)(x * PIXEL_WIDTH), (int)(y * PIXEL_HEIGHT)), PIXEL_WIDTH, PIXEL_HEIGHT);
			smurfSprites[spriteNum] = sprite;
			spriteNum++;
		}
	}
	spriteNum = 0;

	for (unsigned int y = 0; y < SPRITES_DOWN; y++)
	{
		for (unsigned int x = 0; x < SPRITES_ACROSS; x++)
		{
			Sprite sprite(mGraphicsBufferManager->getBuffer("Dean"), Vector2D((int)(x * PIXEL_WIDTH), (int)(y * PIXEL_HEIGHT)), PIXEL_WIDTH, PIXEL_HEIGHT);
			deanSprites[spriteNum] = sprite;
			spriteNum++;
		}
	}

	mUnitManager->addUnit(new Unit(deanSprites, smurfSprites, location));
}

void Game::Cleanup()
{
	delete mpSystem;
	delete mUnitManager;
	delete mGraphicsBufferManager;
	delete mpInputTranslator;

	EventSystem* pEventSystem = EventSystem::getInstance();
	pEventSystem->removeListener((EventType)ADD_UNIT, this);
	pEventSystem->removeListener((EventType)DEL_UNIT, this);
	pEventSystem->removeListener((EventType)FREEZE_UNITS, this);
	pEventSystem->removeListener((EventType)EXIT_GAME, this);
	pEventSystem->removeListener((EventType)MOVE_GAME, this);
}

void Game::DoLoop()
{
	Timer timer;
	while (mIsRunning)
	{
		timer.start();
		Update(mTimePerFrame);
		Render();
		timer.sleepUntilElapsed(mTimePerFrame);
	}
}

void Game::getInput()
{
	if (mpSystem->isKeyPressed(Input::SPACE))
		mUnitManager->stopAnimation();
	if (mpSystem->isKeyPressed(Input::ESCAPE))
		mIsRunning = false;
	if (mpSystem->isKeyPressed(Input::ENTER))
		mUnitManager->swapToDean();
	if (mpSystem->isMouseButtonPressed(Input::RIGHT))
		mUnitManager->findAndDelete(Vector2D(mpSystem->getMousePos()));
	if (mpSystem->isMouseButtonPressed(Input::LEFT))
		defineUnit(Vector2D(mpSystem->getMousePos().getX() - 32, mpSystem->getMousePos().getY() - 32));
}

void Game::Update(double fps)
{
	mpSystem->getInputSystem()->update();
	mUnitManager->update(fps);
}

void Game::Render()
{
	mpSystem->getGraphicsSystem()->draw(Vector2D(0, 0), *mGraphicsBufferManager->getBuffer("Woods"), 0.5);
	mUnitManager->draw();
	mpSystem->getGraphicsSystem()->flip();
}

void Game::handleEvent(const Event& theEvent)
{
	if (theEvent.getType() == ADD_UNIT)
	{
		const AddUnitEvent& addEvent = static_cast<const AddUnitEvent&>(theEvent);
		defineUnit(Vector2D(addEvent.getLocation().getX() - 32, addEvent.getLocation().getY() - 32));
	}
	else if (theEvent.getType() == DEL_UNIT)
	{
		const DelUnitEvent& delEvent = static_cast<const DelUnitEvent&>(theEvent);
		mUnitManager->findAndDelete(delEvent.getLocation());
	}
	else if (theEvent.getType() == FREEZE_UNITS)
		mUnitManager->stopAnimation();
	else if (theEvent.getType() == MOVE_GAME)
	{
		const MoveGameEvent& moveEvent = static_cast<const MoveGameEvent&>(theEvent);
		cout << moveEvent.getLocation().getX() << ", " << moveEvent.getLocation().getY() << endl;
	}
	else if (theEvent.getType() == EXIT_GAME)
		mIsRunning = false;
}

Game* Game::getInstance()
{
	return mGame;
}
