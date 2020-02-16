#include "ResultImage.h"
#include "Game.h"
#include "GameManager.h"

ResultImage::ResultImage(glm::vec2 pos)
{

	TheTextureManager::Instance()->load("../Assets/textures/MachineItems.png",
		"resultImage", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/ItemsAnimation.png",
		"animation", TheGame::Instance()->getRenderer());
	
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("resultImage");
	setWidth(size.x);
	setHeight(size.y);
	setType(RESULT_IMAGE);
	m_pPositionToDraw = pos;
	frameOffset = rand() % (8) + 1;
	frame = frameOffset;

}

ResultImage::~ResultImage()
{
}

void ResultImage::draw()
{

	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	if (frame > 22)
	{
		cyclesCount++;
		frame = 1;
	}

	if(cyclesCount == 4)
	{
		cyclesCount = 0;
		frame = 1;
		TheGameManager::Instance()->waitingAnimation = false;

	}
	
	
	if (GameManager::Instance()->waitingAnimation)
	{
		
		TheTextureManager::Instance()->drawFrame("animation", m_pPositionToDraw.x - 45, m_pPositionToDraw.y - 68, 100, 136, 0, (int)frame*0.35f, TheGame::Instance()->getRenderer(), 0, 255, SDL_FLIP_NONE);
		frame ++;
	} else
	{
		cyclesCount = 0;

		TheTextureManager::Instance()->drawFrame("resultImage", m_pPositionToDraw.x - 45, m_pPositionToDraw.y - 68, 100, 136, 0, item, TheGame::Instance()->getRenderer(), 0, 255, SDL_FLIP_NONE);
	}

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
