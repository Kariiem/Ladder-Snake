#include "CardTen.h"

int CardTen::card_price=0;
int CardTen:: fees=0;
int CardTen:: exists=0;
Player* CardTen:: owner=NULL;

bool CardTen::has_been_saved_with_parameters = false;
bool CardTen::has_been_loaded_with_parameters = false;

CardTen::CardTen(const CellPosition &pos):Card(pos)
{
	cardNumber=10;
}
CardTen::CardTen()
{
	cardNumber=10;

}
void CardTen::ReadCardParameters(Grid *pGrid)
{

	if(exists==0)
	{
		Output * pOut = (pGrid)->GetOutput();
		Input * pIn = (pGrid)->GetInput();
		pOut->PrintMessage("CardTen: Enter Card_price  ...");
		do
		{
			card_price= pIn->GetInteger(pOut);
			if(card_price<=0)
			{
				pOut->PrintMessage("Please enter a positive number");
			}
		}while(card_price<=0);
		
		pOut->PrintMessage("CardTen: Enter Fees  ...");
		do
		{
		fees= pIn->GetInteger(pOut);
		if(fees<=0)
		{
			pOut->PrintMessage("Please enter a positive number");
		}
		}while(fees<=0);
		
		exists=1;
	}

}

void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{

	/*Three cases:
	Case 1 pointer =null then we have to ask the user if he wants to buy
	Case 2 pointer==*player then nothing happens
	Case 3 pointer!=null and pointer!=player then we decrease his wallet
	*/

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid,pPlayer) ;
	Input * pIn = (pGrid)->GetInput();
	Output * pOut = (pGrid)->GetOutput();

	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne
	if(owner==NULL) //no one owns the card
	{
		pOut->PrintMessage("Do you want to buy this Card? Y/N");
		string reply= pIn->GetSrting(pOut);
		if(reply=="Y" && pPlayer->GetWallet() >= card_price)
		{
			pOut->PrintMessage("Congratulations, you've bought the card");
			owner=pPlayer;
			owner->SetWallet( pPlayer->GetWallet() - card_price);
		}
		else if(reply=="Y" &&pPlayer->GetWallet()<card_price)
		{
			pOut->PrintMessage("You don't have enough money!");
		}
		else if(reply=="N" || reply!="Y")
		{
			pOut->PrintMessage("You didn't buy the card.");
		}
	}
	else if(owner==pPlayer)
	{
	} //if theis player owns the card nothing happens

	else if(owner!=pPlayer) //if some player owns this card and this player doesn't he pay the fees
	{
		pPlayer->SetWallet( pPlayer->GetWallet()-fees);
		owner->SetWallet(owner->GetWallet()+fees);
	}

}

void CardTen::setExists(int ex)
{
	exists=ex;
}

int CardTen::getExists()
{
	return exists;
}
void CardTen::SetOwner(Player* pPlayer)
{
	owner=pPlayer;
}
Player* CardTen::GetOwner()
{
	return owner;
}
	
void CardTen::Save(ofstream &OutFile) {
	Card::Save(OutFile);

	if(!has_been_saved_with_parameters){
	OutFile << " " << card_price <<" "<< fees << '\n';
	has_been_saved_with_parameters = true ;
	}
	else OutFile<<"\n";
}
void CardTen::Load(ifstream &Infile,Grid* pGrid){
	Card::Load(Infile, pGrid);

	if(!has_been_loaded_with_parameters){
	Infile >> card_price >> fees    ;
	has_been_loaded_with_parameters = true ;
	}

	pGrid->AddObjectToCell(this);
}

void CardTen::SetSaveFlagToFalse() {
	has_been_saved_with_parameters = false ;
}


CardTen::~CardTen(void)
{
}





