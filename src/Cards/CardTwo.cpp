#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (2 here)
}
CardTwo::CardTwo()
{
	cardNumber =2;
}
CardTwo::~CardTwo(void)
{
}
void CardTwo::ReadCardParameters(Grid * pGrid)
{
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output * pOut = (pGrid)->GetOutput();
	Input * pIn = (pGrid)->GetInput();

	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardTwo: Enter its wallet amount ..."
	pOut->PrintMessage("New CardTwo: Enter its wallet amount ...");
	do
	{
		walletAmount= pIn->GetInteger(pOut);
		if(walletAmount<=0)
		{
			pOut->PrintMessage("Please enter a positive number");
		}
	}while(walletAmount<=0);
	
	
	// 3- Clear the status bar
	pOut->ClearStatusBar() ;
}
void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{	
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	 Card::Apply(pGrid,pPlayer) ;
	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne
	 pPlayer->SetWallet( pPlayer->GetWallet()+walletAmount);
}

void CardTwo::Save(ofstream& OutFile) {
	Card::Save(OutFile);
	OutFile << " " << walletAmount << '\n';
}
void CardTwo::Load(ifstream& Infile, Grid* pGrid) {
	Card::Load(Infile, pGrid);
	Infile >> walletAmount;

	pGrid->AddObjectToCell(this);
}
