#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

// SFML include
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

class State
{
private:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;

public:
	// Constructor/Destructor
	State(sf::RenderWindow* window);
	virtual ~State();

	// Functions
	virtual void Update(const float& dt) = 0;
	virtual void Render(sf::RenderTarget* target = nullptr) = 0;
	virtual void EndState() = 0;
};