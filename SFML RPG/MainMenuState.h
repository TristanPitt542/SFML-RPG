#pragma once
#include "GameState.h"
#include "Button.h"

class MainMenuState : public State
{
private:
	// Varriables
	sf::RectangleShape background;
	sf::Font font;

	Button* gameState_btn;
	//Functions
	void InitFonts();
	void InitKeyBinds();

public:
	// Constructor
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	// Destructor
	virtual ~MainMenuState();

	// Functions
	void EndState();

	void UpdateInput(const float& dt);
	void Update(const float& dt);
	void Render(sf::RenderTarget* target = nullptr);

};

