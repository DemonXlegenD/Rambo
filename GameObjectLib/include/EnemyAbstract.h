#pragma once
#include "Components/Component.h"
#include "Scene.h"

class EnemyAbstract : public Component {
public:
    EnemyAbstract();
    EnemyAbstract(int _hp, int _damage, int _speed);
protected:
    int hp;
    int damage;
    int speed;
    Scene scene;


    int pvEnemy(int degat);
};