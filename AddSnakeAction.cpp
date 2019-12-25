#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"

AddSnakeAction::AddSnakeAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction()
{
}

void AddSnakeAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();



	///TODO: Make the needed validations on the read parameters
	if( !startPos.IsValidCell() || !endPos.IsValidCell() )
	{
		startPos.SetHCell(-1);
		startPos.SetVCell(-1);
		pGrid->PrintErrorMessage("start cell and/or end cell are/is invalid positions, Click to continue ...");
		return;
	}
	if(startPos.HCell() != endPos.HCell() )
	{
		startPos.SetHCell(-1);
		startPos.SetVCell(-1);
		pGrid->PrintErrorMessage("start cell and end cell are not in the same column, Click to continue ...");
		return;
	}
	if( startPos.VCell()>=endPos.VCell())
	{
		startPos.SetHCell(-1);
		startPos.SetVCell(-1);
		pGrid->PrintErrorMessage("start cell cannot be smaller than end cell,Click to continue ...");
		return;
	}
	if (endPos.HCell()==0 && endPos.VCell()==8)
	{
		startPos.SetHCell(-1);
		startPos.SetVCell(-1);
		pGrid->PrintErrorMessage("end cell cannot be the first cell, Click to continue ...");
		return;
	}
	if(startPos.HCell()==10 && startPos.VCell()== 0 )
	{
		startPos.SetHCell(-1);
		startPos.SetVCell(-1);
		pGrid->PrintErrorMessage("start cell cannot be the last cell, CLick to continue ...");
		return;
	}
	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddSnakeAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Snake object with the parameters read from the user
	Snake * pSnake = new Snake (startPos,endPos);

	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Add the Snake object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pSnake);

	bool Overlap = pGrid->IsOverlapping(pSnake);
	// if the GameObject cannot be added
	if (!added)
	{
		//is this becuase it overlaps with a another snake or ladder ?
		if(Overlap)
		{
			pGrid->PrintErrorMessage("Error: Snakes cannot overlap! Click to continue ... ");
		}
		// Print an appropriate message anyway
		else if(startPos.IsValidCell() && endPos.IsValidCell())
			pGrid->PrintErrorMessage("Error:Cell can hold only one object");
	}
	// Here, the snake is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}
