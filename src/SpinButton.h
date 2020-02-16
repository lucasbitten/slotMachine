#pragma once
#ifndef __PLAY_BUTTON__
#define __PLAY_BUTTON__

#include "Button.h"

class SpinButton : public Button
{
public:
	SpinButton();
	~SpinButton();


	bool ButtonClick() override;
	
	
private:
	bool m_isClicked;
};

#endif /* defined (__PLAY_BUTTON__) */