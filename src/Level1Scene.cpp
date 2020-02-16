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
	
	resetButton = new ResetButton();
	resetButton->setPosition(glm::vec2(275, 450));
	
	quitButton = new QuitButton();
	quitButton->setPosition(glm::vec2(750, 760));
	
	SDL_Color color = { 255, 0, 0, 255 };
	
	m_pJackPotLabel = new Label("Jackpot: " + std::to_string(GameManager::Instance()->jackpot), "digital-7", 30, color, glm::vec2(150,515));
	m_pPlayerMoneyLabel = new Label("Money: " + std::to_string(GameManager::Instance()->playerMoney), "digital-7", 30, color, glm::vec2(400, 515));
	m_pTurnLabel = new Label("Turn: " + std::to_string(GameManager::Instance()->turn), "digital-7", 30, color, glm::vec2(600, 515));
	m_pWinLabel = new Label("Wins: " + std::to_string(GameManager::Instance()->winNumber), "digital-7", 30, color, glm::vec2(150, 565));
	m_pLossesLabel = new Label("Losses: " + std::to_string(GameManager::Instance()->lossNumber), "digital-7", 30, color, glm::vec2(400, 565));
	m_pWinRatioLabel = new Label("Win ratio: 00.00%", "digital-7", 30, color, glm::vec2(600, 565));
	m_pBetLabel = new Label("Your Bet: " + std::to_string(GameManager::Instance()->playerBet), "digital-7", 35, color, glm::vec2(150, 620));

	value1Button = new BetValueButton(1);
	value5Button = new BetValueButton(5);
	value10Button = new BetValueButton(10);
	value50Button = new BetValueButton(50);
	value100Button = new BetValueButton(100);
	value500Button = new BetValueButton(500);
	value1000Button = new BetValueButton(1000);

	value1Button->setPosition(glm::vec2(50, 700));
	value5Button->setPosition(glm::vec2(110, 700));
	value10Button->setPosition(glm::vec2(170, 700));
	value50Button->setPosition(glm::vec2(230, 700));
	value100Button->setPosition(glm::vec2(290, 700));
	value500Button->setPosition(glm::vec2(350, 700));
	value1000Button->setPosition(glm::vec2(410, 700));

	valueMinus1Button = new BetValueButton(-1);
	valueMinus5Button = new BetValueButton(-5);
	valueMinus10Button = new BetValueButton(-10);
	valueMinus50Button = new BetValueButton(-50);
	valueMinus100Button = new BetValueButton(-100);
	valueMinus500Button = new BetValueButton(-500);
	valueMinus1000Button = new BetValueButton(-1000);
		 
	valueMinus1Button->setPosition(glm::vec2(50, 760));
	valueMinus5Button->setPosition(glm::vec2(110, 760));
	valueMinus10Button->setPosition(glm::vec2(170, 760));
	valueMinus50Button->setPosition(glm::vec2(230, 760));
	valueMinus100Button->setPosition(glm::vec2(290, 760));
	valueMinus500Button->setPosition(glm::vec2(350, 760));
	valueMinus1000Button->setPosition(glm::vec2(410, 760));

	
	message = new MessageDialog();
	message->setPosition(glm::vec2(Config::SCREEN_WIDTH*0.5f, Config::SCREEN_HEIGHT*0.5f));
	dialogButton = new DialogButton();
	dialogButton->setPosition(glm::vec2(560, 500));
	messageTextLabelLine1 = new Label(" ","Anton-Regular",20, color,glm::vec2(400,280));
	messageTextLabelLine2 = new Label(" ", "Anton-Regular", 20, color, glm::vec2(400, 320));

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
	quitButton->draw();
	resetButton->draw();
	
	m_pJackPotLabel->draw();
	m_pPlayerMoneyLabel->draw();
	m_pTurnLabel->draw();
	m_pWinLabel->draw();
	m_pLossesLabel->draw();
	m_pWinRatioLabel->draw();
	m_pBetLabel->draw();


	value1Button    ->draw();
	value5Button	->draw();
	value10Button	->draw();
	value50Button	->draw();
	value100Button	->draw();
	value500Button	->draw();
	value1000Button	->draw();

	valueMinus1Button->draw();
	valueMinus5Button->draw();
	valueMinus10Button->draw();
	valueMinus50Button->draw();
	valueMinus100Button->draw();
	valueMinus500Button->draw();
	valueMinus1000Button->draw();

	
	if (GameManager::Instance()->showingMessage) //Draw the message dialog box only when needed
	{
		messageTextLabelLine1->setText(GameManager::Instance()->messageContentLine1);
		messageTextLabelLine2->setText(GameManager::Instance()->messageContentLine2);

		message->draw();
		messageTextLabelLine1->draw();
		messageTextLabelLine2->draw();
		dialogButton->draw();
	}
}

