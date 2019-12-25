#include "AddCardAction.h"
#include "Input.h"
#include "Output.h"

#include "Card.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"


AddCardAction::AddCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters() //M.W
{	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Read the "cardNumber" parameter and set its data member
	pOut->PrintMessage("please enter the card number");
	int cardNumberin= pIn->GetInteger(pOut);
	if (cardNumberin>0 && cardNumberin<15) 
	{
		cardNumber=cardNumberin;
	}
	else
	{
		cardNumber=-1;
		pOut->PrintMessage("Card does not exist.");
		return;
	}

	// 3- Read the "cardPosition" parameter (its cell position) and set its data member
	pOut->PrintMessage("please choose the cell");

	cardPosition=pIn->GetCellClicked();
	if(cardPosition.HCell()==10 && cardPosition.VCell()== 0 )
	{
		cardPosition.SetHCell(-1);
		cardPosition.SetVCell(-1);
		pGrid->PrintErrorMessage("The Last cell cannot hold a Card, CLick to continue ...");
		return;
	}
	if(cardPosition.HCell()==0 && cardPosition.VCell()== 8 )
	{
		cardPosition.SetHCell(-1);
		cardPosition.SetVCell(-1);
		pGrid->PrintErrorMessage("The Start cell cannot hold a Card, CLick to continue ...");
		return;
	}
	// 4- Make the needed validations on the read parameters
	// done ;
	// 5- Clear status bar
	pOut->ClearStatusBar() ;
}

void AddCardAction::Execute() //M.W
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();

	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card * pCard = NULL;                              // will point to the card object type

	static bool exist=1;
	switch (cardNumber)
	{
		// A- Add the remaining cases
	case 1: pCard = new CardOne(cardPosition); break;
	case 2: pCard = new CardTwo(cardPosition); break;
	case 3: pCard = new CardThree(cardPosition); break;
	case 4: pCard = new CardFour(cardPosition); break;
	case 5: pCard = new CardFive(cardPosition); break;	 
	case 6: pCard = new CardSix(cardPosition); break;
	case 7: pCard = new CardSeven(cardPosition); break;
	case 8: pCard = new CardEight(cardPosition); break;
	case 9: pCard = new CardNine(cardPosition); break;
		//*************************************************//
	case 10:pCard = new CardTen(cardPosition);break;
	case 11:pCard = new CardEleven(cardPosition);break;
	case 12:pCard = new CardTwelve(cardPosition);break;
	case 13:pCard = new CardThirteen(cardPosition);break;
	case 14:pCard = new CardFourteen(cardPosition);break;
	}

	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
	if (pCard)
	{
		// A- We get a pointer to the Grid from the ApplicationManager
		Grid* pGrid = pManager->GetGrid();
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();

		// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type


		// C- Add the card object to the GameObject of its Cell:
		bool obj_can_be_added = pGrid->AddObjectToCell(pCard);	

		// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction
		if (!obj_can_be_added )
		{
			// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
			if ( cardPosition.IsValidCell() )
				pGrid->PrintErrorMessage("Card cannot be added ,the cell contains another object. Press any key to continue");
			return;
		}
		pCard->ReadCardParameters( pGrid);

	}
}
