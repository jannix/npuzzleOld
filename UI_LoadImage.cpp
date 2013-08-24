#include "UI_LoadImage.h"
#include "UI_Panel.h"
#include <iostream>

void	__UI_LoadImage_quitCbClickUp(ID::Control*, ID::Event*, void*)
{
	std::cout << "quitClickUp" << std::endl;
	UI_Panel::GetInstance()->uiStart.SetOnScreen(true);
	UI_Panel::GetInstance()->uiLoadImage.SetOnScreen(false);
}

void	__UI_LoadImage_loadCbClickUp(ID::Control*, ID::Event*, void*)
{
	std::cout << "loadClickUp" << std::endl;
	UI_Panel::GetInstance()->uiStart.SetOnScreen(false);
	UI_Panel::GetInstance()->uiSelectSize.SetOnScreen(true);
}

UI_LoadImage::UI_LoadImage() : ID::Drawable(UI_WIDTH, UI_HEIGHT, UI_FLAGS,
					    UI_RMASK, UI_GMASK,
					    UI_BMASK, UI_AMASK),
			       quitUI("Misc/nuke.bmp"),
			       currentPosition(DEFAULT_FONT_PATH, 15,
					       "New Game -> Load Image"),
			       imageToLoad(DEFAULT_FONT_PATH, 30,
					   "Image to load:"),
			       load(500, 120, UI_FLAGS,
				    UI_RMASK, UI_GMASK,
				    UI_BMASK, UI_AMASK,
				    DEFAULT_FONT_PATH, 30,
				    "Load"),
			       imagePath(500, 30, UI_FLAGS,
					 UI_RMASK, UI_GMASK,
					 UI_BMASK, UI_AMASK,
					 DEFAULT_FONT_PATH, 25)
{
	ID::Font*	font;
	int		w;
	int		h;

	this->quitUI.SetPos((ID::REL_POS_TYPE)(ID::REL_POS_TOP | ID::REL_POS_RIGHT));
	this->quitUI.SetCbClickUp(__UI_LoadImage_quitCbClickUp, 0);
	this->AddChild(&(this->quitUI));

	this->currentPosition.SetPos(ID::REL_POS_TOP);
	this->currentPosition.SetColor(0x00FF00FF);
	this->AddChild(&(this->currentPosition));

	font = ID::Font::GetInstance();
	if (font->SizeText(this->imageToLoad.GetPolice()->font,
			   this->imageToLoad.GetText(),
			   &w, &h) == -1)
		throw 10;
	this->imageToLoad.SetPos((UI_WIDTH >> 1) - (w >> 1),
			         (UI_HEIGHT >> 1) - 50 -
			         (h >> 1));
	this->imageToLoad.SetColor(0x00FF00FF);
	this->AddChild(&(this->imageToLoad));

	this->load.SetPos((UI_WIDTH >> 1) -
			  (this->load.GetWidth() >> 1),
			  (UI_HEIGHT >> 1) + 50 -
			  (this->load.GetHeight() >> 1));
	this->load.GetLabel()->SetColor(0x00FF00FF);
	this->load.SetCbClickUp(__UI_LoadImage_loadCbClickUp, NULL);
	this->AddChild(&(this->load));

	this->imagePath.SetPos((UI_WIDTH >> 1) -
			       (this->imagePath.GetWidth() >> 1),
			       (UI_HEIGHT >> 1) -
			       (this->imagePath.GetHeight() >> 1));
	this->imagePath.SetBackground(0xFFFFFFFF);
	this->imagePath.SetColor(0x0000FFFF);
	this->AddChild(&(this->imagePath));
}

UI_LoadImage::~UI_LoadImage()
{
}
