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
	players.push_back(Player(&this->playerTexture, &this->bulletTexture));
	// players.push_back(Player(&this->playerTexture, &this->bulletTexture, Keyboard::Up, Keyboard::Down, Keyboard::Left, Keyboard::Right, Keyboard::Enter));
	//player = new Player(&this->playerTexture);

}

Game::~Game()
{
	delete player;
}

void Game::CombatUpdate() 
{
	
}

void Game::Update()
{
	for (size_t i = 0; i < this->players.size(); i++)
	{
		this->players[i].Update(this->window->getSize());

		// Bullets update
		for (size_t k = 0; k < this->players[i].getBullets().size(); k++)
		{
			this->players[i].getBullets()[k].Update();

			// Check bullet is out of window
			if (this->players[i].getBullets()[k].getPosition().x > this->window->getSize().x)
			{
				this->players[i].getBullets().erase(this->players[i].getBullets().begin() + k);
				break;
			}
		}

		// Enemy collision check
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