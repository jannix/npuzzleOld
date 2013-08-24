#include "UI_PlayBoard.h"
#include "UI_Panel.h"
#include "AI_Solver.h"
#include <stdlib.h>
#include <iostream>

char*	itoa(int n)
{
	int	e;
	int	i;
	char*	c;

	e = 1;
	while (n / e >= 10 || n / e <= -10)
		e = e * 10;
	c = (char*)new char[12];
	if (c == NULL)
		return NULL;
	i = 0;
	if (n < 0)
		c[0] = '-';
	while (e != 0)
	{
		if (n >= 0)
			c[i] = ((n / e) % 10) + '0';
		else if (i != 0)
			c[i] = (n / e % 10) * -1 + '0';
		i = i + 1;
		if ((i > 1 && n < 0) || n >= 0)
			e = e / 10;
	}
	c[i] = 0;
	return c;
}

void	hint(void)
{
	std::cout << "Hint" << std::endl;
	AI_Solver::GetInstance()->Solver();
}

void	__UI_PlayBoard_giveUpCbClickUp(ID::Control*, ID::Event*, void*)
{
	std::cout << "giveUpClickUp" << std::endl;
	UI_Panel::GetInstance()->uiStart.SetOnScreen(true);
	UI_Panel::GetInstance()->uiPlayBoard.SetOnScreen(false);
}

void	__UI_PlayBoard_solveCbClickUp(ID::Control*, ID::Event*, void*)
{
	if (UI_Panel::GetInstance()->hintInterval == NULL)
	{
	UI_Panel::GetInstance()->hintInterval = hint;
	UI_Panel::GetInstance()->msInterval = atoi(UI_Panel::GetInstance()->uiPlayBoard.speed.GetText());
	if (UI_Panel::GetInstance()->msInterval < 20)
		UI_Panel::GetInstance()->msInterval = 20;
	}
	else
		UI_Panel::GetInstance()->hintInterval = NULL;
	std::cout << "solveClickUp" << std::endl;
}

void	__UI_PlayBoard_hintCbClickUp(ID::Control*, ID::Event*, void*)
{
	std::cout << "hintClickUp" << std::endl;
	hint();
}

void	__UI_PlayBoard_pieceCbClickUp(ID::Control*, ID::Event*, void* _d)
{
	UI_PlayBoard*	pb;
	Piece*		p;
	Piece*		hole;
	int		n;

	p = (Piece*)_d;
	pb = &(UI_Panel::GetInstance()->uiPlayBoard);
	n = pb->cols * pb->rows;
	hole = pb->playBoard[n - 1];
	if ((hole->iX == p->iX &&
	     (hole->iY == p->iY + 1 || hole->iY == p->iY - 1)) ||
	    (hole->iY == p->iY &&
	     (hole->iX == p->iX + 1 || hole->iX == p->iX - 1)))
	{
		p->Swap(hole->iX, hole->iY);
		if (AI_Solver::GetInstance()->CheckEndGame())
		{
			std::cout << "End game" << std::endl;
		}
	}
//	while (n > 0)
//	{
//		--n;
//	}
	std::cout << "pieceClickUp" << std::endl;
}


