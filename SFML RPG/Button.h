#pragma once

#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>

// SFML include
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

enum button_States { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };

class Button
{
private:
	short unsigned buttonState;

	bool pressed;
	bool hover;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

public:
	//Constructor
	Button(float x, float y, float width, float height, sf::Font* font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	// Destructor
	virtual~Button();

	// Accessors
	const bool IsPressed() const;

	//Functions
	void Update(sf::Vector2f mousePos);
	void Render(sf::RenderTarget* target);
};

