#include "CutCardAction.h"

#include "Grid.h"
#include "Input.h"
#include "Output.h"

#include "Card.h"
#include "CardOne.h"
#include "CardTwo.h"
#include"CardThree.h"
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



CutCardAction::CutCardAction(ApplicationManager *pApp) : Action(pApp)
{
}
void CutCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("click on the source cell...");
	pos = new CellPosition(pIn->GetCellClicked());
}
void CutCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	Card* pCard=NULL;
	if( pos->IsValidCell() )
	{
		pCard=( pGrid->GetCard(*pos) );// will point to the card object type
	}
	else
		return;
	if( pGrid->GetCard(*pos) )
	{
		Card* P=new Card();
		int cardnumber=pCard->GetCardNumber();
		switch(cardnumber)
		{
		case 1: {
			CardOne* pCard1 = new CardOne();
			*pCard1=*dynamic_cast<CardOne*>(pCard);
			P=pCard1;
			break;
		}
		case 2: {
			CardTwo* pCard2 = new CardTwo();
			*pCard2=*dynamic_cast<CardTwo*>(pCard);
			P=pCard2;
			break;
		}
		case 3: {
			CardThree* pCard3 = new CardThree();
			*pCard3=*dynamic_cast<CardThree*>(pCard);
			P=pCard3;
			break;
		}
		case 4: {
			CardFour* pCard4 = new CardFour();
			*pCard4=*dynamic_cast<CardFour*>(pCard);
			P=pCard4; 
			break;
		}
		case 5: {
			CardFive* pCard5 = new CardFive();
			*pCard5=*dynamic_cast<CardFive*>(pCard);
			P=pCard5;
			break;
		}	 
		case 6: {
			CardSix* pCard6 = new CardSix();
			*pCard6=*dynamic_cast<CardSix*>(pCard );
			P=pCard6;
			break;
		}
		case 7: {
			CardSeven* pCard7 = new CardSeven();
			*pCard7=*dynamic_cast<CardSeven*>(pCard);
			P=pCard7;
			break;
		}
		case 8: {
			CardEight* pCard8 = new CardEight();
			*pCard8=*dynamic_cast<CardEight*>(pCard);
			P=pCard8;
			break;
		}
		case 9: {
			CardNine* pCard9 = new CardNine();
			*pCard9=*dynamic_cast<CardNine*>(pCard);
			P=pCard9;
			break;
		}
		case 10:{
			CardTen* pCard10 = new CardTen();
			*pCard10=*dynamic_cast<CardTen*>(pCard);
			P=pCard10;
			break;
		}
		case 11:{
			CardEleven* pCard11 = new CardEleven();
			*pCard11=*dynamic_cast<CardEleven*>(pCard);
			P=pCard11;
			break;
		}
		case 12:{
			CardTwelve* pCard12 = new CardTwelve();
			*pCard12=*dynamic_cast<CardTwelve*>(pCard);
			P=pCard12;
			break;
		}
		case 13:{
			CardThirteen* pCard13 = new CardThirteen();
			*pCard13=*dynamic_cast<CardThirteen*>(pCard);
			P=pCard13;
			break;
		}
		case 14:{
			CardFourteen* pCard14 = new CardFourteen();
			*pCard14=*dynamic_cast<CardFourteen*>(pCard);
			P=pCard14; 
			break;
		}
		}

		pGrid->SetClipboard(P);
		pGrid->RemoveObjectFromCell(*pos);
		pOut->ClearStatusBar();
	}

	else
	{
		pGrid->SetClipboard(NULL);
		pOut->ClearStatusBar();
		return;
	}


}
CutCardAction::~CutCardAction()
{
}
