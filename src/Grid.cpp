#include "Grid.h"

#include "Cell.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Snake.h" //Kareem included <<<Snake>>>

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


#include "Player.h"
#include <fstream>
#include <iostream>
using namespace std ;

Grid::Grid(Input * pIn, Output * pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells-1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;
}
//===================================================================================
//===================================================================================
bool Grid::IsOverlapping(GameObject* newObj) const
{
	for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // left to right
		{
			Ladder*L=dynamic_cast<Ladder*>(CellList[i][j]->GetGameObject());
			Snake*S=dynamic_cast<Snake*>(CellList[i][j]->GetGameObject());
			if(  (L && L->IsOverlapping(newObj) ) || (S && S->IsOverlapping(newObj) ) )
				return true;
		}
	}
	return false;
}
//======================================================================================
// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject * pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	bool Overlap = this->IsOverlapping(pNewObject);
	CellPosition pos = pNewObject->GetPosition();
	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject * pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if( pPrevObject || Overlap ){
			//NOT ==  NULL  // the cell already contains a game object
			return false; // do NOT add and return false
		}
		// Set the game object of the Cell with the new game object
		//cout<<"\nAdding an object now \n";
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}

void Grid::RemoveObjectFromCell(const CellPosition & pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		// Note: you can deallocate the object here before setting the pointer to null if it is needed

		delete CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
	}
}

void Grid::UpdatePlayerCell(Player * player, const CellPosition & newPosition)
{
	// Clear the player's circle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell * newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);	

	// Draw the player's circle on the new cell position
	player->Draw(pOut);
}


void Grid::SetPlayer(int i)
{
	currPlayerNumber=i;
}
// ========= Setters and Getters Functions =========


Input * Grid::GetInput() const
{
	return pIn;
}

Output * Grid::GetOutput() const
{
	return pOut;
}
void Grid::SetBonus(int b)
{
	for (int i=0;i<4;i++)
	{
		PlayerList[i]->SetNumAttacks(b);
	}
}
void Grid::SetClipboard(Card * pCard) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Clipboard = pCard;
}

Card * Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}
void Grid:: SetCardOwners(Player*pPlayer)
{
	CardTen::      SetOwner(pPlayer);
	CardEleven::   SetOwner(pPlayer);
	CardTwelve::   SetOwner(pPlayer);
	CardThirteen:: SetOwner(pPlayer);
	CardFourteen:: SetOwner(pPlayer);
}
void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

// ========= Other Getters =========


