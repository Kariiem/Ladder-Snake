#pragma once
//#include "Action.h"
#include "Player.h"
#include "Grid.h"

class Player;
class Attack;
class Grid;
class CellPosition;
//class 
class LaunchAttack //: public Action
{
	// [Action Parameters]
	int AttackNumber;            // 1- the card number
	Player *pPlayerdef;			// 2- player the attack is launched on
	int Playernum;				// 3- player number 
	Player *pPlayeratt;		  // 4- player the attack is launched by
	Grid *pGrid;

	
public:
	//LaunchAttack(ApplicationManager *pApp,Player *attply); // A Constructor 8.dec
	LaunchAttack(Grid*);	 // A Constructor 12.dec
	LaunchAttack();
	virtual void ReadActionParameters(); // Reads LaunchAttack action parameters (AttackNumber, player to act)
	
	virtual void Execute(); 
	~LaunchAttack(void);
};

