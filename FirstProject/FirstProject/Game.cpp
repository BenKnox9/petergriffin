#include "Game.h"

Game::Game(RenderWindow *window)

{
	this->window = window;
	window->setFramerateLimit(60);

	// Init textures
	if (!playerTexture.loadFromFile("Textures/petergriffin.jpg", sf::IntRect(0, 0, 32, 32)))
	{
		// error...
	}

	// Init player default is WASD and space, but enter parameters e.g. Keyboard::5 for different controls
	player = new Player(&this->playerTexture);
}

Game::~Game()
{
	delete player;
}

void Game::Update()
{
	player->Update();
}

void Game::Draw()
{
	window->clear();
	player->Draw(*window);
	window->display();
}