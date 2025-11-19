#pragma once

#include "State.h"

class GameState : public State
{
private:
	Entity player;

	//Functions
	void InitKeyBinds();

public:
	// Constructor
	GameState(sf::RenderWindow * window, std::map<std::string, int>* supportedKeys);
	// Destructor
	virtual ~GameState();

	// Functions
	void EndState();

	void UpdateInput(const float& dt);
	void Update(const float& dt);
	void Render(sf::RenderTarget* target = nullptr);

};