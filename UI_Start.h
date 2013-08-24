#ifndef	__UI_START_H__
#define	__UI_START_H__

#include "ID_glibrary.h"
#include "Constantes.h"

class	UI_Start : public ID::Drawable
{
	public:
		UI_Start();
		~UI_Start();

		ID::Button_Image	quitUI;
		ID::Label		currentPosition;
		ID::Button_Label	playWithImage;
		ID::Button_Label	playWithNumbers;

};

#endif
