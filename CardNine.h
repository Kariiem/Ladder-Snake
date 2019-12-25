#pragma once

#include "Card.h"

class CardNine :	public Card
{
	int specific_cell;
public:
	CardNine (const CellPosition & pos); // A Constructor takes card position
	CardNine();
	virtual void ReadCardParameters(Grid * pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	void Load(ifstream& Infile, Grid* pGrid) ;
	void Save(ofstream& OutFile);

	virtual ~CardNine (); // A Virtual Destructor
};

