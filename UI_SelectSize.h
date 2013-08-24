#ifndef	__UI_SELECTSIZE_H__
#define	__UI_SELECTSIZE_H__

#include "ID_glibrary.h"
#include "Constantes.h"

class	UI_SelectSize : public ID::Drawable
{
	public:
		UI_SelectSize();
		~UI_SelectSize();

		ID::Button_Image	quitUI;
		ID::Label		currentPosition;
		ID::Label		howManyCols;
		ID::Label		howManyRows;
		ID::Button_Label	play;
		ID::Textbox		cols;
		ID::Textbox		rows;
};

#endif
