#include "CardEight.h"

CardEight ::CardEight (const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 8; // set the inherited cardNumber data member with the card number (8 here)
}
CardEight::CardEight() {
	cardNumber = 8;
}
CardEight ::~CardEight (void)
{
}

void CardEight::ReadCardParameters(Grid*pGrid)
{
}
void CardEight ::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer) ;
	pPlayer->set_freezing_state(1);
}



void CardEight::Save(ofstream& OutFile) {
	Card::Save(OutFile);
	OutFile << '\n';
}

void CardEight::Load(ifstream& Infile, Grid* pGrid) {
	Card::Load(Infile, pGrid);

	pGrid->AddObjectToCell(this);
}