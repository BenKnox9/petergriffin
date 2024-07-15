#include "Game.h"

Game::Game(RenderWindow *window)

{
	this->window = window;
	this->window->setFramerateLimit(60);

	// Init fonts
	this->font.loadFromFile("Fonts/FamilyGuy.ttf");

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
	players.push_back(Player(&this->playerTexture, &this->bulletTexture));
	// players.push_back(Player(&this->playerTexture, &this->bulletTexture, Keyboard::Up, Keyboard::Down, Keyboard::Left, Keyboard::Right, Keyboard::Enter));

	// Init UI
	this->InitUI();

}

Game::~Game()
{
	delete player;
}

void Game::InitUI()
{
	for (size_t i; i < this->players.size(); i++) 
	{
		// Follow text init
		Text tempText;
		tempText.setFont(this->font);
		tempText.setCharacterSize(12);
		tempText.setColor(Color::Blue);
		tempText.setString(std::to_string(i));

		this->followPlayerTexts.push_back(Text(tempText));

		// Static text init
		Text tempText;
		tempText.setFont(this->font);
		tempText.setCharacterSize(12);
		tempText.setColor(Color::Blue);
		tempText.setString(std::to_string(i));

		this->staticPlayerTexts.push_back(Text(tempText));
	}
}

void Game::UpdateUI()
{
	for (size_t i = 0; i < this->followPlayerTexts.size(); i++)
	{
		this->followPlayerTexts[i].setPosition(this->players[i].getPosition());
		this->followPlayerTexts[i].setString(this->players[i].getHPString());
	}
	
	for (size_t i = 0; i < this->staticPlayerTexts.size(); i++)
	{

	}
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

	// Update UI
	this->UIUpdate();

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