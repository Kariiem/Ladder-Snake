#include "EditCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"

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


EditCardAction::EditCardAction(ApplicationManager *pApp) : Action(pApp)
{
}
void EditCardAction::ReadActionParameters()
{	

}
void EditCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	pOut->PrintMessage("Please click on the card you want to edit");
	// 2- Switch case on cardNumber data member and create the appropriate card object type
	cardPosition=(pIn->GetCellClicked());
	Card*pCard=NULL;
	if(cardPosition.IsValidCell() )
	{
		pCard=( pGrid->GetCard(cardPosition) );// will point to the card object type
	}

	CardOne *p1=dynamic_cast<CardOne*>(pCard);
	CardTwo *p2=dynamic_cast<CardTwo*>(pCard);
	CardThree *p3=dynamic_cast<CardThree*>(pCard);
	CardFour *p4=dynamic_cast<CardFour*>(pCard);
	CardFive *p5=dynamic_cast<CardFive*>(pCard);
	CardSix *p6=dynamic_cast<CardSix*>(pCard);
	CardSeven *p7=dynamic_cast<CardSeven*>(pCard);
	CardEight *p8=dynamic_cast<CardEight*>(pCard);
	CardNine *p9=dynamic_cast<CardNine*>(pCard);
	CardTen *p10=dynamic_cast<CardTen*>(pCard);
	CardEleven *p11=dynamic_cast<CardEleven*>(pCard);
	CardTwelve *p12=dynamic_cast<CardTwelve*>(pCard);
	CardThirteen *p13=dynamic_cast<CardThirteen*>(pCard);
	CardFourteen *p14=dynamic_cast<CardFourteen*>(pCard);

	if(pCard!=NULL)
	{
		cardNumber=pCard->GetCardNumber();
	}
	switch (cardNumber) // not completed
	{
	case 1:  p1->ReadCardParameters(pGrid); break;
	case 2:  p2->ReadCardParameters(pGrid); break;
	case 3:  p3->ReadCardParameters(pGrid); break;
	case 4:  p4->ReadCardParameters(pGrid); break;
	case 5:  p5->ReadCardParameters(pGrid); break;	 
	case 6:  p6->ReadCardParameters(pGrid); break;
	case 7:  p7->ReadCardParameters(pGrid); break;
	case 8:  p8->ReadCardParameters(pGrid); break;
	case 9:  p9->ReadCardParameters(pGrid); break;
	case 10: p10->setExists(0); p10->ReadCardParameters(pGrid);break;
	case 11: p11->setExists(0); p11->ReadCardParameters(pGrid); break;
	case 12: p12->setExists(0); p12->ReadCardParameters(pGrid); break;
	case 13: p13->setExists(0); p13->ReadCardParameters(pGrid); break;
	case 14: p14->setExists(0); p14->ReadCardParameters(pGrid); break;
	}
	pGrid->UpdateInterface();
}
EditCardAction::~EditCardAction()
{
}
