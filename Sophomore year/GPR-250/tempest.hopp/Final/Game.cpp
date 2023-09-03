#include "Game.h"
#include "InputSystem.h"

Game* Game::mGame = new Game;

Game::Game()
{
	srand(time(NULL));
	EventSystem::initInstance();
	EventSystem* pEventSystem = EventSystem::getInstance();
	pEventSystem->init();
	pEventSystem->addListener((EventType)PRESS_BUTTON, this);
	pEventSystem->addListener((EventType)FREEZE_UNITS, this);
	pEventSystem->addListener((EventType)EXIT_GAME, this);
	pEventSystem->addListener((EventType)MOVE_GAME, this);
	mGraphicsBufferManager = new GraphicsBufferManager();
	mUnitManager = new UnitManager();
	mFruitManager = new FruitManager();
	mButtonManager = new ButtonManager();
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
	mpSmallFont = new Font(SHARED_ASSET_PATH + FONT_FILENAME, FONT_SIZE);
	mpBigFont = new Font(SHARED_ASSET_PATH + FONT_FILENAME, FONT_SIZE * 2);

	mGraphicsBufferManager->addBuffer("background", new GraphicsBuffer(SOLO_ASSET_PATH + BACKGROUND_FILENAME));
	mGraphicsBufferManager->addBuffer("button", new GraphicsBuffer(SOLO_ASSET_PATH + BUTTON_BACKGROUND_FILENAME));
	mGraphicsBufferManager->addBuffer("Smurf", new GraphicsBuffer(SHARED_ASSET_PATH + SMURF_FILENAME));
	mGraphicsBufferManager->addBuffer("Player", new GraphicsBuffer(SOLO_ASSET_PATH + PLAYER_FILENAME));
	mGraphicsBufferManager->addBuffer("fruit", new GraphicsBuffer(SOLO_ASSET_PATH + FRUIT_FILENAME));

	makeButtons();

	mpPlayer = new Player(mGraphicsBufferManager->getBuffer("Player"), Vector2D(350, 450), mpBigFont);

	mTimePerFrame = fps;
	mTimeBetweenFruit = 300;
	mFruitSpeed = 1000/mTimePerFrame;
	mCurTime = mTimeBetweenFruit;
	mIsRunning = true;
}

