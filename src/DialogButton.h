#pragma once
#ifndef __DIALOG__BUTTON__
#define __DIALOG__BUTTON__

#include "Button.h"

class DialogButton : public Button
{
public:
	DialogButton();
	~DialogButton();


	bool ButtonClick() override;


private:
	bool m_isClicked;
};

#endif /* defined (__PLAY_BUTTON__) */#pragma once
