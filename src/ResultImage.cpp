#include "ResultImage.h"
#include "Game.h"

ResultImage::ResultImage()
{

	TheTextureManager::Instance()->load("../Assets/textures/Spin.png",
		"resultImage", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("resultImage");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(100, 100.0f));
	setType(RESULT_IMAGE);

	
}

ResultImage::~ResultImage()
{
}

void ResultImage::draw()
{

	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("resultImage", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
	
}

void ResultImage::update()
{
}

void ResultImage::clean()
{
}
