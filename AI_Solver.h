#ifndef	_AI_SOLVER_H__
#define	_AI_SOLVER_H__

#include "UI_Panel.h"

class	AI_Solver : public Singleton<AI_Solver>
{
	friend class	Singleton<AI_Solver>;
	public:
		void	Solver(void);
		bool	CheckEndGame(void);

	private:
		AI_Solver();
		~AI_Solver();
};

#endif
