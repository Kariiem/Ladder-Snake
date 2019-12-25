#include "CardThree.h"


CardThree::CardThree(const CellPosition &pos):Card(pos)
{
	//pCellPosition =&pos;
	cardNumber=3;
}
CardThree::CardThree()
{
	cardNumber =3;
}
void CardThree::ReadCardParameters(Grid* pGrid)
{
}
void CardThree::Apply(Grid* pGrid,Player *pPlayer)
{
	Card::Apply(pGrid , pPlayer);
	Ladder* nextladder = pGrid->GetNextLadder( pPlayer->GetCell()->GetCellPosition());

	if(!nextladder)
	{
		pGrid->GetOutput()->PrintMessage("NO LADDER AHEAD!!!!");
		return;
	}

	CellPosition nextladderpos = nextladder->GetPosition();

	pGrid->UpdatePlayerCell(pPlayer, nextladderpos);
	nextladder->Apply(pGrid, pPlayer);
	//pGrid->GetCurrentPlayer()->SetTurnCount(pGrid->GetCurrentPlayer()->GetTurnCount()-1);
	//pGrid->GetCurrentPlayer()->Move(pGrid,0);
}

void CardThree::Save(ofstream& OutFile) {
	Card::Save(OutFile);
	OutFile << '\n';
}

void CardThree::Load(ifstream& Infile, Grid* pGrid) {
	Card::Load(Infile, pGrid);

	pGrid->AddObjectToCell(this);
}

CardThree::~CardThree(void)
{
}
