#include "ApplicationManager.h"

#include "Grid.h"

#include "AddLadderAction.h"
#include "AddSnakeAction.h"
#include "AddCardAction.h"

#include "RollDiceAction.h"
#include "InputDiceValue.h"
#include "NewGame.h"
#include "_Delete_.h"

#include "EditCardAction.h"
#include "DesignModeAction.h"
#include "PlayModeAction.h"

#include "CopyCardAction.h"
#include "CutCardAction.h"
#include "PasteCardAction.h"

#include "SaveGridAction.h"
#include "LoadGridAction.h"

///TODO: Add #include for all action types   //Kareem included  <<<AddSnakeAction>>>

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid * ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case ADD_LADDER:
		pAct = new AddLadderAction(this);
		break;

	case ADD_SNAKE:
		pAct = new AddSnakeAction(this);
		break;

	case ADD_CARD:
		// create an object of AddCardAction here
		pAct = new AddCardAction(this);
		break;

	case COPY:
		pAct = new CopyCardAction(this);
		break;

	case CUT:
		pAct=new CutCardAction(this);
		break;

	case PASTE:
		pAct=new PasteCardAction(this);
		break;

	case EDIT_CARD:
		pAct = new EditCardAction(this);
		break;

	case EXIT:
		break;

	case Delete:
		pAct = new _Delete_(this);
		break;

	case TO_PLAY_MODE:
		pAct = new PlayModeAction(this);// temporary till you made its action class (CHANGE THIS LATTER)
		break;
		
	case ROLL_DICE:
		// create an object of RollDiceAction here
		pAct = new RollDiceAction(this);
	
		break;

	case Input_Dice_Value://Kareem <<<___>>>
		pAct = new InputDiceValue(this);
		break;

	case TO_DESIGN_MODE:
		pAct=new DesignModeAction(this);
		//->CreateDesignModeToolBar(); // temporary till you made its action class (CHANGE THIS LATTER)
		break;

	case New_Game://Kareem <<<___>>>
		pAct=new NewGame(this);
		break;

	case Save_Grid:
		pAct = new SaveGridAction(this);
		break;

	case Load_Grid:
		pAct = new LoadGridAction(this);
		break;

		///TODO: Add a case for EACH Action type in the Design mode or Play mode



	case STATUS:	// a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}
