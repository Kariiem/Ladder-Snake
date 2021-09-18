#include "Attack.h"

Attack::Attack(Grid*g,Player *p)
{
	Player *pPlayerdef=p;	
	Grid *pGrid=g;
	
}
Attack::Attack()
{
}

void Attack::SetAttackNumber(int anum)
{
	if (anum>0 && anum<4) AttackNumber = anum; 
}
int Attack::GetAttackNumber()
{
	return AttackNumber;
}


void Attack::Apply(Grid*g,Player *p)
{
	

}


Attack::~Attack()
{
}
