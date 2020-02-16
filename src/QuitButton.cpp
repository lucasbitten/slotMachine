#include "QuitButton.h"
#include "Game.h"
#include "GameManager.h"
#include "SoundManager.h"

QuitButton::QuitButton()
// call super constructor
	:Button(
		"../Assets/textures/QuitButton.png",
		"quitButton",
		QUIT_BUTTON, glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f)), m_isClicked(false)
{

}

QuitButton::~QuitButton()
{
}

bool QuitButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			TheSoundManager::Instance()->playSound("button", 0);

			Game::Instance()->quit();
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}


