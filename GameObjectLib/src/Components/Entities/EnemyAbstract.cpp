#include "Components/Entities/EnemyAbstract.h"

EnemyAbstract::EnemyAbstract() : Entity() {}
EnemyAbstract::EnemyAbstract(int _hp, int _damage, float _speed) : Entity(_hp, _damage, _speed) {}
