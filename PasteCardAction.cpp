#include "PasteCardAction.h"

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


PasteCardAction::PasteCardAction(ApplicationManager *pApp) : Action(pApp)
{
}
void PasteCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("click on the destination cell...");

}
void PasteCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	ReadActionParameters();
	if( pGrid->GetClipboard() )
	{
		pos =new CellPosition( pIn->GetCellClicked());
		int cardNumber=pGrid->GetClipboard()->GetCardNumber();
		pGrid->GetClipboard()->SetPosition(*pos);

		switch (cardNumber) //  completed
		{
		case 1: {CardOne* pCard1 = new CardOne();
			*pCard1=*dynamic_cast<CardOne*>(pGrid->GetClipboard());pCard=pCard1;break;}
		
		case 2: {CardTwo* pCard2 = new CardTwo();
			*pCard2=*dynamic_cast<CardTwo*>(pGrid->GetClipboard());pCard=pCard2;break;}
		
		case 3: {CardThree* pCard3 = new CardThree();
			*pCard3=*dynamic_cast<CardThree*>(pGrid->GetClipboard());pCard=pCard3; break;}
		
		case 4: {CardFour* pCard4 = new CardFour();
			*pCard4=*dynamic_cast<CardFour*>(pGrid->GetClipboard());pCard=pCard4; break;}
		
		case 5: {CardFive* pCard5 = new CardFive();
			*pCard5=*dynamic_cast<CardFive*>(pGrid->GetClipboard());pCard=pCard5; break;}	 
		
		case 6: {CardSix* pCard6 = new CardSix();
			*pCard6=*dynamic_cast<CardSix*>(pGrid->GetClipboard() );pCard=pCard6; break;}
		
		case 7: {CardSeven* pCard7 = new CardSeven();
			*pCard7=*dynamic_cast<CardSeven*>(pGrid->GetClipboard());pCard=pCard7; break;}
		
		case 8: {CardEight* pCard8 = new CardEight();
			*pCard8=*dynamic_cast<CardEight*>(pGrid->GetClipboard());pCard=pCard8; break;}
		
		case 9: {CardNine* pCard9 = new CardNine();
			*pCard9=*dynamic_cast<CardNine*>(pGrid->GetClipboard());pCard=pCard9; break;}
		
		case 10:{CardTen* pCard10 = new CardTen();
			*pCard10=*dynamic_cast<CardTen*>(pGrid->GetClipboard());pCard=pCard10; break;}
		
		case 11:{CardEleven* pCard11 = new CardEleven();
			*pCard11=*dynamic_cast<CardEleven*>(pGrid->GetClipboard());pCard=pCard11; break;}
		
		case 12:{CardTwelve* pCard12 = new CardTwelve();
			*pCard12=*dynamic_cast<CardTwelve*>(pGrid->GetClipboard());pCard=pCard12; break;}
		
		case 13:{CardThirteen* pCard13 = new CardThirteen();
			*pCard13=*dynamic_cast<CardThirteen*>(pGrid->GetClipboard());pCard=pCard13; break;}
		
		case 14:{CardFourteen* pCard14 = new CardFourteen();
			*pCard14=*dynamic_cast<CardFourteen*>(pGrid->GetClipboard());pCard=pCard14; break;}
		}
	}
	else
	{
		pGrid->PrintErrorMessage("Clipboard has no card to paste.");
		return;
	}
	if(pos->IsValidCell())
	{
		if(pCard)
		{
			bool obj_can_be_added = ( pGrid-> AddObjectToCell(pCard) );
			if (obj_can_be_added) 
				pCard->Draw(pOut);
			pOut->ClearStatusBar();
		}
		else
		{
			pOut->ClearStatusBar();
			return;
		}
	}
}
PasteCardAction::~PasteCardAction()
{
}
