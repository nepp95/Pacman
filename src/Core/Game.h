#pragma once

#include "Core/Event.h"

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
    // void HandleEvents(Event& e);

private:
    SDL_Window* m_window;
    SDL_Surface* m_surface;
};