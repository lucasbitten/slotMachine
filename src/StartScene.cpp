#include "StartScene.h"
#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>
#include "StartButton.h"
#include "SoundManager.h"

StartScene::StartScene()
{


	TheSoundManager::Instance()->load("../Assets/audio/Ambience.ogg",
		"ambience", sound_type::SOUND_SFX);
	
	StartScene::start();


}

StartScene::~StartScene()
{
}

void StartScene::draw()
{
	m_pBackground->draw();
	m_pStartLabel->draw();
	m_pStartButton->draw();

}

void StartScene::update()
{
	m_pStartButton->setMousePosition(m_mousePosition);
	m_pStartButton->ButtonClick();
}

void StartScene::clean()
{
	delete m_pStartLabel;
	
	removeAllChildren();
}

void StartScene::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			/*std::cout << "Mouse X: " << m_mousePosition.x << std::endl;
			std::cout << "Mouse Y: " << m_mousePosition.y << std::endl;
			std::cout << "---------------------------------------------" << std::endl;*/
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				
				m_pStartButton->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(false);
				break;
			}
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::LEVEL1_SCENE);
				break;

			}
			break;

		default:
			break;
		}
	}
}

// this function is used for initialization
void StartScene::start()
{

	TheSoundManager::Instance()->playSound("ambience", 1);
	
	m_pStartButton = new StartButton();

	m_pBackground = new Background();
	
	SDL_Color color = { 230, 200, 0, 255 };
	m_pStartLabel = new Label("Slot Machine Game", "Casino", 80, color, glm::vec2(Config::SCREEN_WIDTH*0.5f, 150.0f));
	m_pStartLabel->setParent(this);
	m_pStartButton->setParent(this);
	addChild(m_pStartButton);
	addChild(m_pStartLabel);
}

glm::vec2 StartScene::getMousePosition()
{
	return m_mousePosition;
}
