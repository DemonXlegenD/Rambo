#include "Components/EnemyAbstract.h"

EnemyAbstract::EnemyAbstract() : hp(100), damage(10), speed(20) {}
EnemyAbstract::EnemyAbstract(int _hp, int _damage, int _speed) : hp(_hp), damage(_damage), speed(_speed) {}

void EnemyAbstract::TakeDamage(int damage) {
    hp -= damage;
}