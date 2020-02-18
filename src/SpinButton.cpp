#include "SpinButton.h"
#include "Game.h"
#include "GameManager.h"
#include "SoundManager.h"


SpinButton::SpinButton()
// call super constructor
	:Button(
		"../Assets/textures/SpinButton.png",
		"spinButton",
        SPIN_BUTTON, glm::vec2(400.0f, 300.0f)), m_isClicked(false)
{
    TheSoundManager::Instance()->load("../Assets/audio/Spin.wav",
        "spin", sound_type::SOUND_SFX);
}

SpinButton::~SpinButton()
{
}

bool SpinButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
            TheSoundManager::Instance()->playSound("button", 0);

            if (GameManager::Instance()->playerMoney == 0)
            {
                std::cout << "You ran out of Money! \nDo you want to play again?" << std::endl;
                //GameManager::Instance()->showMessageDialog("You ran out of Money!", "Do you want to play again?");

            }
            else if (GameManager::Instance()->playerBet > GameManager::Instance()->playerMoney) {
                std::cout << "You don't have enough Money to place that bet." << std::endl;
                GameManager::Instance()->showMessageDialog("You don't have enough Money to place that bet.", " ");


            }
            else if (GameManager::Instance()->playerBet <= 0) {
                std::cout << "All bets must be a positive $ amount." << std::endl;
                GameManager::Instance()->showMessageDialog("All bets must be a positive $ amount.", " ");
            }
            else if (GameManager::Instance()->playerBet <= GameManager::Instance()->playerMoney) {

                TheGameManager::Instance()->isWaitingAnimation = true;

            	GameManager::Instance()->spinResult = GameManager::Instance()-> reels();
                GameManager::Instance()->fruits = GameManager::Instance()->spinResult[0] + " - " + GameManager::Instance()->spinResult[1] + " - " + GameManager::Instance()->spinResult[2];
                std::cout << "result: " << GameManager::Instance()->fruits << std::endl;
                GameManager::Instance()->determineWinnings();
                GameManager::Instance()->turn++;
                GameManager::Instance()->showPlayerStats();

            	if(GameManager::Instance()->playerMoney > 0)
            	{
                    TheSoundManager::Instance()->playSound("spin", 0);

            	}

            	
            }
            else {
                std::cout << "Please enter a valid bet amount" << std::endl;
                GameManager::Instance()->showMessageDialog("Please enter a valid bet amount", " ");

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


