#pragma once
//#include "GameObject.h"
#include "Player.h"
#include "Grid.h" // M.W
// Base Class of All Types of Attacks (Ice,Fire,Poison,lightning)
class Attack
{
protected:
	int AttackNumber; // an integer representing the Attack number
	Player *pPlayerdef;	
	Grid *pGrid;

public:
	Attack(Grid*,Player *p = NULL); // A Constructor for Attack that takes the Player to act on it 12.dec
	Attack();

	void SetAttackNumber(int);   // The setter of Attack number
	int GetAttackNumber();            // The getter of Attack number

	virtual void Apply(Grid*,Player *p = NULL);  // It applies the effect of the Attack Type on the selected player
	  
	

	virtual ~Attack(); // A Virtual Destructor
};