Player * Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Ladder * Grid::GetNextLadder(const CellPosition & position)
{

	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{

			
			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			if(CellList[i][j]->HasLadder())
				return (CellList[i][j]->HasLadder());

		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}
Snake * Grid::GetNextSnake(const CellPosition & position)
{

	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{


			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			if(CellList[i][j]->HasSnake())
				return (CellList[i][j]->HasSnake());

		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}
Card * Grid::GetCard(const CellPosition & position)
{
	return  (CellList[position.VCell()][position.HCell()] )->HasCard();
}


void Grid::SaveAll(ofstream& saveFile , ObjectType Obj ){
	switch(Obj){
	case LADDER :
		{
			int num_ladders = 0 ;
			for(int i = 0 ; i<NumHorizontalCells ; ++i){
				for(int j = 0 ; j<NumVerticalCells ; ++j){
					if(CellList[j][i]->HasLadder()) {
						++num_ladders; 
					}
				}
			}
			saveFile<<num_ladders<<'\n' ;
			for(int i = 0 ; i<NumHorizontalCells ; ++i){
				for(int j = 0 ; j<NumVerticalCells ; ++j){
					if(CellList[j][i]->HasLadder()) {
						CellList[j][i]->HasLadder()->Save(saveFile) ;
					}
				}
			}
		}
		break ;

	case SNAKE :
		{
			int num_snakes = 0 ;
			for(int i = 0 ; i<NumHorizontalCells ; ++i){
				for(int j = 0 ; j<NumVerticalCells ; ++j){
					if(CellList[j][i]->HasSnake()) {
						++num_snakes; 
					}
				}
			}
			saveFile<<num_snakes<<'\n' ;
			for(int i = 0 ; i<NumHorizontalCells ; ++i){
				for(int j = 0 ; j<NumVerticalCells ; ++j){
					if(CellList[j][i]->HasSnake()) {
						CellList[j][i]->HasSnake()->Save(saveFile) ;
					}
				}
			}
		}
		break ;

	case CARD :
		{
			int num_cards = 0 ;
			for(int i = 0 ; i<NumHorizontalCells ; ++i){
				for(int j = 0 ; j<NumVerticalCells ; ++j){
					if(CellList[j][i]->HasCard()) {
						++num_cards; 
					}
				}
			}
			saveFile<<num_cards<<'\n' ;
			for(int i = 0 ; i<NumHorizontalCells ; ++i){
				for(int j = 0 ; j<NumVerticalCells ; ++j){
					if(CellList[j][i]->HasCard()) {
						CellList[j][i]->HasCard()->Save(saveFile) ;
					}
				}
			}
			CardTen::SetSaveFlagToFalse();
			CardEleven::SetSaveFlagToFalse();
			CardTwelve::SetSaveFlagToFalse();
			CardThirteen::SetSaveFlagToFalse();
			CardFourteen::SetSaveFlagToFalse();
		}
		break ;
	}
}
void Grid::LoadAll(ifstream& loadFile , ObjectType Obj ){
	switch (Obj) {
	case LADDER:
		{	
			int num_ladders = 0;
			loadFile >> num_ladders;
			for (int i = 0; i < num_ladders; ++i) {
				Ladder* NewLadder = new Ladder();
				NewLadder->Load(loadFile , this);
			}
		}
		break;

	case SNAKE:
		{
			int num_snakes = 0;
			loadFile >> num_snakes;
			for (int i = 0; i < num_snakes; ++i) {
				Snake* NewSnake = new Snake();
				NewSnake->Load(loadFile, this);
			}
			
		}
		break;


	case CARD:
		{	
			int num_cards = 0;
			loadFile >> num_cards ;
			//cout<<"\n i found "<<num_cards<<"Cards \n";
			for (int i = 0; i < num_cards; ++i) {
				int card_type;
			//	cout<<"\n this is a card of type";
				loadFile >> card_type;
			//	cout<<card_type<<"\n";
				Card* NewCard = createSpecificCard(card_type) ;
				if(NewCard) {
					//cout<<"\n i am going to load now \n";
					NewCard->Load(loadFile, this);
				}
			//	cout<<"\n\n\n\n";
			}

		}
		break;


	}
}


// ========= User Interface Functions =========


void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without cards 
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrCard(pOut);
			}
		}

		// 2- Draw other cell objects (ladders, snakes)
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawLadderOrSnake(pOut);
			}
		}

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount-1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cards/snakes/ladders do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

void Grid::ClearGrid(){	//Deleting All GameObjects From the Grid 
	for(int i = 0 ; i<NumHorizontalCells ; ++i){
		for(int j = 0 ; j<NumVerticalCells ; ++j){
			RemoveObjectFromCell(CellList[j][i]->GetCellPosition()) ;
		}
	}
}
Card* Grid::createSpecificCard(int x) 
{

	switch (x) 
	{
	case 1:  return new CardOne();
	case 2:  return new CardTwo();
	case 3:  return new CardThree();
	case 4:  return new CardFour();
	case 5:  return new CardFive();
	case 6:  return new CardSix();
	case 7:  return new CardSeven();
	case 8:  return new CardEight() ;
	case 9:  return new CardNine();
	case 10: return new CardTen();
	case 11: return new CardEleven();
	case 12: return new CardTwelve();
	case 13: return new CardThirteen();
	case 14: return new CardFourteen();  

	default: 
		return NULL;
	}
}

Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) 
	{
		for (int j = 0; j < NumHorizontalCells; j++) 
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		delete PlayerList[i];
	}
}