#pragma once

#include "Renderer/Scene.h"

#include <SDL.h>

class Game
{
public:
    Game();
    ~Game();

    bool Init();
    void Run();

    void Update();
    void Render();

private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    SDL_Event m_event;

    Scene* m_activeScene;

    bool m_running = false;
};