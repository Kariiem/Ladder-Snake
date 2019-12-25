#include "LoadGridAction.h"
#include "Grid.h"
#include <fstream>

LoadGridAction::LoadGridAction(ApplicationManager* App) : Action(App)
{
}
void LoadGridAction::ReadActionParameters()
{
	pManager->GetGrid()->PrintErrorMessage("Loading a grid now , left-click and enter the name of the grid..(eg: grid_name)") ;
	source  =  pManager->GetGrid()->GetInput()->GetSrting(pManager->GetGrid()->GetOutput());
	source=source + ".txt";
}


void LoadGridAction::Execute()
{
	ReadActionParameters() ;
	Grid* pGrid = pManager->GetGrid();
	ifstream infile(source) ;
	bool was_successful = infile.is_open() ;

	if(!was_successful)
	{
		pGrid->PrintErrorMessage("Sorry! , Can't find or open the file you specified..click to continue") ;
		return ;
	}

	pGrid->ClearGrid();
	pGrid->LoadAll(infile,LADDER) ;
	pGrid->LoadAll(infile,SNAKE) ;
	pGrid->LoadAll(infile,CARD) ;

	infile.close() ;

	pGrid->UpdateInterface();
	pGrid->PrintErrorMessage("Grid Loaded Successfully !! click to continue..") ;
}

LoadGridAction::~LoadGridAction()
{
}
