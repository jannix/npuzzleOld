#ifndef	__UI_PANEL_H__
#define	__UI_PANEL_H__

#include "ID_glibrary.h"
#include "UI_Start.h"
#include "UI_LoadImage.h"
#include "UI_SelectSize.h"
#include "UI_PlayBoard.h"

class	UI_Panel : public Singleton<UI_Panel>
{
	friend class	Singleton<UI_Panel>;
	public:
		void	Init(ID::Window* w);

	public:
		ID::Window*	win;
		bool		alive;
		UI_Start	uiStart;
		UI_LoadImage	uiLoadImage;
		UI_SelectSize	uiSelectSize;
		UI_PlayBoard	uiPlayBoard;
		void		(*hintInterval)(void);
		int		msInterval;
		ID::Surface*	image;

	private:
		UI_Panel();
		~UI_Panel();
};

#endif
