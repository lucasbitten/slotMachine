#pragma once
#ifndef __BACK_GROUND__
#define __BACK_GROUND__
#include "DisplayObject.h"

class Background : public DisplayObject
{
public:

	Background();
	~Background();

	// Inherited via GameObject
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

};



#endif

