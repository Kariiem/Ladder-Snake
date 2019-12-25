#pragma once
#include "Card.h"
#include "Ladder.h"
class CardThree: public Card
{
private:
	

public:
		CardThree(const CellPosition & pos); // A Constructor takes card position
		CardThree();
		virtual void ReadCardParameters(Grid*pGrid);
		virtual void Apply(Grid* pGrid, Player* pPlayer); 

		void Save(ofstream& OutFile);
		void Load(ifstream& Infile, Grid* pGrid) ;

		~CardThree(void);
};

