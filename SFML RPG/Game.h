#pragma once

#include "MainMenuState.h"

class Game
{
private:
	// Variables
	sf::RenderWindow* window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

	//Initialize
	void InitWindow();
	void InitKeys();
	void InitStates();

public:
	// Constructor/Destructor
	Game();
	virtual ~Game();

	/* ======================== */
	/*         Functions        */
	/* ======================== */

	// Regular
	void EndApplication();

	// Update
	void UpdateDt();
	void UpdateSFMLEvents();
	void Update();

	// Render
	void Render();
	
	// Core
	void Run();
};