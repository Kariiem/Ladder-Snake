#include "CardFour.h"


CardFour::CardFour(const CellPosition &pos):Card(pos)
{
	//pCellPosition =&pos;
	cardNumber=4;
}
CardFour::CardFour()
{
	cardNumber=4;
}
void CardFour::Apply(Grid* pGrid,Player *pPlayer)
{
	Card::Apply(pGrid , pPlayer);
	Snake* nextsnake = pGrid->GetNextSnake( pPlayer->GetCell()->GetCellPosition());

	if(!nextsnake)
	{
		pGrid->GetOutput()->PrintMessage("NO SNAKE AHEAD!!!!");
		return;
	}

	CellPosition nextsnakepos = nextsnake->GetPosition();

	pGrid->UpdatePlayerCell(pPlayer, nextsnakepos);
	nextsnake->Apply(pGrid, pPlayer);
	//pGrid->GetCurrentPlayer()->SetTurnCount(pGrid->GetCurrentPlayer()->GetTurnCount()-1);
	//pGrid->GetCurrentPlayer()->Move(pGrid,0);
}

void CardFour::ReadCardParameters(Grid *pGrid)
{

}

void CardFour::Save(ofstream& OutFile) {
	Card::Save(OutFile);
	OutFile << '\n';
}

void CardFour::Load(ifstream& Infile, Grid* pGrid) {
	Card::Load(Infile, pGrid);

	pGrid->AddObjectToCell(this);
}

CardFour::~CardFour(void)
{
}
