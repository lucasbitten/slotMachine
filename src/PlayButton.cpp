#include "PlayButton.h"
#include "Game.h"
#include "GameManager.h"

PlayButton::PlayButton()
// call super constructor
	:Button(
		"../Assets/textures/PlayButton.png",
		"playButton",
		PLAY_BUTTON, glm::vec2(400.0f, 300.0f)), m_isClicked(false)
{

}

PlayButton::~PlayButton()
{
}

bool PlayButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{


            if (GameManager::Instance()->playerMoney == 0)
            {
                std::cout << "You ran out of Money! \nDo you want to play again?" << std::endl;
            	
               /* if (confirm("You ran out of Money! \nDo you want to play again?")) {
                    resetAll();
                    showPlayerStats();
                }*/
            }
            else if (GameManager::Instance()->playerBet > GameManager::Instance()->playerMoney) {
                std::cout << "You don't have enough Money to place that bet." << std::endl;
            }
            else if (GameManager::Instance()->playerBet <= 0) {
                std::cout << "All bets must be a positive $ amount." << std::endl;
            }
            else if (GameManager::Instance()->playerBet <= GameManager::Instance()->playerMoney) {
                GameManager::Instance()->spinResult = GameManager::Instance()-> reels();
                GameManager::Instance()->fruits = GameManager::Instance()->spinResult[0] + " - " + GameManager::Instance()->spinResult[1] + " - " + GameManager::Instance()->spinResult[2];

                std::cout << "result: " << GameManager::Instance()->fruits << std::endl;
                GameManager::Instance()->determineWinnings();
                GameManager::Instance()->turn++;
                GameManager::Instance()->showPlayerStats();
            }
            else {
                std::cout << "Please enter a valid bet amount" << std::endl;
            }

			std::cout << "Play Button Clicked!" << std::endl;
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


