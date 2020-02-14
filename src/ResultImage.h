#pragma once
#ifndef __ResultImage__
#define __ResultImage__
#include "DisplayObject.h"
#include "ItemType.h"

class ResultImage : public DisplayObject
{
public:

	ResultImage(glm::vec2 positionToDraw);
	~ResultImage();

	// Inherited via GameObject
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	ItemType getItem();
	void setItem(ItemType item);

	ItemType item = SPIN;
	
private:

	glm::vec2 m_pPositionToDraw;
};



#endif

