#ifndef Game_H
#define Game_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

class Game
{
private:
	//variables
	sf::RenderWindow* window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	//Initialize
	void InitWindow();
public:
	//Constructor/Destructor
	Game();
	virtual ~Game();

	//Functions
	void Update();
	void UpdateDt();
	void UpdateSFMLEvents();
	void Render();
	void Run();
};
#endif