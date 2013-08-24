#include "AI_Solver.h"
#include "UI_Panel.h"

AI_Solver::AI_Solver()
{
}

AI_Solver::~AI_Solver()
{
}

void	AI_Solver::Solver(void)
{
	Piece**	pb;

	pb = UI_Panel::GetInstance()->uiPlayBoard.playBoard;
	// C'est maintenant qu'il faille que tu fasses chauffer ton cerveau!
	// La structure Piece est dans UI_PlayBoard
}
//	int A = from
//	int x, y = Position targeted
//	Piece[A]->Swap(x, y);

bool	AI_Solver::CheckEndGame(void)
{
	UI_PlayBoard*	pb;
	Piece**		p;
	int		max;

	pb = &(UI_Panel::GetInstance()->uiPlayBoard);
	p = pb->playBoard;
	max = pb->cols * pb->rows - 1;
	while (max > 0)
	{
		if (!(p[max]->Valid()))
			return false;
		--max;
	}
	return true;
}
