#ifndef	__UI_PLAYBOARD_H__
#define	__UI_PLAYBOARD_H__

#include "ID_glibrary.h"
#include "Constantes.h"
#include <map>

class	Piece;

class	UI_PlayBoard : public ID::Drawable
{
	public:
			UI_PlayBoard();
			~UI_PlayBoard();
		int	Init_Board(int c, int r);
		void	Shuffle_Board(void);
		int	Valid_Board(void);

	public:
		ID::Button_Image	giveUp;
		ID::Button_Label	hint;
		ID::Button_Label	solve;
		ID::Label		askSpeed;
		ID::Textbox		speed;
		Piece**			playBoard;

		int			cols;
		int			rows;

	private:
		int			__PermuteHole(std::map<int, int>* pieces);
		int			__PermuteAll(void);
		std::map<int, int>	__ConvertPiecesToInt(void);
};

class	Piece
{
	public:
			Piece(int w, int h, int n);
			~Piece();
		void	Swap(int x, int y);
		bool	Valid(void);

	public:
		ID::Button_Label	bPiece;
		int			iX;
		int			iY;
		int			iN;
		char*			csN;
};

#endif
