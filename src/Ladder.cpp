#include "Ladder.h"
#include "Snake.h"
#include "Player.h"
Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	if(endCellPos.VCell() < startCellPos.VCell())
	{
		this->endCellPos = endCellPos;
	}
	///TODO: Do the needed validation
}

Ladder::Ladder()
{
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a ladder.Click to continue...");
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer,endCellPos);
	//pGrid->GetCurrentPlayer()->SetTurnCount(pGrid->GetCurrentPlayer()->GetTurnCount()-1);
	//pGrid->GetCurrentPlayer()->Move(pGrid,0);
	if(pGrid->GetCurrentPlayer()->GetCell()->GetGameObject()) pGrid->GetCurrentPlayer()->GetCell()->GetGameObject()->Apply(pGrid,pPlayer);

}
bool Ladder::IsOverlapping(GameObject*newObj) const
{ 
	Ladder*Lad1=new Ladder(-1,-1);
	Lad1= dynamic_cast<Ladder*>(newObj) ;
	if( Lad1 !=NULL )
	{
		if(    this->GetPosition().HCell() == Lad1->GetPosition().HCell() &&
			this->GetPosition().GetCellNum() <= Lad1->GetEndPosition().GetCellNum()  &&
			this->GetEndPosition().GetCellNum() >= Lad1->GetPosition().GetCellNum() )
		{
			return true;
		}
	}
	Snake* snake1=new Snake(-1,-1);
	snake1= dynamic_cast<Snake*>(newObj) ;
	if( snake1 != NULL )
	{
		if(    this->GetPosition().HCell() == snake1->GetPosition().HCell() &&
			this->GetPosition().GetCellNum() < snake1->GetPosition().GetCellNum()  &&
			this->GetEndPosition().GetCellNum() >= snake1->GetEndPosition().GetCellNum() )
		{
			return true;
		}
	}
	return false;
}

void Ladder::Save(ofstream& file) {
	file<<this->position.GetCellNum()<<"  "<<this->endCellPos.GetCellNum()<<'\n' ;
}
void Ladder::Load(ifstream& file , Grid* pGrid){
	int startCellNum, endCellNum ;
	file >> startCellNum >> endCellNum;
	endCellPos = CellPosition::GetCellPositionFromNum(endCellNum);
	position = CellPosition::GetCellPositionFromNum(startCellNum);

	pGrid->RemoveObjectFromCell(position);
	pGrid->AddObjectToCell(this);
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

Ladder::~Ladder()
{
}
