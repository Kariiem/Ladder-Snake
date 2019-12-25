#include "Fire.h"


Fire::Fire( Grid*g,Player *p)
{
 AttackNumber=2;
pPlayerdef=p;	
pGrid=g;
 
 Apply ();
}
Fire::Fire()
{
AttackNumber=2;
}
void  Fire::Apply ( )
{
	Player * attackingplayer=pGrid->GetCurrentPlayer();
	attackingplayer->dec_num_attacks_left();
	pPlayerdef->set_burning_level(3);
}


Fire::~Fire(void)
{
}
