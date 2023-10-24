#include "EnemyAbstract.h"
class Grunt : public EnemyAbstract
{
public:
	
	EnemyAbstract enemy;
	Grunt();
	int getPosition();
	void mouvementGrunt();

};



