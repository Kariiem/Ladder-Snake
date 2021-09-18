#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager *pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action


	// -- If not ended, do the following --:

	// 2- Generate a random number from 1 to 6 --> This step is done for you
	srand((int) time(NULL)); // time is for different seed each run
	int diceNumber = 1 + (rand() % 6); // from 1 to 6 --> should change seed
	string Dice = to_string(diceNumber);
	pOut->PrintMessage(Dice);


	// 3- Get the "current" player from pGrid
	pGrid->GetCurrentPlayer();
	pGrid->GetOutput()->CreatePlayModeToolBar(); 

	// 4- Move the currentPlayer using function Move of class player

	//======================================================================
	if (pGrid->GetCurrentPlayer()->is_burning())
	{
	pGrid->GetCurrentPlayer()->SetWallet( pGrid->GetCurrentPlayer()->GetWallet()-20);
	pGrid->GetCurrentPlayer()->set_burning_level (pGrid->GetCurrentPlayer()->get_burning_level()-1); 
	pOut->PrintMessage("it is firing");
	}
	if (pGrid->GetCurrentPlayer()->is_freezed()) 
	{
	pGrid->GetCurrentPlayer()->Move(pGrid,0);
	pGrid->GetOutput()->CreatePlayModeToolBar();
	pOut->PrintMessage("it is freezing");
	}
	else if (pGrid->GetCurrentPlayer()->is_posoned())
	{
	pGrid->GetCurrentPlayer()->set_poisoning_level (pGrid->GetCurrentPlayer()->get_poisoning_level()-1); 
	pGrid->GetCurrentPlayer()->Move(pGrid,diceNumber-1);
	pGrid->GetOutput()->CreatePlayModeToolBar();
	pOut->PrintMessage("it is poisoning");
	}
	else 
	{
	pGrid->GetCurrentPlayer()->Move(pGrid,diceNumber);
	pGrid->GetOutput()->CreatePlayModeToolBar();
	} 
	if( pGrid->GetEndGame()==1 )
	{
		pGrid->PrintErrorMessage("Congratulations you have reached the final cell !");
		pManager->ExecuteAction(New_Game);
		return;
	}
	// 5- Advance the current player number of pGrid
	pGrid->AdvanceCurrentPlayer();
	pOut->CreatePlayModeToolBar();
	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
}
RollDiceAction::~RollDiceAction()
{
}
