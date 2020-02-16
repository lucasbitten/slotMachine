#pragma once
#ifndef __GameManager__
#define  __GameManager__

#include <string>
#include <vector>
#include <sstream>
#include "ItemType.h"

class GameManager
{
public:

	static GameManager* Instance()
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance = new GameManager();
			return s_pInstance;
		}

		return s_pInstance;
	}



	GameManager();
	~GameManager();

	void showPlayerStats();
	void resetFruitTally();
	void resetGame();
	void checkJackPot();
	void showWinMessage();
	void showLossMessage();
	std::vector<std::string>  reels();
	void determineWinnings();
	void showMessageDialog(std::string line1, std::string line2);
	
	int playerMoney = 1000;
	int winnings = 0;
	int jackpot = 5000;
	
	bool showingMessage = false;
	std::string messageContentLine1 = "";
	std::string messageContentLine2 = "";

	int turn = 0;
	int playerBet = 0;
	int winNumber = 0;
	int lossNumber = 0;
	std::vector<std::string> spinResult;
	std::vector<ItemType> itemsResult = {SPIN,SPIN,SPIN};

	std::string fruits = "";
	float winRatio = 0;
	std::ostringstream winRatioText;
	int grapes = 0;
	int bananas = 0;
	int oranges = 0;
	int cherries = 0;
	int bars = 0;
	int bells = 0;
	int sevens = 0;
	int blanks = 0;

	bool waitingAnimation;
	
	static GameManager* s_pInstance;

};

typedef GameManager TheGameManager;




#endif
