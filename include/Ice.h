#pragma once
#include "Attack.h"
class Attack;
class Ice : public  Attack
{
public:
	 Ice ( Grid*g,Player *p=NULL);// A Constructor for Attack that takes the Player to act on of it
	 Ice();
	void  Apply ();
	~Ice(void);
};

