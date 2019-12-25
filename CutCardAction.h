#pragma once

#include "Action.h"
class CutCardAction : public Action
{
	CellPosition* pos;
public:
	
	CutCardAction(ApplicationManager *pApp);
	
	virtual void ReadActionParameters(); 	
	
	virtual void Execute();
	
	~CutCardAction();
};

