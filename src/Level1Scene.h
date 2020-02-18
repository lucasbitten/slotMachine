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
	BetValueButton* m_pValue1Button;
	BetValueButton* m_pValue5Button;
	BetValueButton* m_pValue10Button;
	BetValueButton* m_pValue50Button;
	BetValueButton* m_pValue100Button;
	BetValueButton* m_pValue500Button;
	BetValueButton* m_pValue1000Button;

	//Negative Bet Buttons
	BetValueButton* m_pValueMinus1Button;
	BetValueButton* m_pValueMinus5Button;
	BetValueButton* m_pValueMinus10Button;
	BetValueButton* m_pValueMinus50Button;
	BetValueButton* m_pValueMinus100Button;
	BetValueButton* m_pValueMinus500Button;
	BetValueButton* m_pValueMinus1000Button;
	
	//Options Buttons
	QuitButton* m_pQuitButton;
	ResetButton* m_pResetButton;

	//MessageDialog objects
	MessageDialog* m_pMessageDialog;
	DialogButton* m_pDialogButton;
	Label* m_pMessageTextLabelLine1;
	Label* m_pMessageTextLabelLine2;


	Background* m_pBackground;

};

#endif /* defined (__LEVEL_1_SCENE__) */
