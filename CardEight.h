#pragma once

#include "Card.h"



class CardEight :	public Card
{
	
public:
	CardEight (const CellPosition & pos); // A Constructor takes card position
	CardEight();

	virtual void ReadCardParameters(Grid*pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	void Save(ofstream& OutFile);
	void Load(ifstream& Infile, Grid* pGrid);

	virtual ~CardEight (); // A Virtual Destructor
};