UI_PlayBoard::UI_PlayBoard() : ID::Drawable(UI_WIDTH, UI_HEIGHT, UI_FLAGS,
					    UI_RMASK, UI_GMASK,
					    UI_BMASK, UI_AMASK),
			       giveUp("Misc/nuke.bmp"),
			       hint(220, 60, UI_FLAGS,
				    UI_RMASK, UI_GMASK,
				    UI_BMASK, UI_AMASK,
				    DEFAULT_FONT_PATH, 50,
				    "Hint"),
			       solve(100, 30, UI_FLAGS,
				     UI_RMASK, UI_GMASK,
				     UI_BMASK, UI_AMASK,
				     DEFAULT_FONT_PATH, 25,
				     "Solve"),
			       askSpeed(DEFAULT_FONT_PATH, 30,
					"Speed (ms)"),
			       speed(100, 30, UI_FLAGS,
				     UI_RMASK, UI_GMASK,
				     UI_BMASK, UI_AMASK,
				     DEFAULT_FONT_PATH, 25),
			       playBoard(NULL)
{
	ID::Font*	font;
	int		w;
	int		h;

	this->giveUp.SetPos((ID::REL_POS_TYPE)(ID::REL_POS_TOP | ID::REL_POS_LEFT));
	this->giveUp.SetCbClickUp(__UI_PlayBoard_giveUpCbClickUp, 0);
	this->AddChild(&(this->giveUp));

	this->solve.SetPos(900,
			   570);
	this->solve.GetLabel()->SetColor(0x0000FFFF);
	this->solve.SetCbClickUp(__UI_PlayBoard_solveCbClickUp, 0);
	this->AddChild(&(this->solve));

	font = ID::Font::GetInstance();
	if (font->SizeText(this->askSpeed.GetPolice()->font,
			   this->askSpeed.GetText(),
			   &w, &h) == -1)
		throw 10;
	this->askSpeed.SetPos(UI_WIDTH - w,
			      600);
	this->askSpeed.SetColor(0x00FF00FF);
	this->AddChild(&(this->askSpeed));

	this->speed.SetPos(900,
			   650);
	this->speed.SetBackground(0xFFFFFFFF);
	this->speed.SetColor(0x00FF00FF);
	this->speed.SetMaxLength(4);
	this->AddChild(&(this->speed));

	this->hint.SetPos(800,
			  100);
	this->hint.GetLabel()->SetColor(0x0000FFFF);
	this->hint.SetCbClickUp(__UI_PlayBoard_hintCbClickUp, 0);
	this->AddChild(&(this->hint));
}

UI_PlayBoard::~UI_PlayBoard()
{
	int	n;

	n = this->cols * this->rows;
	while (n > 0)
	{
		--n;
		this->DelChild(&(this->playBoard[n]->bPiece));
		delete this->playBoard[n];
	}
	delete[] this->playBoard;
}

int	UI_PlayBoard::Init_Board(int c, int r)
{
	int		w;
	int		h;
	int		n;

	if (this->playBoard != NULL)
	{
		n = this->cols * this->rows;
		while (n > 0)
		{
			--n;
			this->DelChild(&(this->playBoard[n]->bPiece));
			delete this->playBoard[n];
		}
		delete[] this->playBoard;
	}
	this->cols = c;
	this->rows = r;
	n = c * r;
	w = PLAYBOARD_WIDTH / c;
	h = PLAYBOARD_HEIGHT / r;
	this->playBoard = new Piece*[n];
	if (this->playBoard == NULL)
		return -1;
	while (n > 0)
	{
		--n;
		this->playBoard[n] = new Piece(w, h, n);
		if (this->playBoard == NULL)
			return -1;
	}
	while (1)
	{
		this->Shuffle_Board();
		if (this->Valid_Board() == true)
		{
			if (AI_Solver::GetInstance()->CheckEndGame())
			{
				std::cout << "Game solved -_-" << std::endl;
				continue ;
			}
			break ;
		}
	}
	return 0;
}

Piece::Piece(int w, int h, int n) : bPiece(w, h, UI_FLAGS, UI_RMASK, UI_GMASK, UI_BMASK, UI_AMASK, DEFAULT_FONT_PATH, h >> 2, "A"),
			     iX((n % UI_Panel::GetInstance()->uiPlayBoard.cols)),
			     iY((n / UI_Panel::GetInstance()->uiPlayBoard.cols)),
			     iN(n),
			     csN(NULL)
{
	this->csN = itoa(n);
	this->bPiece.GetLabel()->SetText(this->csN);
	this->bPiece.SetPos(this->iX * w, this->iY * h + 80);
	this->bPiece.GetLabel()->SetColor(0xB4A04CFF);
	this->bPiece.SetBackground(0xFF504CFF);
	UI_Panel::GetInstance()->uiPlayBoard.AddChild(&(this->bPiece));
}

