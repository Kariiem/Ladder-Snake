#include "Player.h"

#include "GameObject.h"
#include "Card.h"
#include <iostream>

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	// M.W
	attacks [0]=0;
	attacks [1]=1;
	attacks [2]=1;
	attacks [3]=1;
	attacks [4]=1;
	set_freezing_state (0); 
	set_burning_level(0);
	set_poisoning_level(0);
	num_attacks_left=3;
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}
void Player::SetNumAttacks(int i )
{
	num_attacks_left=i;
}

//========================================================================//
//                  KAREEM DEFINED THESE SETTERS/GETTERS                  //
//========================================================================//
void Player::SetTurnCount(int rturncount)
{
	if(rturncount < 0)
		turnCount=0;
	turnCount=rturncount;
}
void Player::SetStepCount(int rstepcount)
{
	if(rstepcount<=0)
		stepCount=1;
	else
		stepCount=rstepcount;
}
int Player::GetStepCount() const
{
	return stepCount;
}
void Player::SetJustRolledDiceNum(int rjustRolledDiceNum )
{
	if(rjustRolledDiceNum <= 0 || rjustRolledDiceNum> 6 )
		justRolledDiceNum=0;
	else
		justRolledDiceNum=rjustRolledDiceNum;
}
int Player::GetJustRolledDiceNum() const
{
	return justRolledDiceNum;
}
//=======================================================================//
bool Player::is_freezed ()
{
	return freezed;
}
void Player::set_freezing_state (bool f)
{
	freezed = f;
}

//=======================================================================//

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];


	///TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(pCell->GetCellPosition(),playerNum,playerColor);

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;


	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(pCell->GetCellPosition(),playerNum,cellColor);
}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	turnCount++;

	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	if( (is_freezed() || (turnCount==3) || (wallet < 1)  )&& !pGrid->GetEndGame())
	{
		//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
		//bonus addition

		if (!is_freezed()&& can_attack() && turnCount==3)
		{
			string input_case;
			pGrid->PrintErrorMessage("Do you want to call a special Attack or Move A/M , click to continue...");
			input_case=(pGrid->GetInput())->GetSrting((pGrid->GetOutput()));
			if (input_case=="a"||input_case=="A")
			{
				LaunchAttack * launchAttack = new LaunchAttack (pGrid) ;
				launchAttack ->Execute();
				delete launchAttack;
			}
			//end of bonus addition
			else if(turnCount==3)
			{
				if (!(this->is_freezed())) wallet=wallet+10*diceNumber;
				turnCount=0;
			}
		}

		else if(turnCount==3) 
		{
			if (!(is_freezed()))  wallet=wallet+10*diceNumber;
			turnCount=0;
		}
		if(turnCount == 3 ) turnCount = 0;
		set_freezing_state(0);
		return;
	}

	// 3- Set the justRolledDiceNum with the passed diceNumber
	justRolledDiceNum=diceNumber;

	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"
	int pos=pCell->GetCellPosition().GetCellNumFromPosition( pCell->GetCellPosition());
	pos=pos+diceNumber;

	SetStepCount(pos);

	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
	if( (99-pos)>=0 )
	{
		pGrid->UpdatePlayerCell( this,pCell->GetCellPosition().GetCellPositionFromNum(pos));
	}

	// 6- Apply() the game object of the reached cell (if any)
	if(  dynamic_cast<GameObject*> (pCell->GetGameObject() )   )
	{
		pCell->GetGameObject()->Apply(pGrid,this);
	}
	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	if(stepCount==99)
	{
		pGrid->SetEndGame(true);
	}

}
void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}
//bonus additions
void Player::dec_num_attacks_left()
{
	if (num_attacks_left>0)  num_attacks_left--;

}
bool Player::can_attack ()
{
	return num_attacks_left > 0;
}
void Player::used_this_attack(int a)
{
	attacks[a]=0;
}
bool Player::can_use_this_attack(int a)
{
	return attacks[a];
}
				//
int Player::get_player_num ()
{
	return playerNum;
}
bool Player::is_posoned()
{
	return poisoned;
}
void Player::set_poisoning_level (int p)
{
	if (p>=0&&p<=5) {poison_level=p; poisoned=1;}
	if (p==0) poisoned = 0;
}
int Player::get_poisoning_level()
{
	return poison_level;
}
bool Player::is_burning ()
{
	return burning;
}
void Player::set_burning_level (int b)
{
	if (b>=0&&b<=3) 
	{
		burning_level=b; burning=1;
	}
	if (b==0) burning = 0;
}
int Player::get_burning_level()
{
	return burning_level;
}
