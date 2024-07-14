#include "Game.h"

Game::Game(RenderWindow *window)

{
	this->window = window;
	window->setFramerateLimit(60);

	// Init textures
	if (!playerTexture.loadFromFile("Textures/petergriffinspritesheet.png", sf::IntRect(0, 0, 64, 64)))
	{
		// error...
	}
	if (!bulletTexture.loadFromFile("Textures/petergriffinspritesheet.png", sf::IntRect(0, 64, 64, 64)))
	{
		// error...
	}

	// Init player 
	// Default is WASD and space, but enter parameters as shown below for different binds
	// player = new Player(&this->playerTexture, Keyboard::Up, Keyboard::Down, Keyboard::Left, Keyboard::Right, Keyboard::Enter);
	players.push_back(Player(&playerTexture, &bulletTexture));
	//player = new Player(&this->playerTexture);

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