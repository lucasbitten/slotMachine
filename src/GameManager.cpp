#include "GameManager.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Game.h"

GameManager* GameManager::s_pInstance;

GameManager::GameManager()
{
    winRatioText << std::setprecision(4) << "00.00%";
}

GameManager::~GameManager()
{
}

void GameManager::showPlayerStats()
{
    std::cout << "*---- Player stats ----*" << std::endl;
    std::cout << "Win Ratio: " << std::setprecision(4)  << winRatio << "%" << std::endl;
}

void GameManager::resetFruitTally()
{
    grapes = 0;
    bananas = 0;
    oranges = 0;
    cherries = 0;
    bars = 0;
    bells = 0;
    sevens = 0;
    blanks = 0;
}

void GameManager::resetGame()
{

    playerMoney = 1000;
    winnings = 0;
    jackpot = 5000;
    turn = 0;
    playerBet = 0;
    winNumber = 0;
    lossNumber = 0;
    winRatio = 0;
    winRatioText.str("00.00%");
}

void GameManager::checkJackPot()
{
	const float jackPotTry = floor((double(rand()) / (RAND_MAX)) * 51 + 1);
	const float jackPotWin = floor((double(rand()) / (RAND_MAX)) * 51 + 1);
    if (jackPotTry == jackPotWin) {
        std::cout << "You Won the $" << jackpot << " Jackpot!!" << std::endl;
        playerMoney += jackpot;
        jackpot = 1000;

    }

}

void GameManager::showWinMessage()
{

    playerMoney += winnings;
    std::cout << "You Won " << winnings << "!" << std::endl;
    resetFruitTally();
    checkJackPot();
	
}

void GameManager::showLossMessage()
{

    playerMoney -= playerBet;
    std::cout << "You Lost! " << std::endl;
    resetFruitTally();

	if (playerMoney <= 0)
	{
        TheGame::Instance()->changeSceneState(SceneState::END_SCENE);

	}
	
}


std::vector<std::string> GameManager:: reels()
{
	std::vector<std::string> betLine = { " ", " ", " " };
    std::vector<int> outCome = { 0, 0, 0 };

    for (int spin = 0; spin < 3; spin++) {
        std::cout << spin << std::endl;

        outCome[spin] = floor((double(rand()) / (RAND_MAX) * 65) + 1);
        std::cout << outCome[spin] << std::endl;

        if(outCome[spin] >= 1 && outCome[spin] <= 27)
        {
            betLine[spin] = "blank";
            blanks++;
        } else if((outCome[spin] >= 28 && outCome[spin] <= 37))
        {
            betLine[spin] = "Grapes";
            grapes++;
        }
        else if ((outCome[spin] >= 38 && outCome[spin] <= 46))
        {
            betLine[spin] = "Banana";
            bananas++;
        }
        else if ((outCome[spin] >= 47 && outCome[spin] <= 54))
        {
            betLine[spin] = "Orange";
            oranges++;
        }
        else if ((outCome[spin] >= 55 && outCome[spin] <= 59))
        {
            betLine[spin] = "Cherry";
            cherries++;
        }
        else if ((outCome[spin] >= 60 && outCome[spin] <= 62))
        {
            betLine[spin] = "Bar";
            bars++;
        }
        else if ((outCome[spin] >= 63 && outCome[spin] <= 64))
        {
            betLine[spin] = "Bell";
            bells++;
        }
        else if ((outCome[spin] == 65))
        {
            betLine[spin] = "Seven";
            sevens++;
        }
    }
    std::cout << betLine[0] << std::endl;
    return betLine;

	
}

void GameManager::determineWinnings()
{
    if (blanks == 0)
    {
        if (grapes == 3) {
            winnings = playerBet * 10;
        }
        else if (bananas == 3) {
            winnings = playerBet * 20;
        }
        else if (oranges == 3) {
            winnings = playerBet * 30;
        }
        else if (cherries == 3) {
            winnings = playerBet * 40;
        }
        else if (bars == 3) {
            winnings = playerBet * 50;
        }
        else if (bells == 3) {
            winnings = playerBet * 75;
        }
        else if (sevens == 3) {
            winnings = playerBet * 100;
        }
        else if (grapes == 2) {
            winnings = playerBet * 2;
        }
        else if (bananas == 2) {
            winnings = playerBet * 2;
        }
        else if (oranges == 2) {
            winnings = playerBet * 3;
        }
        else if (cherries == 2) {
            winnings = playerBet * 4;
        }
        else if (bars == 2) {
            winnings = playerBet * 5;
        }
        else if (bells == 2) {
            winnings = playerBet * 10;
        }
        else if (sevens == 2) {
            winnings = playerBet * 20;
        }
        else if (sevens == 1) {
            winnings = playerBet * 5;
        }
        else {
            winnings = playerBet * 1;
        }
        winNumber++;
        winRatio = winNumber / (1.0f*(winNumber + lossNumber)) * 100;
        showWinMessage();

    }
    else
    {
        lossNumber++;
        winRatio = winNumber / (1.0f * (winNumber + lossNumber)) * 100;
        showLossMessage();
    }
	if (winRatio == 0)
	{
        winRatioText.str("00.00%");

	}else
	{
        winRatioText.str("");
        winRatioText << winRatio << "%";
	}


	
}
