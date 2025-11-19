#pragma once

#include "GameState.h"

class Game
{
private:
	// Variables
	sf::RenderWindow* window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	//Initialize
	void InitWindow();
	void InitStates();

public:
	// Constructor/Destructor
	Game();
	virtual ~Game();

	// Functions
	void UpdateDt();
	void UpdateSFMLEvents();
	void Update();
	void Render();
	void Run();
};