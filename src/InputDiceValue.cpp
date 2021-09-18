#include "InputDiceValue.h"

#include "Grid.h"
#include "Player.h"


InputDiceValue::InputDiceValue(ApplicationManager *pApp): Action(pApp)
{

}

void InputDiceValue::ReadActionParameters() 
{

}

void InputDiceValue::Execute()
{

	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("please enter a number between 1-6 : ");
	int diceNumber=pIn->GetInteger(pOut);

	if(diceNumber<=0 || diceNumber>6)
	{	
		pOut->ClearStatusBar();
		pGrid->PrintErrorMessage("Invalid number.click to continue...");
		pOut->ClearStatusBar();
		return ;
	}
	///TODO: Make the needed validations on the read parameters
	pGrid->GetCurrentPlayer();

	
	
	if (pGrid->GetCurrentPlayer()->is_burning())
	{
	pGrid->GetCurrentPlayer()->SetWallet( pGrid->GetCurrentPlayer()->GetWallet()-20);
	pGrid->GetCurrentPlayer()->set_burning_level (pGrid->GetCurrentPlayer()->get_burning_level()-1); 
	// we should test if the player donot have enough money he should stay in his place
	}
	if (pGrid->GetCurrentPlayer()->is_freezed()) 
	{
	pGrid->GetCurrentPlayer()->Move(pGrid,0);
	pGrid->GetOutput()->CreatePlayModeToolBar();
	}
	else if (pGrid->GetCurrentPlayer()->is_posoned())
	{
	pGrid->GetCurrentPlayer()->set_poisoning_level (pGrid->GetCurrentPlayer()->get_poisoning_level()-1); 
	pGrid->GetCurrentPlayer()->Move(pGrid,diceNumber-1);
	pGrid->GetOutput()->CreatePlayModeToolBar();

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
	pGrid->GetOutput()->CreatePlayModeToolBar();
	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
}
InputDiceValue::~InputDiceValue(void)
{
}
