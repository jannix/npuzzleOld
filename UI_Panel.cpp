#include "UI_Panel.h"

UI_Panel::UI_Panel() : alive(true),
		       uiStart(),
		       uiLoadImage(),
		       hintInterval(NULL),
		       msInterval(0),
		       image(NULL)

{
}

UI_Panel::~UI_Panel()
{
	delete this->image;
}

void	UI_Panel::Init(ID::Window* w)
{
	this->uiStart.SetOnScreen(true);
	w->AddChild(&(this->uiStart));

	this->uiLoadImage.SetOnScreen(false);
	w->AddChild(&(this->uiLoadImage));

	this->uiSelectSize.SetOnScreen(false);
	w->AddChild(&(this->uiSelectSize));

	this->uiPlayBoard.SetOnScreen(false);
	w->AddChild(&(this->uiPlayBoard));

	this->win = w;
}
