#pragma once
#ifndef __END_SCENE__
#define __END_SCENE__

#include "Scene.h"
#include "Label.h"
#include "RestartButton.h"

class EndScene : public Scene
{
public:
	EndScene();
	~EndScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

	glm::vec2 getMousePosition();

private:
	glm::vec2 m_mousePosition;

	
	Label* m_pGameOverLabel;
	Label* m_pNoMoneyLabel;

	RestartButton* m_pRestartButton;
	
};

#endif /* defined (__END_SCENE__) */