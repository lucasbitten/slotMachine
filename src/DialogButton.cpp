#include "DialogButton.h"
#include "Game.h"
#include "GameManager.h"

DialogButton::DialogButton()
// call super constructor
    :Button(
        "../Assets/textures/DialogButton.png",
        "dialogButton",
        PLAY_BUTTON, glm::vec2(500, 400)), m_isClicked(false)
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


