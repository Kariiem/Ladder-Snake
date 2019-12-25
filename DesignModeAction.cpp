#include "DesignModeAction.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"
#include "Player.h"

DesignModeAction::DesignModeAction(ApplicationManager *pApp) : Action(pApp)
{

}
void DesignModeAction::ReadActionParameters()
{
}

void DesignModeAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	CellPosition pos(8,0);
	Cell* cell=new Cell(pos);
	pOut->PrintMessage("Are you sure you want to return to Design mode?All your progress will be lost. Y/N");
	string choice = pIn->GetSrting(pOut);
	if(choice=="Y"||choice=="y")
	{
		for(int i=0; i<4;i++)
		{
			pGrid->GetCurrentPlayer()->ClearDrawing(pOut);
			pGrid->UpdatePlayerCell( pGrid->GetCurrentPlayer(),pos);
			pGrid->GetCurrentPlayer()->SetCell(cell);
			pGrid->GetCurrentPlayer()->SetStepCount(1);
			pGrid->GetCurrentPlayer()->SetTurnCount(0);
			pGrid->GetCurrentPlayer()->SetWallet(100); 
			pGrid->GetCurrentPlayer()->set_freezing_state(0);
			pGrid->AdvanceCurrentPlayer();
		}
		pGrid->SetEndGame(false);
		pGrid->SetPlayer(0);

		//Setting the owner of each card to NULL
		pGrid->SetCardOwners(NULL);

		pOut->CreateDesignModeToolBar();
	}
	else
		return;
}


DesignModeAction::~DesignModeAction()
{
}
