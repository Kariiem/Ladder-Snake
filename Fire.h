#pragma once
#include "Attack.h"
class Attack;
class Fire : public  Attack
{
public:
	 Fire( Grid*g,Player *p=NULL); // A Constructor for Attack that takes the Player to act on of it
	 Fire();
	void  Apply ();
	~Fire(void);
};