void	UI_PlayBoard::Shuffle_Board(void)
{
	int	i;
	int	x;
	int	max;

	srand((int)&i + rand());
	max = this->cols * this->rows;
	i = 0;
	while (i < max)
	{
		x =(rand() % (max));
		this->playBoard[i]->Swap(x % this->cols, x / this->cols);
//		std::cout << i << " -> " << x % this->cols << "|" <<
//					    x / this->cols << std::endl;
		++i;
	}
}

int	UI_PlayBoard::Valid_Board(void)
{
	int	parity;
	int	permutations;
	int	max;

	max = this->cols * this->rows - 1;
	parity = (this->cols + this->rows - 2) -
		 (this->playBoard[max]->iX + this->playBoard[max]->iY);
	permutations = this->__PermuteAll();
//	std::cout << "PA=" << parity <<
//		     "-PE=" << permutations << std::endl;
	return ((parity % 2) == (permutations % 2));
}

int	UI_PlayBoard::__PermuteHole(std::map<int, int>* pieces)
{
	int	i;
	int	tmp;
	int	max;

	max = this->cols * this->rows - 1;
	i = 0;
	while ((*pieces)[i] != max)
	{
//		std::cout << i << "=" << (*pieces)[i] << std::endl;
		++i;
	}
	if (i != max)
	{
		tmp = (*pieces)[(*pieces)[i]];
		(*pieces)[(*pieces)[i]] = (*pieces)[i];
		(*pieces)[i] = tmp;
		return 1;
	}
	return 0;
}

int	UI_PlayBoard::__PermuteAll(void)
{
	std::map<int, int>	pieces;
	int			i;
	int			permutations;
	int			tmp;

	pieces = this->__ConvertPiecesToInt();
	permutations = this->__PermuteHole(&pieces);
//	std::cout << "PERMUT" << permutations << std::endl;
	i = this->cols * this->rows - 2;
	while (i >= 0)
	{
		if (pieces[i] != i)
		{
			tmp = pieces[pieces[i]];
			pieces[pieces[i]] = pieces[i];
			pieces[i] = tmp;
			++permutations;
		}
		--i;
	}
	return permutations;
}

std::map<int, int>	UI_PlayBoard::__ConvertPiecesToInt(void)
{
	std::map<int, int>	pieces;
	int			n;

	n = this->cols * this->rows;
	while (n > 0)
	{
		--n;
		pieces[n] = this->playBoard[n]->iX +
			    this->playBoard[n]->iY * this->cols;
//		std::cout << n << "=" << pieces[n] <<
//			     this->playBoard[n]->iX <<
//			     this->playBoard[n]->iY << std::endl;
	}
	return pieces;
}

Piece::~Piece()
{
	delete this->csN;
}

void	Piece::Swap(int x, int y)
{
	UI_PlayBoard*	pb;
	int		i;

	pb = &(UI_Panel::GetInstance()->uiPlayBoard);
	i = pb->cols * pb->rows;
	while (i > 0)
	{
		--i;
		if (pb->playBoard[i]->iX == x &&
		    pb->playBoard[i]->iY == y)
		{
			pb->playBoard[i]->iX = this->iX;
			pb->playBoard[i]->iY = this->iY;
			pb->playBoard[i]->bPiece.SetPos(this->iX * this->bPiece.GetWidth(),
					    this->iY * this->bPiece.GetHeight() + 80);
		}
	}
	this->iX = x;
	this->iY = y;
	x = x * this->bPiece.GetWidth();
	y = y * this->bPiece.GetHeight() + 80;
	this->bPiece.SetPos(x, y);
	this->bPiece.SetCbClickUp(__UI_PlayBoard_pieceCbClickUp, this);
}

bool	Piece::Valid(void)
{
	UI_PlayBoard*	pb;

	pb = &(UI_Panel::GetInstance()->uiPlayBoard);
	return this->iN % pb->cols == this->iX &&
	       this->iN / pb->cols == this->iY;
}
