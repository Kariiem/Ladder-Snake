#include "CardFive.h"

CardFive::CardFive(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (5 here)
}
CardFive::CardFive()
{
	cardNumber =5;
}
CardFive::~CardFive(void)
{
}
void CardFive::ReadCardParameters(Grid*pGrid)
{

}
void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer) ; // calling the apply function of the base class
	last_roll= pPlayer->GetJustRolledDiceNum ();//get the last dice roll value
	CellPosition pos(( pPlayer->GetCell())->GetCellPosition().GetCellNum() + last_roll);//create a cellposition with the new one
	pGrid->UpdatePlayerCell(pPlayer,pos);// updating the current player's position

	if ((pGrid->GetCurrentPlayer()->GetCell()->GetGameObject())) pGrid->GetCurrentPlayer()->GetCell()->GetGameObject()->Apply(pGrid,pPlayer);
	// if the new cell has an object apply it
	// note :
	// we didn't use the move function as it move the player and incremrnt its turn count 

}

void CardFive::Save(ofstream& OutFile) {
	Card::Save(OutFile);
	OutFile << '\n';
}

void CardFive::Load(ifstream& Infile, Grid* pGrid) {
	Card::Load(Infile, pGrid);

	pGrid->AddObjectToCell(this);
}