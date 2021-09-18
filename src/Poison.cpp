#include "Poison.h"


Poison::Poison( Grid*g,Player *p)
{
 AttackNumber=3;
pPlayerdef=p;	
pGrid=g;
 Apply ();
}
Poison::Poison()
{
AttackNumber=3;
}
void Poison::Apply ()
{
	Player * attackingplayer=pGrid->GetCurrentPlayer();
	attackingplayer->dec_num_attacks_left();
	pPlayerdef->set_poisoning_level(5);

}


Poison::~Poison(void)
{
}
