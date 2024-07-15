#pragma once

#include "Player.h"

class Game
{
private:
	RenderWindow* window;


	Font font;
	std::vector<Text> followPlayerTexts;
	std::vector<Text> staticPlayerTexts;

	std::vector<Player> players;
	Player* player;
	Texture playerTexture;
	Texture bulletTexture;

public:
	Game(RenderWindow *window);
	virtual ~Game();

	// Accessors 
	inline RenderWindow& getWindow() 
	{
		return *this->window;
	}

	// Setters


	// Functions
	void InitUI();
	void UpdateUI();
	void Update();
	void Draw();
};