#include "ResultImage.h"
#include "Game.h"

ResultImage::ResultImage(glm::vec2 pos)
{

	TheTextureManager::Instance()->load("../Assets/textures/MachineItems.png",
		"resultImage", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("resultImage");
	setWidth(size.x);
	setHeight(size.y);
	setType(RESULT_IMAGE);
	m_pPositionToDraw = pos;
	
}

ResultImage::~ResultImage()
{
}

void ResultImage::draw()
{

	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	//TheTextureManager::Instance()->draw("resultImage", xComponent, yComponent,
	//	TheGame::Instance()->getRenderer(), 0, 255, true);

	TheTextureManager::Instance()->drawFrame("resultImage", m_pPositionToDraw.x - 45, m_pPositionToDraw.y - 68, 100, 136, 0, item, TheGame::Instance()->getRenderer(), 0, 255, SDL_FLIP_NONE);
}

void ResultImage::update()
{
}

void ResultImage::clean()
{
}

ItemType ResultImage::getItem()
{
	return item;
}

void ResultImage::setItem(ItemType itemType)
{
	item = itemType;
}
