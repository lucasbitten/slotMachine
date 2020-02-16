#include "RestartButton.h"
#include "Game.h"
#include "SoundManager.h"


RestartButton::RestartButton()
// call super constructor
	:Button(
		"../Assets/textures/RestartButton.png",
		"restartButton",
		RESTART_BUTTON, glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f)), m_isClicked(false)
{

}

RestartButton::~RestartButton()
{
}

bool RestartButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			TheSoundManager::Instance()->playSound("button", 0);

			TheGame::Instance()->changeSceneState(SceneState::LEVEL1_SCENE);
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


