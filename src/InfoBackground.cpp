#include "InfoBackground.h"
#include "Game.h"

InfoBackground::InfoBackground()
{

	TheTextureManager::Instance()->load("../Assets/textures/InfoBackground.png",
		"infoBackground", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("infoBackground");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(100, 100.0f));
	setType(INFO_LABEL);


}

InfoBackground::~InfoBackground()
{
}

void InfoBackground::draw()
{

	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("infoBackground", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);

}

void InfoBackground::update()
{
}

void InfoBackground::clean()
{
}
