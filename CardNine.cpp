#include "CardNine.h"

CardNine::CardNine (const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 9; // set the inherited cardNumber data member with the card number (9 here)
}
CardNine::CardNine()
{
	cardNumber =9;
}
CardNine ::~CardNine (void)
{

}

void CardNine::ReadCardParameters(Grid * pGrid)
{
	Output * pOut = (pGrid)->GetOutput();
	Input * pIn = (pGrid)->GetInput();

	pOut->PrintMessage("New CardNine: Enter its specific cell ...");
	specific_cell= pIn->GetInteger(pOut);


	pOut->ClearStatusBar() ;
}
void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer) ;
	int currcell=( pPlayer->GetCell())->GetCellPosition().GetCellNum();
	CellPosition pos=specific_cell;
	pGrid->UpdatePlayerCell(pPlayer,pos);
	if(pGrid->GetCurrentPlayer()->GetCell()->GetGameObject()) pGrid->GetCurrentPlayer()->GetCell()->GetGameObject()->Apply(pGrid,pPlayer);
	//pGrid->GetCurrentPlayer()->SetTurnCount(pGrid->GetCurrentPlayer()->GetTurnCount()-1);
	//pGrid->GetCurrentPlayer()->Move(pGrid,0);

}

void CardNine::Save(ofstream& OutFile) {
	Card::Save(OutFile);
	OutFile << " " << specific_cell << '\n';
}
void CardNine::Load(ifstream& Infile, Grid* pGrid) {
	Card::Load(Infile, pGrid);
	Infile >> specific_cell ;

	pGrid->AddObjectToCell(this);
}
