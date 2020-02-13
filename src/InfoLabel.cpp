#include "InfoLabel.h"
#include "Game.h"

InfoLabel::InfoLabel()
{

	TheTextureManager::Instance()->load("../Assets/textures/infoLabel.png",
		"infoLabel", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("infoLabel");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(100, 100.0f));
	setType(INFO_LABEL);


}

InfoLabel::~InfoLabel()
{
}

void InfoLabel::draw()
{

	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("infoLabel", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);

}

void InfoLabel::update()
{
}

void InfoLabel::clean()
{
}
