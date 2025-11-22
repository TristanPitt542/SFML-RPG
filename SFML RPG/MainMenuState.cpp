#include "MainMenuState.h"

void MainMenuState::InitFonts()
{
	if(!this->font.loadFromFile("Fonts/ARCADECLASSIC.ttf"))
		throw("ERROR::MAINSTATE::COULD NOT LOAD FONT");
}

void MainMenuState::InitKeyBinds()
{
	std::ifstream ifs("Config/GameState_keybinds.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keyBinds[key] = this->supportedKeys->at(key2);
		}
	}

	ifs.close();
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) : State(window, supportedKeys)
{
	this->InitFonts();
	this->InitKeyBinds();

	this->gameState_btn = new Button(100, 100, 150, 50, &this->font, "New Game", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);

}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::EndState()
{
	std::cout << "Ending MainMenuState" << std::endl;
}

void MainMenuState::UpdateInput(const float& dt)
{
	this->CheckForQuit();
}

void MainMenuState::Update(const float& dt)
{
	this->UpdateMousePositions();
	this->UpdateInput(dt);

	this->gameState_btn->Update(this->mousePosView);
}

void MainMenuState::Render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	this->gameState_btn->Render(target);
}
