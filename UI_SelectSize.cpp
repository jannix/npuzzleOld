#include "UI_SelectSize.h"
#include "UI_Panel.h"
#include <iostream>

void	__UI_SelectSize_quitCbClickUp(ID::Control*, ID::Event*, void*)
{
	std::cout << "quitClickUp" << std::endl;
	UI_Panel::GetInstance()->uiStart.SetOnScreen(true);
	UI_Panel::GetInstance()->uiSelectSize.SetOnScreen(false);
}

void	__UI_SelectSize_playCbClickUp(ID::Control*, ID::Event*, void* data)
{
	UI_SelectSize*	UI;
	int	c;
	int	r;

	UI = (UI_SelectSize*)data;
	c = atoi(UI->cols.GetText());
	r = atoi(UI->rows.GetText());
	if (c > 1 && r > 1 && c <= 15 && r <= 15)
	{
		UI_Panel::GetInstance()->uiSelectSize.SetOnScreen(false);
		UI_Panel::GetInstance()->uiPlayBoard.SetOnScreen(true);
		UI_Panel::GetInstance()->uiPlayBoard.Init_Board(c, r);
	}
}

UI_SelectSize::UI_SelectSize() : ID::Drawable(UI_WIDTH, UI_HEIGHT, UI_FLAGS,
					    UI_RMASK, UI_GMASK,
					    UI_BMASK, UI_AMASK),
			       quitUI("Misc/nuke.bmp"),
			       currentPosition(DEFAULT_FONT_PATH, 15,
					       "New Game -> Select Size"),
			       howManyCols(DEFAULT_FONT_PATH, 30,
					   "How many cols:"),
			       howManyRows(DEFAULT_FONT_PATH, 30,
					   "How many rows:"),
			       play(500, 120, UI_FLAGS,
				    UI_RMASK, UI_GMASK,
				    UI_BMASK, UI_AMASK,
				    DEFAULT_FONT_PATH, 50,
				    "- - Play - -"),
			       cols(100, 30, UI_FLAGS,
				    UI_RMASK, UI_GMASK,
				    UI_BMASK, UI_AMASK,
				    DEFAULT_FONT_PATH, 25),
			       rows(100, 30, UI_FLAGS,
				    UI_RMASK, UI_GMASK,
				    UI_BMASK, UI_AMASK,
				    DEFAULT_FONT_PATH, 25)

{
	ID::Font*	font;
	int		w;
	int		h;

	this->quitUI.SetPos((ID::REL_POS_TYPE)(ID::REL_POS_BOT | ID::REL_POS_RIGHT));
	this->quitUI.SetCbClickUp(__UI_SelectSize_quitCbClickUp, NULL);
	this->AddChild(&(this->quitUI));

	this->currentPosition.SetPos(ID::REL_POS_TOP);
	this->currentPosition.SetColor(0x00FF00FF);
	this->AddChild(&(this->currentPosition));

	font = ID::Font::GetInstance();
	if (font->SizeText(this->howManyCols.GetPolice()->font,
			   this->howManyCols.GetText(),
			   &w, &h) == -1)
		throw 10;
	this->howManyCols.SetPos(50,
			         (UI_HEIGHT >> 1) - 50 -
			         (h >> 1));
	this->howManyCols.SetColor(0x00FF00FF);
	this->AddChild(&(this->howManyCols));

	this->cols.SetPos(w + 80,
			  (UI_HEIGHT >> 1) - 50 -
			  (h >> 1));
	this->cols.SetBackground(0xFFFFFFFF);
	this->cols.SetColor(0x0000FFFF);
	this->cols.SetMaxLength(2);
	this->AddChild(&(this->cols));

	if (font->SizeText(this->howManyRows.GetPolice()->font,
			   this->howManyRows.GetText(),
			   &w, &h) == -1)
		throw 10;
	this->howManyRows.SetPos(50,
			         (UI_HEIGHT >> 1) + 50 -
			         (h >> 1));
	this->howManyRows.SetColor(0x00FF00FF);
	this->AddChild(&(this->howManyRows));

	this->rows.SetPos(w + 80,
			  (UI_HEIGHT >> 1) + 50 -
			  (h >> 1));
	this->rows.SetBackground(0xFFFFFFFF);
	this->rows.SetColor(0x0000FFFF);
	this->rows.SetMaxLength(2);
	this->AddChild(&(this->rows));

	this->play.SetPos(ID::REL_POS_BOT);
	this->play.GetLabel()->SetColor(0x00FF00FF);
	this->play.SetCbClickUp(__UI_SelectSize_playCbClickUp, this);
	this->AddChild(&(this->play));
}

UI_SelectSize::~UI_SelectSize()
{
}
