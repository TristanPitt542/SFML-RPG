#pragma once

#include "State.h"

class GameState : public State
{
private:
public:
	// Constructor
	GameState(sf::RenderWindow * window);
	// Destructor
	~GameState();

	// Functions
	void EndState();

	void Update(const float& dt);
	void Render(sf::RenderTarget* target = nullptr);

};