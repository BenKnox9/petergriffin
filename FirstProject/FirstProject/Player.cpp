#include "Player.h"

unsigned Player::players = 0;

enum controls {UP, DOWN, LEFT, RIGHT, SHOOT};

Player::Player(Texture* texture, Texture *bulletTexture,
	int UP, int DOWN,
	int LEFT, int RIGHT,
	int SHOOT)
	:level(1),
	exp(0), expNext(100),
	hp(10), hpMax(10),
	damage(1), damageMax(2),
	score(0)
{
	this->texture = texture;
	this->bulletTexture = bulletTexture;
	this->sprite.setTexture(*this->texture);
	this->sprite.setScale(1.5f, 1.5f);

	this->shootTimerMin = 20;
	this->shootTimerMax = 25;
	this->shootTimer = this->shootTimerMax;
	this->damageTimerMax = 10;
	this->damageTimer = this->damageTimerMax;

	this->controls[controls::UP] = UP;
	this->controls[controls::DOWN] = DOWN;
	this->controls[controls::LEFT] = LEFT;
	this->controls[controls::RIGHT] = RIGHT;
	this->controls[controls::SHOOT] = SHOOT;

	this->playerNumber = Player::players;
	Player::players++;

	std::cout << this->players << std::endl;
}

Player::~Player()
{

}

void Player::Movement()
{
	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::UP])))
		this->sprite.move(0.f, -5.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::DOWN])))
		this->sprite.move(0.f, 5.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::LEFT])))
		this->sprite.move(-5.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::RIGHT])))
		this->sprite.move(5.f, 0.f);

}

void Player::Combat() 
{
	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::SHOOT])) && this->shootTimer >= this->shootTimerMin)
	{
		this->bullets.push_back(Bullet(bulletTexture, this->sprite.getPosition()));
		if (this->shootTimer >= this->shootTimerMax) 
		{
			this->shootTimer = 0;
		}
	}
}

void Player::Update(Vector2u windowBounds)
{
	// Update timers
	if (this->shootTimer < this->shootTimerMax) {
		this->shootTimer++;
	}

	if (this->damageTimer < this->damageTimerMax) {
		this->damageTimer++;
	}

	this->Movement();
	this->Combat();
}

void Player::Draw(RenderTarget &target)
{
	target.draw(this->sprite);

	for (size_t i = 0; i < this->bullets.size(); i++)
	{
		this->bullets[i].Draw(target);
	}
}
