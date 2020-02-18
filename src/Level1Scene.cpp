#include "Level1Scene.h"
#include "Game.h"
#include "GameManager.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>
#include <sstream>
#include "SoundManager.h"
#include <chrono>
#include <thread>


/*** SCENE FUNCTIONS ***/

void Level1Scene::start()
{

	TheSoundManager::Instance()->playSound("ambience", 1);

	
	GameManager::Instance()->resetGame();
	
	// allocates memory on the heap for this game object

	m_pBackground = new Background();
	m_pInfoBackground = new InfoBackground();
	m_pInfoBackground->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, 560));
	
	m_pSlotMachine = new SlotMachine();
	m_pSlotMachine->setPosition(glm::vec2(400, 250));

	m_pFirstImage = new ResultImage(glm::vec2(280, 270));
	m_pSecondImage = new ResultImage(glm::vec2(393, 270));
	m_pThirdImage = new ResultImage(glm::vec2(507, 270));
	
	m_pSpinButton = new SpinButton();
	m_pSpinButton->setPosition(glm::vec2(520, 450));
	
	m_pResetButton = new ResetButton();
	m_pResetButton->setPosition(glm::vec2(275, 450));
	
	m_pQuitButton = new QuitButton();
	m_pQuitButton->setPosition(glm::vec2(750, 760));
	
	SDL_Color color = { 255, 0, 0, 255 };
	
	m_pJackPotLabel = new Label("Jackpot: " + std::to_string(GameManager::Instance()->jackpot), "digital-7", 30, color, glm::vec2(150,515));
	m_pPlayerMoneyLabel = new Label("Money: " + std::to_string(GameManager::Instance()->playerMoney), "digital-7", 30, color, glm::vec2(400, 515));
	m_pTurnLabel = new Label("Turn: " + std::to_string(GameManager::Instance()->turn), "digital-7", 30, color, glm::vec2(600, 515));
	m_pWinLabel = new Label("Wins: " + std::to_string(GameManager::Instance()->winNumber), "digital-7", 30, color, glm::vec2(150, 565));
	m_pLossesLabel = new Label("Losses: " + std::to_string(GameManager::Instance()->lossNumber), "digital-7", 30, color, glm::vec2(400, 565));
	m_pWinRatioLabel = new Label("Win ratio: 00.00%", "digital-7", 30, color, glm::vec2(600, 565));
	m_pBetLabel = new Label("Your Bet: " + std::to_string(GameManager::Instance()->playerBet), "digital-7", 35, color, glm::vec2(150, 620));

	m_pValue1Button = new BetValueButton(1);
	m_pValue5Button = new BetValueButton(5);
	m_pValue10Button = new BetValueButton(10);
	m_pValue50Button = new BetValueButton(50);
	m_pValue100Button = new BetValueButton(100);
	m_pValue500Button = new BetValueButton(500);
	m_pValue1000Button = new BetValueButton(1000);

	m_pValue1Button->setPosition(glm::vec2(50, 700));
	m_pValue5Button->setPosition(glm::vec2(110, 700));
	m_pValue10Button->setPosition(glm::vec2(170, 700));
	m_pValue50Button->setPosition(glm::vec2(230, 700));
	m_pValue100Button->setPosition(glm::vec2(290, 700));
	m_pValue500Button->setPosition(glm::vec2(350, 700));
	m_pValue1000Button->setPosition(glm::vec2(410, 700));

	m_pValueMinus1Button = new BetValueButton(-1);
	m_pValueMinus5Button = new BetValueButton(-5);
	m_pValueMinus10Button = new BetValueButton(-10);
	m_pValueMinus50Button = new BetValueButton(-50);
	m_pValueMinus100Button = new BetValueButton(-100);
	m_pValueMinus500Button = new BetValueButton(-500);
	m_pValueMinus1000Button = new BetValueButton(-1000);
		 
	m_pValueMinus1Button->setPosition(glm::vec2(50, 760));
	m_pValueMinus5Button->setPosition(glm::vec2(110, 760));
	m_pValueMinus10Button->setPosition(glm::vec2(170, 760));
	m_pValueMinus50Button->setPosition(glm::vec2(230, 760));
	m_pValueMinus100Button->setPosition(glm::vec2(290, 760));
	m_pValueMinus500Button->setPosition(glm::vec2(350, 760));
	m_pValueMinus1000Button->setPosition(glm::vec2(410, 760));

	
	m_pMessageDialog = new MessageDialog();
	m_pMessageDialog->setPosition(glm::vec2(Config::SCREEN_WIDTH*0.5f, Config::SCREEN_HEIGHT*0.5f));
	m_pDialogButton = new DialogButton();
	m_pDialogButton->setPosition(glm::vec2(560, 500));
	m_pMessageTextLabelLine1 = new Label(" ","Anton-Regular",20, color,glm::vec2(400,280));
	m_pMessageTextLabelLine2 = new Label(" ", "Anton-Regular", 20, color, glm::vec2(400, 320));

}

