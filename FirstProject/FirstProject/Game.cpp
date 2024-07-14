#include "Game.h"

Game::Game(RenderWindow *window)

{
	this->window = window;
	window->setFramerateLimit(60);

	// Init textures
	if (!playerTexture.loadFromFile("Textures/petergriffin_transparent.png", sf::IntRect(0, 0, 32, 32)))
	{
		// error...
	}

	// Init player 
	// Default is WASD and space, but enter parameters as shown below for different binds
	// player = new Player(&this->playerTexture, Keyboard::Up, Keyboard::Down, Keyboard::Left, Keyboard::Right, Keyboard::Enter);
	players.push_back(Player(&playerTexture));
	player = new Player(&this->playerTexture);

}

Game::~Game()
{
	delete player;
}

void Game::Update()
{
	for (size_t i = 0; i < this->players.size(); i++)
	{
		this->players[i].Update();
	}
}

void Game::Draw()
{
	window->clear();

	for (size_t i = 0; i < this->players.size(); i++)
	{
		this->players[i].Draw(*this->window);
	}

	this->window->display();
}