#pragma once
#include "Components/Component.h"
#include "Scene.h"

class EnemyAbstract : public Component {
public:
    EnemyAbstract();
    EnemyAbstract(int _hp, int _damage, int _speed); 
    
    int GetHP() const { return hp; }

    void TakeDamage(int damage);

protected:
    int hp;
    int damage;
    int speed;
};