void Game::makeButtons()
{
	ifstream english, dutch, spanish;
	english.open(SOLO_ASSET_PATH + ENG_FILENAME);
	dutch.open(SOLO_ASSET_PATH + DUT_FILENAME);
	spanish.open(SOLO_ASSET_PATH + ESP_FILENAME);

	string tempEng, tempDut, tempSpa;
	getline(english, tempEng);
	getline(dutch, tempDut);
	getline(spanish, tempSpa);

	string newGame[3] = { tempEng, tempDut, tempSpa};
	mButtonManager->addButton("New Game", new Button(mGraphicsBufferManager->getBuffer("button"), newGame, Vector2D(100, 500), mpSmallFont));
	mButtonManager->getButton("New Game")->setDrawState();

	getline(english, tempEng);
	getline(dutch, tempDut);
	getline(spanish, tempSpa);
	string loadGame[3] = { tempEng, tempDut, tempSpa };
	mButtonManager->addButton("Load Game", new Button(mGraphicsBufferManager->getBuffer("button"), loadGame, Vector2D(200, 500), mpSmallFont));
	mButtonManager->getButton("Load Game")->setDrawState();

	getline(english, tempEng);
	getline(dutch, tempDut);
	getline(spanish, tempSpa);
	string options[3] = { tempEng, tempDut, tempSpa };
	mButtonManager->addButton("Options", new Button(mGraphicsBufferManager->getBuffer("button"), options, Vector2D(300, 500), mpSmallFont));
	mButtonManager->getButton("Options")->setDrawState();

	getline(english, tempEng);
	getline(dutch, tempDut);
	getline(spanish, tempSpa);
	string exit[3] = { tempEng, tempDut, tempSpa };
	mButtonManager->addButton("Exit", new Button(mGraphicsBufferManager->getBuffer("button"), exit, Vector2D(400, 500), mpSmallFont));
	mButtonManager->getButton("Exit")->setDrawState();

	getline(english, tempEng);
	getline(dutch, tempDut);
	getline(spanish, tempSpa);
	string retry[3] = { tempEng, tempDut, tempSpa };
	mButtonManager->addButton("Retry", new Button(mGraphicsBufferManager->getBuffer("button"), retry, Vector2D(300, 500), mpSmallFont));

	getline(english, tempEng);
	getline(dutch, tempDut);
	getline(spanish, tempSpa);
	string language[3] = { tempEng, tempDut, tempSpa };
	mButtonManager->addButton("Language", new Button(mGraphicsBufferManager->getBuffer("button"), language, Vector2D(350, 300), mpSmallFont));

	getline(english, tempEng);
	getline(dutch, tempDut);
	getline(spanish, tempSpa);
	string menu[3] = { tempEng, tempDut, tempSpa };
	mButtonManager->addButton("Menu", new Button(mGraphicsBufferManager->getBuffer("button"), menu, Vector2D(200, 500), mpSmallFont));

	getline(english, tempEng);
	getline(dutch, tempDut);
	getline(spanish, tempSpa);
	string cont[3] = { tempEng, tempDut, tempSpa };
	mButtonManager->addButton("Continue", new Button(mGraphicsBufferManager->getBuffer("button"), cont, Vector2D(400, 300), mpSmallFont));

	getline(english, tempEng);
	getline(dutch, tempDut);
	getline(spanish, tempSpa);
	string levelUp[3] = { tempEng, tempDut, tempSpa };
	mButtonManager->addButton("Level Up", new Button(mGraphicsBufferManager->getBuffer("button"), levelUp, Vector2D(300, 0), mpBigFont));

	getline(english, tempEng);
	getline(dutch, tempDut);
	getline(spanish, tempSpa);
	string baseLevel[3] = { tempEng, tempDut, tempSpa };
	mButtonManager->addButton("Base Level", new Button(mGraphicsBufferManager->getBuffer("button"), baseLevel, Vector2D(350, 25), mpBigFont));

	english.close();
	dutch.close();
	spanish.close();
}

void Game::Cleanup()
{
	delete mpSmallFont;
	delete mpBigFont;
	delete mpSystem;
	delete mUnitManager;
	delete mGraphicsBufferManager;
	delete mFruitManager;
	delete mButtonManager;
	delete mpInputTranslator;
	delete mpPlayer;

	EventSystem* pEventSystem = EventSystem::getInstance();
	pEventSystem->removeListener((EventType)PRESS_BUTTON, this);
	pEventSystem->removeListener((EventType)FREEZE_UNITS, this);
	pEventSystem->removeListener((EventType)EXIT_GAME, this);
	pEventSystem->removeListener((EventType)MOVE_GAME, this);
}

void Game::StartLoop()
{
	Timer timer;
	while (mIsRunning)
	{
		timer.start();
		Update(mTimePerFrame);
		RenderStart();
		timer.sleepUntilElapsed(mTimePerFrame);
	}
}

void Game::optionsLoop()
{
	Timer timer;
	while (mIsRunning)
	{
		timer.start();
		Update(mTimePerFrame);
		renderOptions();
		timer.sleepUntilElapsed(mTimePerFrame);
	}
}

void Game::gameLoop()
{
	Timer timer;
	while (mIsRunning)
	{
		timer.start();
		Update(mTimePerFrame);
		mpPlayer->Update();
		renderGame();
		fruitSpawning();
		mFruitManager->update(mFruitSpeed);
		mFruitManager->checkForCollisions(mpPlayer);
		timer.sleepUntilElapsed(mTimePerFrame);
		if (mpPlayer->getTime() <= 0)
		{
			mFruitManager->clear();
			mpPlayer->levelUp();

			mFruitSpeed += 3;
			mTimeBetweenFruit -= 15;
			mLevel++;

			mButtonManager->getButton("Continue")->setDrawState();
			mButtonManager->getButton("Exit")->setDrawState();
			mButtonManager->getButton("Level Up")->setDrawState();
			mButtonManager->getButton("Base Level")->setDrawState();

			mCurScene = LEVEL_UP_SCENE;
			levelUpLoop();
		}
		if (mpPlayer->getLives() <= 0)
		{
			mFruitManager->clear();
			//buttons to activate
			mButtonManager->getButton("Exit")->setDrawState();
			mButtonManager->getButton("Retry")->setDrawState();
			mButtonManager->getButton("Menu")->setDrawState();
			mButtonManager->getButton("Base Level")->setDrawState();

			mCurScene = LOSE_SCENE;
			endLoop();
		}
	}
}

