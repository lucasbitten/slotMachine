#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "SlotMachine.h"
#include "PlayButton.h"
#include "GLM/gtx/string_cast.hpp"
#include "Label.h"
#include "BetValueButton.h"
#include "ResultImage.h"
#include "QuitButton.h"
#include "ResetButton.h"
#include "InfoLabel.h"
#include "Background.h"


class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();
	
	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;

	// getters
	glm::vec2 getMousePosition();

private:
	// game objects

	glm::vec2 m_mousePosition;

	SlotMachine* m_pSlotMachine;
	PlayButton* m_pPlayButton;

	Label* m_pJackPotLabel;
	Label* m_pPlayerMoneyLabel;
	Label* m_pTurnLabel;
	Label* m_pWinLabel;
	Label* m_pLossesLabel;
	Label* m_pWinRatioLabel;
	Label* m_pBetLabel;

	BetValueButton* value1Button;
	BetValueButton* value5Button;
	BetValueButton* value10Button;
	BetValueButton* value50Button;
	BetValueButton* value100Button;
	BetValueButton* value500Button;
	BetValueButton* value1000Button;

	BetValueButton* valueMinus1Button;
	BetValueButton* valueMinus5Button;
	BetValueButton* valueMinus10Button;
	BetValueButton* valueMinus50Button;
	BetValueButton* valueMinus100Button;
	BetValueButton* valueMinus500Button;
	BetValueButton* valueMinus1000Button;

	QuitButton* quitButton;
	ResetButton* resetButton;

	ResultImage* m_pFirstImage;
	ResultImage* m_pSecondImage;
	ResultImage* m_pThirdImage;

	InfoLabel* m_pInfoLabel;
	Background* m_pBackground;

	void updateLabels() const;


	
	// ImGui utility functions
	void m_ImGuiKeyMap();
	void m_ImGuiSetStyle();
	void m_updateUI();

	// ImGui menu variables
	bool m_exitApp = false;
	bool m_displayAbout = false;
	bool m_displayUI = false;

};

#endif /* defined (__LEVEL_1_SCENE__) */
