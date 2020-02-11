#include "ResetButton.h"
#include "Game.h"
#include "GameManager.h"

ResetButton::ResetButton()
// call super constructor
	:Button(
		"../Assets/textures/ResetButton.png",
		"resetButton",
		RESET_BUTTON, glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f)), m_isClicked(false)
{

}

ResetButton::~ResetButton()
{
}

bool ResetButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			GameManager::Instance()->resetGame();
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


