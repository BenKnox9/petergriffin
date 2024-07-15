#pragma once

#include "Bullet.h"

using namespace sf;

class Player
{
private:
	unsigned playerNumber;
	Texture* texture;
	Sprite sprite;
	RectangleShape hitBox;

	Texture* bulletTexture;
	std::vector <Bullet> bullets;

	int shootTimer;
	int shootTimerMin;
	int shootTimerMax;
	int damageTimer;
	int damageTimerMax;


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
	Player(Texture* texture, Texture *bulletTexture,
		int UP = 22, int DOWN = 18,
		int LEFT = 0, int RIGHT = 3,
		int SHOOT = 57
	);

	virtual ~Player();

	// Accessors
	inline std::vector<Bullet>& getBullets() 
	{
		return this->bullets; 
	}

	inline const Vector2f& getPosition() const 
	{ 
		return this->sprite.getPosition(); 
	}

	inline const String& getHPString() const
	{
		return std::to_string(this->hp) + " / " + std::to_string(this->hpMax)	;
	}


	// Functions
	void Movement();
	void Combat();
	void Update(Vector2u windowBounds);
	void Draw(RenderTarget &target);

	// Statics
	static unsigned players;
};