void Level1Scene::update()
{
	//Seting the images result of each draw
	m_pFirstImage->setItem(GameManager::Instance()->itemsResult[0]);
	m_pSecondImage->setItem(GameManager::Instance()->itemsResult[1]);
	m_pThirdImage->setItem(GameManager::Instance()->itemsResult[2]);

	
	if (!GameManager::Instance()->showingMessage && !GameManager::Instance()->waitingAnimation) // Disabling other buttons if the message dialog is on screen
	{
		m_pSpinButton->setMousePosition(m_mousePosition);
		m_pSpinButton->ButtonClick();

		resetButton->setMousePosition(m_mousePosition);
		resetButton->ButtonClick();
		
		quitButton->setMousePosition(m_mousePosition);
		quitButton->ButtonClick();
		
		value1Button->setMousePosition(m_mousePosition);
		value5Button->setMousePosition(m_mousePosition);
		value10Button->setMousePosition(m_mousePosition);
		value50Button->setMousePosition(m_mousePosition);
		value100Button->setMousePosition(m_mousePosition);
		value500Button->setMousePosition(m_mousePosition);
		value1000Button->setMousePosition(m_mousePosition);

		value1Button->ButtonClick();
		value5Button->ButtonClick();
		value10Button->ButtonClick();
		value50Button->ButtonClick();
		value100Button->ButtonClick();
		value500Button->ButtonClick();
		value1000Button->ButtonClick();

		valueMinus1Button->setMousePosition(m_mousePosition);
		valueMinus5Button->setMousePosition(m_mousePosition);
		valueMinus10Button->setMousePosition(m_mousePosition);
		valueMinus50Button->setMousePosition(m_mousePosition);
		valueMinus100Button->setMousePosition(m_mousePosition);
		valueMinus500Button->setMousePosition(m_mousePosition);
		valueMinus1000Button->setMousePosition(m_mousePosition);

		valueMinus1Button->ButtonClick();
		valueMinus5Button->ButtonClick();
		valueMinus10Button->ButtonClick();
		valueMinus50Button->ButtonClick();
		valueMinus100Button->ButtonClick();
		valueMinus500Button->ButtonClick();
		valueMinus1000Button->ButtonClick();

	} else
	{
		dialogButton->setMousePosition(m_mousePosition);
		dialogButton->ButtonClick();
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
				resetButton->setMouseButtonClicked(true);
				quitButton->setMouseButtonClicked(true);
				
				value1Button->setMouseButtonClicked(true);
				value5Button->setMouseButtonClicked(true);
				value10Button->setMouseButtonClicked(true);
				value50Button->setMouseButtonClicked(true);
				value100Button->setMouseButtonClicked(true);
				value500Button->setMouseButtonClicked(true);
				value1000Button->setMouseButtonClicked(true);

				valueMinus1Button->setMouseButtonClicked(true);
				valueMinus5Button->setMouseButtonClicked(true);
				valueMinus10Button->setMouseButtonClicked(true);
				valueMinus50Button->setMouseButtonClicked(true);
				valueMinus100Button->setMouseButtonClicked(true);
				valueMinus500Button->setMouseButtonClicked(true);
				valueMinus1000Button->setMouseButtonClicked(true);



				dialogButton->setMouseButtonClicked(true);

				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pSpinButton->setMouseButtonClicked(false);
				
				value1Button->setMouseButtonClicked(false);
				value5Button->setMouseButtonClicked(false);
				value10Button->setMouseButtonClicked(false);
				value50Button->setMouseButtonClicked(false);
				value100Button->setMouseButtonClicked(false);
				value500Button->setMouseButtonClicked(false);
				value1000Button->setMouseButtonClicked(false);

				valueMinus1Button->setMouseButtonClicked(false);
				valueMinus5Button->setMouseButtonClicked(false);
				valueMinus10Button->setMouseButtonClicked(false);
				valueMinus50Button->setMouseButtonClicked(false);
				valueMinus100Button->setMouseButtonClicked(false);
				valueMinus500Button->setMouseButtonClicked(false);
				valueMinus1000Button->setMouseButtonClicked(false);

				resetButton->setMouseButtonClicked(false);
				quitButton->setMouseButtonClicked(false);
				
				dialogButton->setMouseButtonClicked(false);

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