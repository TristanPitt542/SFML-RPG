#include "GameState.h"

void GameState::InitKeyBinds()
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

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) : State(window, supportedKeys)
{
	this->InitKeyBinds();
}

GameState::~GameState()
{
}

void GameState::EndState()
{
	std::cout << "Ending GameState" << std::endl;
}

void GameState::UpdateInput(const float& dt)
{
	this->CheckForQuit();

	//PlayerInput
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("Move_Left"))))
	{
		this->player.Move(dt, -1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("Move_Right"))))
	{
		this->player.Move(dt, 1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("Move_Up"))))
	{
		this->player.Move(dt, 0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("Move_Down"))))
	{
		this->player.Move(dt, 0.f, 1.f);
	}
}

void GameState::Update(const float& dt)
{
	this->UpdateMousePositions();

	this->UpdateInput(dt);

	this->player.Update(dt);
}

void GameState::Render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	this->player.Render(this->window);
		
}
