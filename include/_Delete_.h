#pragma once
#include "Action.h"
class _Delete_ :
	public Action
{
public:
	_Delete_(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	virtual void Execute();

	~_Delete_();
};

