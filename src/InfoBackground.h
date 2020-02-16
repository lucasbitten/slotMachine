#pragma once
#ifndef __INFO_BACKGROUND__
#define __INFO_BACKGROUND__
#include "DisplayObject.h"

class InfoBackground : public DisplayObject
{
public:

	InfoBackground();
	~InfoBackground();

	// Inherited via GameObject
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	
};



#endif