void Level1Scene::updateInfoLabels() const //Method to update all the players information during play
{

	m_pJackPotLabel->setText(("Jackpot: " + std::to_string(GameManager::Instance()->jackpot)));
	m_pPlayerMoneyLabel->setText(("Money: " + std::to_string(GameManager::Instance()->playerMoney)));
	m_pTurnLabel->setText(("Turn: " + std::to_string(GameManager::Instance()->turn))); 
	m_pWinLabel->setText(("Wins: " + std::to_string(GameManager::Instance()->winNumber)));
	m_pLossesLabel->setText(("Losses: " + std::to_string(GameManager::Instance()->lossNumber)));
	m_pWinRatioLabel->setText(("Win ratio: " + GameManager::Instance()->winRatioText.str()));
	m_pBetLabel->setText(("Your Bet: " + std::to_string(GameManager::Instance()->playerBet)));

}


Level1Scene::Level1Scene()
{
	TheSoundManager::Instance()->load("../Assets/audio/Ambience.ogg",
		"ambience", sound_type::SOUND_SFX);
	Level1Scene::start();
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::draw()
{

	m_pBackground->draw();
	m_pInfoBackground->draw();

	m_pFirstImage->draw();
	m_pSecondImage->draw();
	m_pThirdImage->draw();
	m_pSlotMachine->draw();
	
	m_pSpinButton->draw();
	m_pQuitButton->draw();
	m_pResetButton->draw();
	
	m_pJackPotLabel->draw();
	m_pPlayerMoneyLabel->draw();
	m_pTurnLabel->draw();
	m_pWinLabel->draw();
	m_pLossesLabel->draw();
	m_pWinRatioLabel->draw();
	m_pBetLabel->draw();


	m_pValue1Button    ->draw();
	m_pValue5Button	->draw();
	m_pValue10Button	->draw();
	m_pValue50Button	->draw();
	m_pValue100Button	->draw();
	m_pValue500Button	->draw();
	m_pValue1000Button	->draw();

	m_pValueMinus1Button->draw();
	m_pValueMinus5Button->draw();
	m_pValueMinus10Button->draw();
	m_pValueMinus50Button->draw();
	m_pValueMinus100Button->draw();
	m_pValueMinus500Button->draw();
	m_pValueMinus1000Button->draw();

	
	if (GameManager::Instance()->isShowingMessage) //Draw the message dialog box only when needed
	{
		m_pMessageTextLabelLine1->setText(GameManager::Instance()->messageContentLine1);
		m_pMessageTextLabelLine2->setText(GameManager::Instance()->messageContentLine2);

		m_pMessageDialog->draw();
		m_pMessageTextLabelLine1->draw();
		m_pMessageTextLabelLine2->draw();
		m_pDialogButton->draw();
	}
}

void Level1Scene::update()
{
	//Seting the images result of each draw
	m_pFirstImage->setItem(GameManager::Instance()->itemsResult[0]);
	m_pSecondImage->setItem(GameManager::Instance()->itemsResult[1]);
	m_pThirdImage->setItem(GameManager::Instance()->itemsResult[2]);

	
	if (!GameManager::Instance()->isShowingMessage && !GameManager::Instance()->isWaitingAnimation) // Disabling other buttons if the message dialog is on screen
	{
		m_pSpinButton->setMousePosition(m_mousePosition);
		m_pSpinButton->ButtonClick();

		m_pResetButton->setMousePosition(m_mousePosition);
		m_pResetButton->ButtonClick();
		
		m_pQuitButton->setMousePosition(m_mousePosition);
		m_pQuitButton->ButtonClick();
		
		m_pValue1Button->setMousePosition(m_mousePosition);
		m_pValue5Button->setMousePosition(m_mousePosition);
		m_pValue10Button->setMousePosition(m_mousePosition);
		m_pValue50Button->setMousePosition(m_mousePosition);
		m_pValue100Button->setMousePosition(m_mousePosition);
		m_pValue500Button->setMousePosition(m_mousePosition);
		m_pValue1000Button->setMousePosition(m_mousePosition);

		m_pValue1Button->ButtonClick();
		m_pValue5Button->ButtonClick();
		m_pValue10Button->ButtonClick();
		m_pValue50Button->ButtonClick();
		m_pValue100Button->ButtonClick();
		m_pValue500Button->ButtonClick();
		m_pValue1000Button->ButtonClick();

		m_pValueMinus1Button->setMousePosition(m_mousePosition);
		m_pValueMinus5Button->setMousePosition(m_mousePosition);
		m_pValueMinus10Button->setMousePosition(m_mousePosition);
		m_pValueMinus50Button->setMousePosition(m_mousePosition);
		m_pValueMinus100Button->setMousePosition(m_mousePosition);
		m_pValueMinus500Button->setMousePosition(m_mousePosition);
		m_pValueMinus1000Button->setMousePosition(m_mousePosition);

		m_pValueMinus1Button->ButtonClick();
		m_pValueMinus5Button->ButtonClick();
		m_pValueMinus10Button->ButtonClick();
		m_pValueMinus50Button->ButtonClick();
		m_pValueMinus100Button->ButtonClick();
		m_pValueMinus500Button->ButtonClick();
		m_pValueMinus1000Button->ButtonClick();

	} else
	{
		m_pDialogButton->setMousePosition(m_mousePosition);
		m_pDialogButton->ButtonClick();
	}

	
	if(GameManager::Instance()->playerMoney <= 0)
	{
		m_pSpinButton->m_alpha = 100;
	}


}

void Level1Scene::clean()
{
	removeAllChildren();


}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}


