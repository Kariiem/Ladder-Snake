#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();



	//TODO: Make the needed validations on the read parameters
	if( !startPos.IsValidCell() || !endPos.IsValidCell() )
	{
		startPos.SetHCell(-1);
		startPos.SetVCell(-1);
		pGrid->PrintErrorMessage("end cell and/or start cell are/is invalid positions, Click to continue ...");
		return;
	}
	if(startPos.HCell() != endPos.HCell() )
	{
		startPos.SetHCell(-1);
		startPos.SetVCell(-1);
		pGrid->PrintErrorMessage("end cell and start cell are not in the same column, Click to continue ...");
		return;
	}
	if(	startPos.VCell()<=endPos.VCell())
	{
		startPos.SetHCell(-1);
		startPos.SetVCell(-1);
		pGrid->PrintErrorMessage("end cell cannot be smaller than start cell,Click to continue ...");
		return;
	}
	if(startPos.HCell()==0 && startPos.VCell()== 8 )
	{
		startPos.SetHCell(-1);
		startPos.SetVCell(-1);
		pGrid->PrintErrorMessage("start cell cannot be the first cell, Click to continue ...");
		return;
	}
	if(endPos.HCell()==10 && endPos.VCell()== 0 ) 
	{
		startPos.SetHCell(-1);
		startPos.SetVCell(-1);
		pGrid->PrintErrorMessage("end cell cannot be the last cell, CLick to continue ...");
		return;
	}

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Ladder object with the parameters read from the user
	Ladder * pLadder = new Ladder(startPos, endPos);

	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pLadder);

	// if the GameObject cannot be added
	bool Overlap= pGrid->IsOverlapping(pLadder);
	if (! added )
	{
		if(Overlap)
		{
			pGrid->PrintErrorMessage("Error: Ladders cannot overlap! Click to continue ... ");
		}
		// Print an appropriate message
		else if(startPos.IsValidCell() && endPos.IsValidCell())
			pGrid->PrintErrorMessage("Error:Cell can hold only one object");


	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction
}
