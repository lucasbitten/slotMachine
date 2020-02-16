#include "DialogButton.h"
#include "Game.h"
#include "GameManager.h"
#include "SoundManager.h"

DialogButton::DialogButton()
// call super constructor
    :Button(
        "../Assets/textures/DialogButton.png",
        "dialogButton",
        DIALOG_BUTTON, glm::vec2(500, 400)), m_isClicked(false)
{

}

DialogButton::~DialogButton()
{
}

bool DialogButton::ButtonClick()
{
    if (m_mouseOver() && m_mouseButtonClicked)
    {
        if (!m_isClicked)
        {
            TheSoundManager::Instance()->playSound("button", 0);
            GameManager::Instance()->showingMessage = false;

        }
        return true;
    }
    else
    {
        m_isClicked = false;
    }
    return false;
}


