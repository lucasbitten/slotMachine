#pragma once
#ifndef __BetValueButton__
#define __BetValueButton__

#include "Button.h"

class BetValueButton : public Button
{
public:

	BetValueButton(int value);
	~BetValueButton();

	bool ButtonClick() override;
private:
	
	int valueToChange;
	bool m_isClicked;
	
	
};



#endif
