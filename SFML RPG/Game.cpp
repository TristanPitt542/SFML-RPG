#include "Game.h"

void Game::InitWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "RPG");
}

// Constructor
Game::Game()
{
    this->InitWindow();
}
//Destructor
Game::~Game()
{
    delete this->window;
}

void Game::Update()
{
    this->UpdateSFMLEvents();
}

void Game::UpdateDt()
{
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::UpdateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::Render()
{
    this->window->clear();

    //render items

    this->window->display();
}

void Game::Run()
{
    while (window->isOpen())
    {
        this->UpdateDt();
        this->Update();
        this->UpdateSFMLEvents();
        this->Render();
    }
}