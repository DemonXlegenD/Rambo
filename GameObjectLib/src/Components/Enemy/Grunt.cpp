#include "Components/Enemy/Grunt.h"

Grunt::Grunt() : EnemyAbstract(200, 10, 20) {};


void Grunt::MouvementGrunt() {
    srand(time(nullptr));
    int rand_attack = rand() % 3 + 1;
    int rand_mouve = rand() % 3 + 1;

    //if (rand_mouve == 1) {
    //    enemy.loadFromFile("Sprite/enemy/grunt_idle.png");
    //    /*grunt.SetPosition(grunt.SetPosition()) */
    //        if (rand_attack == 1) {
    //            enemy.loadFromFile("Sprite/enemy/grunt_shoot.png");
    //        }
    //}
    //else if (rand_mouve == 2) {
    //    enemy.loadFromFile("Sprite/enemy/grunt_run.png");
    //}
    //else if (rand_mouve == 3) {
    //    enemy.loadFromFile("Sprite/enemy/grunt_crouch.png");
    //    if (rand_attack == 1) {
    //        enemy.loadFromFile("Sprite/enemy/grunt__crouch_shoot_front.png");
    //    }
    //}
    //else if (hp == 0) {
    //    enemy.loadFromFile("Sprite/enemy/grunt_death.png");
    //}
}