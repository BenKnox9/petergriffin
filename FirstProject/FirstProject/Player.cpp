#include "Player.h"

unsigned Player::players = 0;

enum controls {UP, DOWN, LEFT, RIGHT, SHOOT};

Player::Player(Texture* texture,
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
	this->sprite.setTexture(*this->texture);

	this->sprite.setScale(3.0f, 3.0f);

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
	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::SHOOT])))
		std::cout << "SHOOT" << "\n";
}

void Player::Update()
{
	this->Movement();
}

void Player::Draw(RenderTarget &target)
{
	target.draw(this->sprite);
}
