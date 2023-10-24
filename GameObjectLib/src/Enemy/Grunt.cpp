#include "Enemy/Grunt.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>   

Grunt::Grunt() {
	enemy.vie = 200;
	enemy.degate = 10;
	enemy.speed = 20;


}

//int Grunt::getPosition() {
//	enemy.p
//}

void Grunt::mouvementGrunt() {
	srand(time(nullptr));
	int rand_attack = rand() % 3 + 1;
	int rand_mouve = rand() % 3 + 1;

	if (rand_mouve == 1) {
		enemy.enemyAbstact.loadFromFile("Sprite/enemy/grunt_idle.png");
	}
	else if (rand_mouve == 1 && rand_attack == 1) {
		enemy.enemyAbstact.loadFromFile("Sprite/enemy/grunt_shoot.png");
	}
	else if (rand_mouve == 2) {
		enemy.enemyAbstact.loadFromFile("Sprite/enemy/grunt_run.png");
	}
	else if (rand_mouve == 2 && rand_attack == 1) {
		enemy.enemyAbstact.loadFromFile("Sprite/enemy/grunt_shoot.png");
	}
	else if (rand_mouve == 3) {
		enemy.enemyAbstact.loadFromFile("Sprite/enemy/grunt_crouch.png");
	}
	else if (rand_mouve == 3 && rand_attack == 1) {
		enemy.enemyAbstact.loadFromFile("Sprite/enemy/grunt_crouch_shoot_front.png");
	}
	else if (enemy.vie == 0) {
		enemy.enemyAbstact.loadFromFile("Sprite/enemy/grunt_death.png");
	}


}