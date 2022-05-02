#pragma once

#include "Renderer/Components.h"

class Renderer
{
public:
    Renderer(SDL_Renderer* renderer);
    ~Renderer();

    static void Init();
    static void Shutdown();

    static void RenderQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
    static void RenderQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color);
    static void RenderQuad(const glm::mat4& transform, const glm::vec4& color, int entityID = -1);

    static void RenderSprite(const glm::mat4& transform, SpriteRendererComponent& src, int entityID);

private:
    void StartBatch();
    void FlushAndReset();

private:
    SDL_Renderer* m_renderer;
};