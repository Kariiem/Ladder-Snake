#pragma once
#include "Attack.h"
class Attack;
class Lighting : public  Attack
{
public:
	 Lighting( Grid*g,Player *p=NULL); // A Constructor for Attack that takes the Player to act on of it
	 Lighting();
	void  Apply ();
	~Lighting(void);
};

