#include "GameObject.h"
#include "EnemyAbstract.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Grunt : public EnemyAbstract
{
public:

    Grunt();
    void mouvementGrunt();

};