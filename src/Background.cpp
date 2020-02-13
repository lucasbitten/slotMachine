#include "Background.h"
#include "Game.h"

Background::Background()
{

	TheTextureManager::Instance()->load("../Assets/textures/Background.png",
		"background", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("background");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(Config::SCREEN_WIDTH *0.5f,Config::SCREEN_HEIGHT*0.5f));
	setType(BACKGROUND);


}

Background::~Background()
{
}

void Background::draw()
{

	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("background", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);

}

void Background::update()
{
}

void Background::clean()
{
}
