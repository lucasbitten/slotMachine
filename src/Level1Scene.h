#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "SlotMachine.h"
#include "SpinButton.h"
#include "GLM/gtx/string_cast.hpp"
#include "Label.h"
#include "BetValueButton.h"
#include "ResultImage.h"
#include "QuitButton.h"
#include "ResetButton.h"
#include "InfoBackground.h"
#include "Background.h"
#include "MessageDialog.h"
#include "DialogButton.h"

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


	ResultImage* m_pFirstImage;
	ResultImage* m_pSecondImage;
	ResultImage* m_pThirdImage;
	
private:
	// game objects
	glm::vec2 m_mousePosition;

	SlotMachine* m_pSlotMachine;

	SpinButton* m_pSpinButton;

	
	InfoBackground* m_pInfoBackground;
	//Player information labels
	Label* m_pJackPotLabel;
	Label* m_pPlayerMoneyLabel;
	Label* m_pTurnLabel;
	Label* m_pWinLabel;
	Label* m_pLossesLabel;
	Label* m_pWinRatioLabel;
	Label* m_pBetLabel;
	void updateInfoLabels() const;


	//Positive Bet Buttons
	BetValueButton* value1Button;
	BetValueButton* value5Button;
	BetValueButton* value10Button;
	BetValueButton* value50Button;
	BetValueButton* value100Button;
	BetValueButton* value500Button;
	BetValueButton* value1000Button;

	//Negative Bet Buttons
	BetValueButton* valueMinus1Button;
	BetValueButton* valueMinus5Button;
	BetValueButton* valueMinus10Button;
	BetValueButton* valueMinus50Button;
	BetValueButton* valueMinus100Button;
	BetValueButton* valueMinus500Button;
	BetValueButton* valueMinus1000Button;
	
	//Options Buttons
	QuitButton* quitButton;
	ResetButton* resetButton;

	//MessageDialog objects
	MessageDialog* message;
	DialogButton* dialogButton;
	Label* messageTextLabelLine1;
	Label* messageTextLabelLine2;


	Background* m_pBackground;



};

#endif /* defined (__LEVEL_1_SCENE__) */
