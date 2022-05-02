#pragma once

#include "Core/Base.h"
#include "Core/UUID.h"
#include "Renderer/Texture.h"

#include <glm/glm.hpp>

struct IDComponent
{
    UUID ID;

    IDComponent() = default;
    IDComponent(const IDComponent&) = default;
};

struct TagComponent
{
    std::string Tag;

    TagComponent() = default;
    TagComponent(const TagComponent&) = default;
};

struct SpriteRendererComponent
{
    Texture TextureHandle;
    glm::vec4 Color{0.0f, 0.0f, 0.0f, 1.0f};

    SpriteRendererComponent() = default;
    SpriteRendererComponent(const SpriteRendererComponent&) = default;
};

struct TransformComponent
{
    glm::vec3 Translation{0.0f, 0.0f, 0.0f};
    glm::vec3 Scale;

    TransformComponent() = default;
    TransformComponent(const TransformComponent&) = default;
};