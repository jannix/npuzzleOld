#ifndef	__UI_LOADIMAGE_H__
#define	__UI_LOADIMAGE_H__

#include "ID_glibrary.h"
#include "Constantes.h"

class	UI_LoadImage : public ID::Drawable
{
	public:
		UI_LoadImage();
		~UI_LoadImage();

		ID::Button_Image	quitUI;
		ID::Label		currentPosition;
		ID::Label		imageToLoad;
		ID::Button_Label	load;
		ID::Textbox		imagePath;
};

#endif
