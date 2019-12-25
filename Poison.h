#pragma once
#include "Attack.h"
class Attack;
class Poison : public  Attack
{
public:
	Poison( Grid*g,Player *p=NULL); // A Constructor for Attack that takes the Player to act on of it
	 Poison();
	void  Apply ();
	~Poison(void);
};

