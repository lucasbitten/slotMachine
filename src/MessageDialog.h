#pragma once
#ifndef __MESSAGE_DIALOG__
#define __MESSAGE_DIALOG__
#include "DisplayObject.h"

class MessageDialog : public DisplayObject
{
public:

	MessageDialog();
	~MessageDialog();

	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;;

};


#endif
