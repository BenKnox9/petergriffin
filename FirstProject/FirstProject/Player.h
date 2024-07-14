#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class Player
{
private:
	Texture* texture;
	Sprite sprite;
	RectangleShape hitBox;

	int controls[5];

	int level;
	int exp;
	int expNext;

	int hp;
	int hpMax;

	int damage;
	int damageMax;

	int score;


public: 
	Player(Texture* texture,
		int UP = 22, int DOWN = 18,
		int LEFT = 0, int RIGHT = 3,
		int SHOOT = 57
	);

	virtual ~Player();

	void Movement();
	void Update();
	void Draw(RenderTarget &target);
};

