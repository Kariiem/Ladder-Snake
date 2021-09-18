#include "Ice.h"
#include <iostream>
using namespace std;


Ice::Ice ( Grid*g,Player *p)
{
pPlayerdef=p;	
pGrid=g;


 AttackNumber=1;
 
 Apply ();
 
}
Ice::Ice()
{
AttackNumber=1;
}
void  Ice::Apply  ()
{
	
	Player * attackingplayer=pGrid->GetCurrentPlayer();
	
	attackingplayer->dec_num_attacks_left();
	
	pPlayerdef->set_freezing_state(1);
}


Ice::~Ice(void)
{
}
