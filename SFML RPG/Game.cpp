#include "Game.h"

// Constructor
Game::Game()
{
    this->InitWindow();
    this->InitKeys();
    this->InitStates();
}

// Destructor
Game::~Game()
{
    delete this->window;
    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}

// Init
void Game::InitWindow()
{
    // Create window using SFML
    std::ifstream ifs("Config/Window.ini");

    std::string title = "None";
    sf::VideoMode window_bounds(800,600);
    unsigned frameRateLimit = 120;
    bool verticalSyncEnabled = false;

    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> frameRateLimit;
        ifs >> verticalSyncEnabled;
    }

    ifs.close();

    this->window = new sf::RenderWindow(sf::VideoMode(window_bounds), title);
    this->window->setFramerateLimit(frameRateLimit);
    this->window->setVerticalSyncEnabled(verticalSyncEnabled);

}

void Game::InitKeys()
{
    this->supportedKeys.emplace("Escape", sf::Keyboard::Key::Escape);
    this->supportedKeys.emplace("A", sf::Keyboard::Key::A);
    this->supportedKeys.emplace("D", sf::Keyboard::Key::D);
    this->supportedKeys.emplace("W", sf::Keyboard::Key::W);
    this->supportedKeys.emplace("S", sf::Keyboard::Key::S);

    std::cout << this->supportedKeys.at("A") << std::endl;
}

void Game::InitStates()
{
    this->states.push(new GameState(this->window, &this->supportedKeys));
}

// Functions
void Game::EndApplication()
{
    std::cout << "Ending Application" << std::endl;
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

void Game::Update()
{
    this->UpdateSFMLEvents();

    if (!this->states.empty())
    {
        this->states.top()->Update(this->dt);

        if (this->states.top()->GetQuit())
        {
            //Quit events here
            this->states.top()->EndState();
            delete this->states.top();
            this->states.pop();
        }
    }
    // Application end
    else
    {
        this->EndApplication();
        this->window->close();
    }

}

void Game::Render()
{
    this->window->clear();

    //render items
    if (!this->states.empty())
        this->states.top()->Render(this->window);

    this->window->display();
}

void Game::Run()
{
    while (window->isOpen())
    {
        this->UpdateDt();
        this->Update();
        this->Render();
    }
}