#pragma once

#include "Entity.h"

class State
{
private:

protected:
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keyBinds;
	bool quit;
	
	//Mouse
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Resources
	std::vector<sf::Texture> textures;

	//Functions
	virtual void InitKeyBinds() = 0;

public:
	// Constructor
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	// Destructor
	virtual ~State();

	// Functions
	const bool& GetQuit() const;

	virtual void CheckForQuit();
	
	virtual void EndState() = 0;
	virtual void UpdateMousePositions();
	virtual void UpdateInput(const float& dt) = 0;
	virtual void Update(const float& dt) = 0;
	virtual void Render(sf::RenderTarget* target = nullptr) = 0;
};