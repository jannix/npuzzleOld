#include "ID_glibrary.h"
#include "UI_Panel.h"
#include <iostream>
#include <sys/time.h>

int	propagateEvent(ID::Window* w, ID::Event* e)
{
	if (e->type == ID::EVENT_MOTION)
		w->Motion(e);
	else if (e->type == ID::EVENT_CLICK_DOWN)
		w->ClickDown(e);
	else if (e->type == ID::EVENT_CLICK_UP)
		w->ClickUp(e);
	else if (e->type == ID::EVENT_KEY_DOWN)
		w->KeyDown(e);
	else if (e->type == ID::EVENT_KEY_UP)
		w->KeyUp(e);
	else if (e->type == ID::EVENT_QUIT)
		return 1;
	return 0;
}

int	main()
{
	if (ID::Init(SDL_INIT_VIDEO) == -1)
	{
		std::cout << "Fatal Error: ID::Init()" << std::endl;
		return -1;
	}
	ID::Window*		win;
	ID::Wrapper_Event*	we;
	ID::Event		event;
	UI_Panel*		uiPanel;
	struct timeval		tv;
	struct timeval		tv_next;

	win = new ID::Window(1024, 768, SDL_SWSURFACE);
	if (ID::InitWrappers() == -1)
	{
		std::cout << "Fatal Error: ID::Init()" << std::endl;
		return -1;
	}

	we = ID::Wrapper_Event::GetInstance();

	uiPanel = UI_Panel::GetInstance();
	uiPanel->Init(win);

	win->RefreshSurface();
	win->Update(0);
	timerclear(&tv);
	while (uiPanel->alive == true)
	{
		if (uiPanel->hintInterval != NULL &&
		    gettimeofday(&tv, NULL) == 0 &&
		    timercmp(&tv, &tv_next, >))
		{
			uiPanel->hintInterval();
			if (gettimeofday(&tv_next, NULL) == 0)
				tv_next.tv_usec += uiPanel->msInterval * 1000;
		}
		if (we->PollEvent(&event))
		{
			if (propagateEvent(win, &event) == 1)
				uiPanel->alive = false;
		}
		win->RefreshSurface();
		win->Update();
	}
	uiPanel->Kill();
	ID::DestroyWrappers();
	ID::Quit();
	return 0;
}