void Game::endLoop()
{
	Timer timer;
	while (mIsRunning)
	{
		timer.start();
		Update(mTimePerFrame);
		renderEnd();
		timer.sleepUntilElapsed(mTimePerFrame);
	}
	saveDataToFile();
}

void Game::levelUpLoop()
{
	Timer timer;
	while (mIsRunning)
	{
		timer.start();
		Update(mTimePerFrame);
		renderLevelUp();
		timer.sleepUntilElapsed(mTimePerFrame);
	}
	saveDataToFile();
}

void Game::Update(double fps)
{
	mpSystem->getInputSystem()->update();
	mUnitManager->update(fps);
}

void Game::RenderStart()
{
	mpSystem->getGraphicsSystem()->draw(Vector2D(0, 0), *mGraphicsBufferManager->getBuffer("background"), 1);
	mButtonManager->draw();
	mpSystem->getGraphicsSystem()->flip();
}

void Game::renderOptions()
{
	mpSystem->getGraphicsSystem()->draw(Vector2D(0, 0), *mGraphicsBufferManager->getBuffer("background"), 1);
	mButtonManager->draw();
	mpSystem->getGraphicsSystem()->flip();
}

void Game::renderGame()
{
	mpSystem->getGraphicsSystem()->draw(Vector2D(0, 0), *mGraphicsBufferManager->getBuffer("background"), 1);
	mpSystem->getGraphicsSystem()->writeText(Vector2D(470, 25), *mpBigFont, Color(0, 0, 0, 255), to_string(mLevel), Font::Alignment::CENTER);
	mButtonManager->draw();
	mpPlayer->Draw();
	mFruitManager->draw();
	mpSystem->getGraphicsSystem()->flip();
}

void Game::renderEnd()
{
	mpSystem->getGraphicsSystem()->draw(Vector2D(0, 0), *mGraphicsBufferManager->getBuffer("background"), 1);
	mButtonManager->draw();
	mpSystem->getGraphicsSystem()->flip();
}

void Game::renderLevelUp()
{
	mpSystem->getGraphicsSystem()->draw(Vector2D(0, 0), *mGraphicsBufferManager->getBuffer("background"), 1);
	mButtonManager->draw();
	mpSystem->getGraphicsSystem()->flip();
}

