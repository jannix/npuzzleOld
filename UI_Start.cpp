#include "UI_Start.h"
#include "UI_Panel.h"

void	__UI_Start_quitCbClickUp(ID::Control*, ID::Event*, void*)
{
	UI_Panel::GetInstance()->alive = false;
}

void	__UI_Start_playImageCbClickUp(ID::Control*, ID::Event*, void*)
{
	std::cout << "playImageClickUp" << std::endl;
	UI_Panel::GetInstance()->uiStart.SetOnScreen(false);
	UI_Panel::GetInstance()->uiLoadImage.SetOnScreen(true);
}

void	__UI_Start_playNumbersCbClickUp(ID::Control*, ID::Event*, void*)
{
	std::cout << "playNumbersClickUp" << std::endl;
	UI_Panel::GetInstance()->uiStart.SetOnScreen(false);
	UI_Panel::GetInstance()->uiSelectSize.SetOnScreen(true);
}

UI_Start::UI_Start() : ID::Drawable(UI_WIDTH, UI_HEIGHT, UI_FLAGS,
				    UI_RMASK, UI_GMASK,
				    UI_BMASK, UI_AMASK),
		       quitUI("Misc/nuke.bmp"),
		       currentPosition(DEFAULT_FONT_PATH, 15,
				       "New Game"),
		       playWithImage(500, 120, UI_FLAGS,
				     UI_RMASK, UI_GMASK,
				     UI_BMASK, UI_AMASK,
				     DEFAULT_FONT_PATH, 30,
				     "Play with image"),
		       playWithNumbers(500, 120, UI_FLAGS,
				       UI_RMASK, UI_GMASK,
				       UI_BMASK, UI_AMASK,
				       DEFAULT_FONT_PATH, 30,
				       "Play with numbers")
{
	this->quitUI.SetCbClickUp(__UI_Start_quitCbClickUp, NULL);
	this->AddChild(&(this->quitUI));

	this->currentPosition.SetPos(ID::REL_POS_TOP);
	this->currentPosition.SetColor(0x00FF00FF);
	this->AddChild(&(this->currentPosition));

	this->playWithImage.SetPos(ID::REL_POS_LEFT);
	this->playWithImage.GetLabel()->SetColor(0x00FF00FF);
	this->playWithImage.SetCbClickUp(__UI_Start_playImageCbClickUp, NULL);
	this->AddChild(&(this->playWithImage));

	this->playWithNumbers.SetPos(ID::REL_POS_RIGHT);
	this->playWithNumbers.GetLabel()->SetColor(0x00FF00FF);
	this->playWithNumbers.SetCbClickUp(__UI_Start_playNumbersCbClickUp, NULL);
	this->AddChild(&(this->playWithNumbers));
}

UI_Start::~UI_Start()
{
}
