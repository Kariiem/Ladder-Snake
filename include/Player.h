#pragma once

#include "Grid.h"
#include "Cell.h"
#include "LaunchAttack.h"
class Player
{
	Cell * pCell;		   // pointer to the current Cell of the player

	const int playerNum;   // the player number (from 0 to MaxPlayerCount-1)
	// player number does NOT change after construction (const.)

	int stepCount;		   // step count which is the same as his cellNum: from 1 to NumVerticalCells*NumHorizontalCells
	int wallet;		       // player's wallet (how many coins he has -- integer)
	int justRolledDiceNum; // the current dice number which is just rolled by the player
	int turnCount;         // a counter that starts with 0, is incremented with each dice roll                       // and reset again when reached 3
	bool freezed;                    // it is used to indicate when to move and when to add to your wallet
	
	bool attacks [5];
	int num_attacks_left;
	bool poisoned;
	bool burning;
	int poison_level;
	int burning_level;

public:

	Player(Cell * pCell, int playerNum); // Constructor making any needed initializations
	// ====== Setters and Getters ======
	void SetNumAttacks(int );
	void SetCell(Cell * cell);		// A setter for the pCell
	Cell* GetCell() const;			// A getter for the pCell

	void SetWallet(int wallet);		// A setter for the wallet
	int GetWallet() const;			// a getter for the wallet

	int GetTurnCount() const;		// A getter for the turnCount

	///TODO: You can add setters and getters for data members here (if needed)
	int GetPlayerNum() const{
		return playerNum;
	}
	//=====================================//Kareem Commented this
	void SetTurnCount(int rturncount) ;

	int GetStepCount() const;
	void SetStepCount(int rstepcount) ;

	void SetJustRolledDiceNum(int rjustRolledDiceNum );
	int GetJustRolledDiceNum() const;
	//=====================================
	bool is_freezed ();
	void set_freezing_state (bool);
	//========================================
	void used_this_attack(int);
	bool can_use_this_attack(int);
	void dec_num_attacks_left();
	bool can_attack ();
	int get_player_num ();
	bool is_posoned();
	void set_poisoning_level (int);
	int get_poisoning_level();
	bool is_burning ();
	void set_burning_level (int);
	int get_burning_level();
	//=======================================
	// ====== Drawing Functions ======

	void Draw(Output* pOut) const;			// Draws the Player's Circle on its current cell

	void ClearDrawing(Output* pOut) const;	// Clears the Player's Circle from its current cell

	// ====== Game Functions ======

	void Move(Grid * pGrid, int diceNumber);	// Moves the Player with the passed diceNumber 
	// and Applies the Game Object's effect (if any) of the end reached cell 
	// for example, if the end cell contains a ladder, take it

	void AppendPlayerInfo(string & playersInfo) const; // Appends player's info to the input string, 
	// for example: P0(wallet, turnCount)


};