void Game::handleEvent(const Event& theEvent)
{
	if (theEvent.getType() == PRESS_BUTTON)
	{
		const PressButtonEvent& pressEvent = static_cast<const PressButtonEvent&>(theEvent);
		if (mButtonManager->getButton("New Game")->isPressed(pressEvent.getLocation()))
		{
			//buttons to deactivate
			mButtonManager->getButton("New Game")->setDrawState();
			mButtonManager->getButton("Load Game")->setDrawState();
			mButtonManager->getButton("Options")->setDrawState();
			mButtonManager->getButton("Exit")->setDrawState();
			
			//buttons to activate
			mButtonManager->getButton("Base Level")->setDrawState();

			mCurScene = GAME_SCENE;
			gameLoop();
		}
		else if (mButtonManager->getButton("Load Game")->isPressed(pressEvent.getLocation()))
		{
			//buttons to deactivate
			mButtonManager->getButton("New Game")->setDrawState();
			mButtonManager->getButton("Load Game")->setDrawState();
			mButtonManager->getButton("Options")->setDrawState();
			mButtonManager->getButton("Exit")->setDrawState();

			//buttons to activate
			mButtonManager->getButton("Base Level")->setDrawState();

			mCurScene = GAME_SCENE;
			loadGameFromFile();
		}
		else if (mButtonManager->getButton("Options")->isPressed(pressEvent.getLocation()))
		{
			//buttons to deactivate
			mButtonManager->getButton("New Game")->setDrawState();
			mButtonManager->getButton("Load Game")->setDrawState();
			mButtonManager->getButton("Options")->setDrawState();
			mButtonManager->getButton("Exit")->setDrawState();

			//buttons to activate
			mButtonManager->getButton("Language")->setDrawState();
			mButtonManager->getButton("Menu")->setDrawState();

			mCurScene = OPTIONS_SCENE;
			optionsLoop();
		}
		else if (mButtonManager->getButton("Exit")->isPressed(pressEvent.getLocation()))
		{
			mIsRunning = false;
		}
		else if (mButtonManager->getButton("Continue")->isPressed(pressEvent.getLocation()))
		{
			mButtonManager->getButton("Level Up")->setDrawState();
			mButtonManager->getButton("Continue")->setDrawState();
			mButtonManager->getButton("Exit")->setDrawState();
			mButtonManager->getButton("Base Level")->setDrawState();

			mpPlayer->restart();
			mCurScene = GAME_SCENE;
			gameLoop();
		}
		else if (mButtonManager->getButton("Retry")->isPressed(pressEvent.getLocation()))
		{
			//buttons to deactivate
			mButtonManager->getButton("Exit")->setDrawState();
			mButtonManager->getButton("Retry")->setDrawState();
			mButtonManager->getButton("Menu")->setDrawState();

			mpPlayer->restart();
			mCurScene = GAME_SCENE;
			gameLoop();
		}
		else if (mButtonManager->getButton("Language")->isPressed(pressEvent.getLocation()))
		{
			mButtonManager->swapLanguage();
		}
		else if (mButtonManager->getButton("Menu")->isPressed(pressEvent.getLocation()))
		{
			//buttons to deactivate
			mButtonManager->getButton("Language")->setDrawState();
			mButtonManager->getButton("Menu")->setDrawState();
			mButtonManager->getButton("Retry")->setDrawState();

			//buttons to activate
			mButtonManager->getButton("New Game")->setDrawState();
			mButtonManager->getButton("Load Game")->setDrawState();
			mButtonManager->getButton("Options")->setDrawState();
			mButtonManager->getButton("Exit")->setDrawState();

			mCurScene = NEW_GAME_SCENE;
			StartLoop();
		}
	}
	else if (theEvent.getType() == MOVE_GAME)
	{
		const MoveGameEvent& moveEvent = static_cast<const MoveGameEvent&>(theEvent);
		mpPlayer->setLocation(Vector2D(moveEvent.getLocation().getX() - 45, moveEvent.getLocation().getY() + 75));
	}
}

void Game::loadGameFromFile()
{
	ifstream gameFiles;
	gameFiles.open(SOLO_ASSET_PATH + GAME_FILENAME);
	if (!gameFiles.fail())
	{
		string temp;
		getline(gameFiles, temp);
		mLevel = stoi(temp);

		getline(gameFiles, temp);
		mFruitSpeed = stoi(temp);

		getline(gameFiles, temp);
		mTimeBetweenFruit = stoi(temp);
	}
	mpPlayer->loadDataFromFile(mLevel);
	mpPlayer->restart();
	gameLoop();
}

void Game::saveDataToFile()
{
	cout << "Writing data to file" << endl;
	ofstream gameFiles;
	gameFiles.open(SOLO_ASSET_PATH + GAME_FILENAME);
	gameFiles << mLevel << endl << mFruitSpeed << endl << mTimeBetweenFruit << endl;
	gameFiles.close();
}

void Game::fruitSpawning()
{
	mCurTime -= 5;
	if (mCurTime <= 0)
	{
		mCurTime = mTimeBetweenFruit;
		mFruitManager->addFruit(new Fruit(mGraphicsBufferManager->getBuffer("fruit"), Vector2D(rand() % 700 + 50, 0)), SOLO_ASSET_PATH + SAMPLE_FILENAME);
	}
}

Game* Game::getInstance()
{
	return mGame;
}
