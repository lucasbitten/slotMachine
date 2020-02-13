#pragma once
#ifndef __INFO_LABEL__
#define __INFO_LABEL__
#include "DisplayObject.h"

class InfoLabel : public DisplayObject
{
public:

	InfoLabel();
	~InfoLabel();

	// Inherited via GameObject
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

};



#endif

