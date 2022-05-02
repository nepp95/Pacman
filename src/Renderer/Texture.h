#pragma once

#include <SDL.h>

class Texture
{
public:
    Texture();
    Texture(const std::string& filepath);
    ~Texture();

private:
    SDL_Texture* m_texture;
    bool m_isLoaded = false;
    std::string m_filepath;

    uint32_t m_width, m_height;
};