#include "Game.h"

#include "Core/Base.h"

Game::Game()
{
    CORE_LOG("Hello");
    CORE_ASSERT(Init(), "Game failed to initialize!");
}

Game::~Game()
{

}

bool Game::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        CORE_LOG("SLD_Init failed!");
        CORE_LOG(SDL_GetError());
        return false;
    }

    // Create window
    m_window = SDL_CreateWindow("Pacman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
    CORE_ASSERT(m_window, "Failed to create window!");

    // Get window surface
    m_surface = SDL_GetWindowSurface(m_window);
    SDL_FillRect(m_surface, NULL, SDL_MapRGB(m_surface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(m_window);
    SDL_Delay(2000);

    CORE_LOG("Goodbye!");

    return true;
}

void Game::Run()
{
    
}

void Game::Update()
{

}

void Game::Render()
{

}