#pragma once

#include "Core/Base.h"

#include <glm/glm.hpp>

struct TagComponent
{
    std::string Tag;

    TagComponent();
    TagComponent(const TagComponent&);
};

struct SpriteRendererComponent
{
    

    SpriteRendererComponent();
    SpriteRendererComponent(const SpriteRendererComponent&);
};

struct TransformComponent
{
    glm::vec3 Translation{0.0f, 0.0f, 0.0f};
    glm::vec3 Scale;

    TransformComponent();
    TransformComponent(const TransformComponent&);
};