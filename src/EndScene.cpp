#include "EndScene.h"
#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>

EndScene::EndScene()
{
	EndScene::start();
}

EndScene::~EndScene()
{
}

void EndScene::draw()
{
	m_pGameOverLabel->draw();
	m_pNoMoneyLabel->draw();
	m_pRestartButton->draw();
}

void EndScene::update()
{
	m_pRestartButton->setMousePosition(m_mousePosition);
	m_pRestartButton->ButtonClick();
	
}

void EndScene::clean()
{
	delete m_pGameOverLabel;
	delete m_pRestartButton;
	delete m_pNoMoneyLabel;
	removeAllChildren();
}

void EndScene::handleEvents()
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

				m_pRestartButton->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRestartButton->setMouseButtonClicked(false);
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

void EndScene::start()
{
	SDL_Color color = { 230, 200, 0, 255 };
	m_pGameOverLabel = new Label("Game Over!", "Anton-Regular", 80, color, glm::vec2(Config::SCREEN_WIDTH/2, 100));
	m_pGameOverLabel->setParent(this);
	addChild(m_pGameOverLabel);
	
	m_pNoMoneyLabel = new Label("You ran out of money!", "Anton-Regular", 60, color, glm::vec2(Config::SCREEN_WIDTH / 2, 200.0f));
	m_pNoMoneyLabel->setParent(this);
	addChild(m_pNoMoneyLabel);

	m_pRestartButton = new RestartButton();
	m_pRestartButton->setPosition(glm::vec2(Config::SCREEN_WIDTH / 2, Config::SCREEN_HEIGHT / 2));
	m_pRestartButton->setParent(this);
	addChild(m_pRestartButton);
}
