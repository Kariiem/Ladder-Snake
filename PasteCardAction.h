#pragma once

#include "Action.h"
class PasteCardAction : public Action
{
	CellPosition* pos;
	Card* pCard;
public:
	PasteCardAction (ApplicationManager *pApp);
	~PasteCardAction();

	virtual void ReadActionParameters(); 	

	virtual void Execute();

};

