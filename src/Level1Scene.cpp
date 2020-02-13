#include "Level1Scene.h"
#include "Game.h"
#include "GameManager.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>
#include <sstream>



// ImGui functions ***********************************************


void Level1Scene::m_ImGuiKeyMap()
{
	ImGuiIO& io = ImGui::GetIO();

	// Keyboard mapping. ImGui will use those indices to peek into the io.KeysDown[] array.
	io.KeyMap[ImGuiKey_Tab] = SDL_SCANCODE_TAB;
	io.KeyMap[ImGuiKey_LeftArrow] = SDL_SCANCODE_LEFT;
	io.KeyMap[ImGuiKey_RightArrow] = SDL_SCANCODE_RIGHT;
	io.KeyMap[ImGuiKey_UpArrow] = SDL_SCANCODE_UP;
	io.KeyMap[ImGuiKey_DownArrow] = SDL_SCANCODE_DOWN;
	io.KeyMap[ImGuiKey_PageUp] = SDL_SCANCODE_PAGEUP;
	io.KeyMap[ImGuiKey_PageDown] = SDL_SCANCODE_PAGEDOWN;
	io.KeyMap[ImGuiKey_Home] = SDL_SCANCODE_HOME;
	io.KeyMap[ImGuiKey_End] = SDL_SCANCODE_END;
	io.KeyMap[ImGuiKey_Insert] = SDL_SCANCODE_INSERT;
	io.KeyMap[ImGuiKey_Delete] = SDL_SCANCODE_DELETE;
	io.KeyMap[ImGuiKey_Backspace] = SDL_SCANCODE_BACKSPACE;
	io.KeyMap[ImGuiKey_Space] = SDL_SCANCODE_SPACE;
	io.KeyMap[ImGuiKey_Enter] = SDL_SCANCODE_RETURN;
	io.KeyMap[ImGuiKey_Escape] = SDL_SCANCODE_ESCAPE;

	io.KeyMap[ImGuiKey_A] = SDL_SCANCODE_A;
	io.KeyMap[ImGuiKey_C] = SDL_SCANCODE_C;
	io.KeyMap[ImGuiKey_V] = SDL_SCANCODE_V;
	io.KeyMap[ImGuiKey_X] = SDL_SCANCODE_X;
	io.KeyMap[ImGuiKey_Y] = SDL_SCANCODE_Y;
	io.KeyMap[ImGuiKey_Z] = SDL_SCANCODE_Z;
}

void Level1Scene::m_ImGuiSetStyle()
{
	ImGuiStyle& style = ImGui::GetStyle();

	style.Alpha = 0.8f;
	style.FrameRounding = 3.0f;
	style.Colors[ImGuiCol_Text] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.94f, 0.94f, 0.94f, 0.94f);
	style.Colors[ImGuiCol_ChildWindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_PopupBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.94f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.00f, 0.00f, 0.00f, 0.39f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(1.00f, 1.00f, 1.00f, 0.10f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.94f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.96f, 0.96f, 0.96f, 1.00f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 1.00f, 1.00f, 0.51f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.82f, 0.82f, 0.82f, 1.00f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.86f, 0.86f, 0.86f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.98f, 0.98f, 0.98f, 0.53f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.69f, 0.69f, 0.69f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.59f, 0.59f, 0.59f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.49f, 0.49f, 0.49f, 1.00f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.24f, 0.52f, 0.88f, 1.00f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	style.Colors[ImGuiCol_Column] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
	style.Colors[ImGuiCol_ColumnHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.78f);
	style.Colors[ImGuiCol_ColumnActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.50f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
	style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);
}

void Level1Scene::m_updateUI()
{
	// Prepare Window Frame
	ImGui::NewFrame();
	//ImGui::ShowDemoWindow(); // use for debug purposes

	std::string windowString = "Settings ";

	ImGui::Begin(&windowString[0], NULL, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_MenuBar);

	// set window to top left corner
	ImGui::SetWindowPos(ImVec2(300, 200), true);

	/*************************************************************************************************/
	/* MENU                                                                                          */
	/*************************************************************************************************/

	static int i0 = 123;
	ImGui::InputInt("Player bet: ", &i0);

	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			ImGui::Separator();
			ImGui::MenuItem("Exit", NULL, &m_exitApp);
			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Help"))
		{
			ImGui::Separator();
			ImGui::MenuItem("About", NULL, &m_displayAbout);
			ImGui::EndMenu();
		}
		ImGui::EndMenuBar();
	}

	if (m_exitApp)
	{
		TheGame::Instance()->quit();
	}

	if (m_displayAbout)
	{
		ImGui::Begin("About Slot Machine Game", &m_displayAbout, ImGuiWindowFlags_AlwaysAutoResize);
		ImGui::Separator();
		ImGui::Text("Authors:");
		ImGui::Text("Lucas Bittencourt ");
		ImGui::End();
	}

	/*************************************************************************************************/

	
	//if (ImGui::Button("Restart Game"))
	//{
	//	GameManager::Instance()->resetGame();
	//}

	//ImGui::SameLine();
	//ImGui::PushItemWidth(80);





	// Main Window End
	ImGui::End();
}

/*** SCENE FUNCTIONS ***/

void Level1Scene::start()
{

	GameManager::Instance()->resetGame();
	
	if (m_displayUI)
	{
		ImGui::NewFrame();
	}
	m_pBackground = new Background();

	m_pInfoLabel = new InfoLabel();
	m_pInfoLabel->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, 560));
	
	// allocates memory on the heap for this game object
	m_pSlotMachine = new SlotMachine();
	m_pSlotMachine->setPosition(glm::vec2(400, 250));
	m_pPlayButton = new PlayButton();
	m_pPlayButton->setPosition(glm::vec2(520, 450));

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

	m_pFirstImage = new ResultImage();
	m_pSecondImage = new ResultImage();
	m_pThirdImage = new ResultImage();

	m_pFirstImage->setPosition(glm::vec2(280, 270));
	m_pSecondImage->setPosition(glm::vec2(393, 270));
	m_pThirdImage->setPosition(glm::vec2(507, 270));

	resetButton = new ResetButton();
	quitButton = new QuitButton();

	resetButton->setPosition(glm::vec2(275, 450));
	quitButton->setPosition(glm::vec2(750, 760));
}

void Level1Scene::updateLabels() const
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
	Level1Scene::start();
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::draw()
{
	m_pBackground->draw();
	m_pInfoLabel->draw();

	m_pFirstImage->draw();
	m_pSecondImage->draw();
	m_pThirdImage->draw();
	
	m_pSlotMachine->draw();
	m_pPlayButton->draw();
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



	quitButton->draw();
	resetButton->draw();
	
	if (m_displayUI)
	{
		ImGui::Render();
		ImGuiSDL::Render(ImGui::GetDrawData());
		SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), 0, 0, 0, 255);
	}
}

void Level1Scene::update()
{
	m_pPlayButton->setMousePosition(m_mousePosition);
	m_pPlayButton->ButtonClick();

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

	if (m_displayUI)
	{
		m_updateUI();
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

				m_pPlayButton->setMouseButtonClicked(true);
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

				resetButton->setMouseButtonClicked(true);
				quitButton->setMouseButtonClicked(true);
				
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pPlayButton->setMouseButtonClicked(false);
				
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
				
				updateLabels();

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

	m_ImGuiKeyMap();
	m_ImGuiSetStyle();
}