#include "_Delete_.h"
#include "Grid.h"
#include "Output.h"
#include "Input.h"

_Delete_::_Delete_(ApplicationManager *pApp):Action(pApp)
{
}
void _Delete_::ReadActionParameters()
{
	//No parameters for this function
}

void _Delete_::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Select game object to delete");
	
	CellPosition pCellpos = pIn->GetCellClicked() ;
	pGrid->RemoveObjectFromCell(pCellpos);
	pGrid->UpdateInterface();	
}


_Delete_::~_Delete_()
{
}
