#include "pch.h"
#include "Renderer.h"

#include "Core/Base.h"

Renderer::Renderer(SDL_Renderer* renderer)
    : m_renderer(renderer)
{


}

Renderer::~Renderer()
{}

void Renderer::Init()
{
    
}

void Renderer::Shutdown()
{}

void Renderer::RenderQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color)
{
    RenderQuad({ position.x, position.y, 0.0f }, size, color);
}

void Renderer::RenderQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color)
{
    SDL_Rect rect{ position.x, position.y, 64, 64 };
    SDL_SetRenderDrawColor(m_renderer, color.r * 255, color.g * 255, color.b * 255, color.a * 255);
    
}

void Renderer::RenderQuad(const glm::mat4& transform, const glm::vec4& color, int entityID)
{
}

void Renderer::RenderSprite(const glm::mat4& transform, SpriteRendererComponent& src, int entityID)
{
}

void Renderer::StartBatch()
{}

void Renderer::FlushAndReset()
{}