#pragma once
#include "Card.h"
#include "Snake.h"
class CardFour:public Card
{

public:
	CardFour(const CellPosition & pos); // A Constructor takes card position
	CardFour();
	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardOne which is: walletAmount
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player 

	void Save(ofstream& OutFile);
	void Load(ifstream& Infile, Grid* pGrid);

	~CardFour(void);
};

