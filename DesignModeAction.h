#pragma once

#include "Action.h"
class DesignModeAction :  public Action
{
public:
	DesignModeAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute(); 

	~DesignModeAction();
};

