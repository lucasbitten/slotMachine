#include "BetValueButton.h"
#include "GameManager.h"
#include "SoundManager.h"

BetValueButton::BetValueButton(int value)
	:Button(
		"../Assets/textures/BetButton" + std::to_string(value) + ".png",
		"betValue" + std::to_string(value),
		BET_VALUE_BUTTON, glm::vec2(400.0f, 300.0f)), m_isClicked(false)
{
	valueToChange = value;
}

BetValueButton::~BetValueButton()
{
}

bool BetValueButton::ButtonClick()
{
    if (m_mouseOver() && m_mouseButtonClicked)
    {
        if (!m_isClicked)
        {
        	
            TheSoundManager::Instance()->playSound("button", 0);


            GameManager::Instance()->playerBet += valueToChange;
            if (GameManager::Instance()->playerBet < 0)
            {
                GameManager::Instance()->playerBet = 0;
            }


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
