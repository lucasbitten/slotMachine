#pragma once
#ifndef __ResultImage__
#define __ResultImage__
#include "DisplayObject.h"

class ResultImage : public DisplayObject
{
public:

	ResultImage();
	~ResultImage();

	// Inherited via GameObject
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	
};



#endif