void Level1Scene::handleEvents()
{
	ImGuiIO& io = ImGui::GetIO();
	int wheel = 0;

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;
		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:

				//Event handler for all buttons
				m_pSpinButton->setMouseButtonClicked(true);
				m_pResetButton->setMouseButtonClicked(true);
				m_pQuitButton->setMouseButtonClicked(true);
				
				m_pValue1Button->setMouseButtonClicked(true);
				m_pValue5Button->setMouseButtonClicked(true);
				m_pValue10Button->setMouseButtonClicked(true);
				m_pValue50Button->setMouseButtonClicked(true);
				m_pValue100Button->setMouseButtonClicked(true);
				m_pValue500Button->setMouseButtonClicked(true);
				m_pValue1000Button->setMouseButtonClicked(true);

				m_pValueMinus1Button->setMouseButtonClicked(true);
				m_pValueMinus5Button->setMouseButtonClicked(true);
				m_pValueMinus10Button->setMouseButtonClicked(true);
				m_pValueMinus50Button->setMouseButtonClicked(true);
				m_pValueMinus100Button->setMouseButtonClicked(true);
				m_pValueMinus500Button->setMouseButtonClicked(true);
				m_pValueMinus1000Button->setMouseButtonClicked(true);



				m_pDialogButton->setMouseButtonClicked(true);

				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pSpinButton->setMouseButtonClicked(false);
				
				m_pValue1Button->setMouseButtonClicked(false);
				m_pValue5Button->setMouseButtonClicked(false);
				m_pValue10Button->setMouseButtonClicked(false);
				m_pValue50Button->setMouseButtonClicked(false);
				m_pValue100Button->setMouseButtonClicked(false);
				m_pValue500Button->setMouseButtonClicked(false);
				m_pValue1000Button->setMouseButtonClicked(false);

				m_pValueMinus1Button->setMouseButtonClicked(false);
				m_pValueMinus5Button->setMouseButtonClicked(false);
				m_pValueMinus10Button->setMouseButtonClicked(false);
				m_pValueMinus50Button->setMouseButtonClicked(false);
				m_pValueMinus100Button->setMouseButtonClicked(false);
				m_pValueMinus500Button->setMouseButtonClicked(false);
				m_pValueMinus1000Button->setMouseButtonClicked(false);

				m_pResetButton->setMouseButtonClicked(false);
				m_pQuitButton->setMouseButtonClicked(false);
				
				m_pDialogButton->setMouseButtonClicked(false);

				updateInfoLabels();

				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_TEXTINPUT:
			io.AddInputCharactersUTF8(event.text.text);
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			case SDLK_BACKQUOTE:
				//m_displayUI = (m_displayUI) ? false : true;
				break;
			case SDLK_f:
				//std::cout << "**** NEW PATH ****" << std::endl;
				break;
			case SDLK_g:
				break;
			case SDLK_m:

				break;
			case SDLK_p:
				break;
			case SDLK_r:
				break;

				/************************************************************************/
			case SDLK_w:
				break;
			case SDLK_s:
				break;
			case SDLK_a:
				break;
			case SDLK_d:
				break;
			}
			{
				int key = event.key.keysym.scancode;
				IM_ASSERT(key >= 0 && key < IM_ARRAYSIZE(io.KeysDown));
				io.KeysDown[key] = (event.type == SDL_KEYDOWN);
				io.KeyShift = ((SDL_GetModState() & KMOD_SHIFT) != 0);
				io.KeyCtrl = ((SDL_GetModState() & KMOD_CTRL) != 0);
				io.KeyAlt = ((SDL_GetModState() & KMOD_ALT) != 0);
				io.KeySuper = ((SDL_GetModState() & KMOD_GUI) != 0);
			}
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:

				break;

			case SDLK_s:

				break;

			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}
			{
				int key = event.key.keysym.scancode;
				IM_ASSERT(key >= 0 && key < IM_ARRAYSIZE(io.KeysDown));
				io.KeysDown[key] = (event.type == SDL_KEYDOWN);
				io.KeyShift = ((SDL_GetModState() & KMOD_SHIFT) != 0);
				io.KeyCtrl = ((SDL_GetModState() & KMOD_CTRL) != 0);
				io.KeyAlt = ((SDL_GetModState() & KMOD_ALT) != 0);
				io.KeySuper = ((SDL_GetModState() & KMOD_GUI) != 0);
			}
			break;
		default:
			break;
		}
	}

	io.DeltaTime = 1.0f / 60.0f;
	int mouseX, mouseY;
	const int buttons = SDL_GetMouseState(&mouseX, &mouseY);
	io.MousePos = ImVec2(static_cast<float>(mouseX), static_cast<float>(mouseY));
	io.MouseDown[0] = buttons & SDL_BUTTON(SDL_BUTTON_LEFT);
	io.MouseDown[1] = buttons & SDL_BUTTON(SDL_BUTTON_RIGHT);
	io.MouseWheel = static_cast<float>(wheel);

	io.DisplaySize.x = 1280;
	io.DisplaySize.y = 720;


}