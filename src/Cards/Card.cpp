#include "Card.h"
#include <iostream>

Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{
}

Card::Card()
{
}
void Card::SetCardNumber(int cnum)
{
	if (cnum>0 && cnum<15) 
		cardNumber = cnum; // validation M.W
}


int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::Draw(Output* pOut) const
{

	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(GameObject::position,cardNumber);


}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click
	if (cardNumber==7) pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + " and got another free turn !!. Click to continue ...");
	if (cardNumber==8) pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + " Oops you can't move the next turn. Click to continue ...");
	if (cardNumber==5) pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + " You can move forward the same number of steps that you just rolled. Click to continue ...");
	if (cardNumber==6) pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + " Oops you will backward the same number of steps that you just rolled. Click to continue ...");
	if (cardNumber==9) pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + " Magic happens , you will be teleported now !!. Click to continue ...");
	if (cardNumber==2) pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + " MONEY MONEY MONEY !!. Click to continue ...");
	if (cardNumber==1) pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + " You will pay for your sins now !. Click to continue ...");
	
	
	else pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}


void Card::Save(ofstream& OutFile) {
	OutFile << cardNumber << " " << position.GetCellNum();
	std::cout<<"\npostion : "<<  position.GetCellNum()<<"\n"; 
}
void Card::Load(ifstream& Infile, Grid* pGrid) {
	int cellNum;
	Infile >> cellNum;
	position = CellPosition::GetCellPositionFromNum(cellNum);
}

Card::~Card()
{
}
