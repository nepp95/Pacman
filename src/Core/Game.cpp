#include "Game.h"

#include "Core/Base.h"
#include "Renderer/Renderer.h"

Game::Game()
{
    CORE_ASSERT(Init(), "Game failed to initialize!");

    m_running = true;
}

Game::~Game()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();

    delete m_activeScene;
    m_activeScene = nullptr;
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

    // Create renderer
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    CORE_ASSERT(m_renderer, "Failed to create renderer!");

    // Create scene
    m_activeScene = new Scene();

    return true;
}

void Game::Run()
{
    while (m_running)
    {
        Update();
        Render();
    }
}

void Game::Update()
{
    while (SDL_PollEvent(&m_event) != 0)
    {
        if (m_event.type == SDL_QUIT)
            m_running = false;
    }

    m_activeScene->Update();
}

void Game::Render()
{
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);

    // Render stuff
    m_activeScene->Render();
    //

    SDL_RenderPresent(m_renderer);
}