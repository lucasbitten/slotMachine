#include "MessageDialog.h"
#include "Game.h"

MessageDialog::MessageDialog()
{
	TheTextureManager::Instance()->load("../Assets/textures/MessageDialog.png",
		"messageDialog", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("messageDialog");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(100, 100.0f));
	setType(INFO_LABEL);
	
}

MessageDialog::~MessageDialog()
{
}

void MessageDialog::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("messageDialog", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void MessageDialog::update()
{
}

void MessageDialog::clean()
{
}
