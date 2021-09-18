#include "NewGame.h"

#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Player.h"

NewGame::NewGame(ApplicationManager *pApp):Action(pApp)
{

}
void NewGame::ReadActionParameters()
{
	//No parameters for this function
}

void NewGame::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	CellPosition pos(8,0);
	Cell* cell=new Cell(pos);
	pOut->PrintMessage("Are you sure you want to start new game? Y/N");
	string choice = pIn->GetSrting(pOut);
	if(choice=="Y" || choice=="y")
	{
		for(int i=0; i<4;i++)
		{
			pGrid->GetCurrentPlayer()->ClearDrawing(pOut);
			pGrid->UpdatePlayerCell( pGrid->GetCurrentPlayer(),pos);
			pGrid->GetCurrentPlayer()->SetCell(cell);
			pGrid->GetCurrentPlayer()->SetStepCount(1);
			pGrid->GetCurrentPlayer()->SetTurnCount(0);
			pGrid->GetCurrentPlayer()->set_freezing_state(0);
			pGrid->GetOutput()->CreatePlayModeToolBar(); 
			pGrid->GetCurrentPlayer()->SetWallet(100);
			pGrid->GetOutput()->CreatePlayModeToolBar(); 
			pGrid->AdvanceCurrentPlayer();
			
		}
		pGrid->SetEndGame(false);
		pGrid->SetPlayer(0);
		
		//Setting the owner of each card to NULL
		pGrid->SetCardOwners(NULL);
	}
	pOut->ClearStatusBar();
}

NewGame::~NewGame()
{

}
