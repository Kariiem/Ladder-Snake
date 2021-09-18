#include "Lighting.h"


Lighting::Lighting( Grid*g,Player *p)
{
 AttackNumber=4;
pPlayerdef=p;	
pGrid=g;
 Apply ();
}
Lighting::Lighting()
{
AttackNumber=4;
}
void Lighting::Apply ()
{
	/*int playerattnum= pGrid->get_player_num(pPlayeratt);
	for (int i=0;i<4;i++) 
	{
	 if (i!= playerattnum) 
	 {
		 Player * pPlayer = pGrid->get_player_from_num (i);
	 pPlayer->SetWallet( pPlayer->GetWallet()-20);
	 }

	}*/
	Player * attackingplayer=pGrid->GetCurrentPlayer();
	attackingplayer->dec_num_attacks_left();
	for (int i=0;i<4;i++)
	{
		if ((pGrid->GetCurrentPlayer())!=attackingplayer) (pGrid->GetCurrentPlayer())->SetWallet(pGrid->GetCurrentPlayer()->GetWallet()-20);
		pGrid->AdvanceCurrentPlayer();
	}
	attackingplayer->dec_num_attacks_left();
}


Lighting::~Lighting(void)
{
}
