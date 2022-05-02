#pragma once

#include "Core/UUID.h"
#include "Renderer/Components.h"

#include <entt.hpp>

class Entity;

class Scene
{
public:
    Scene();
    ~Scene();

    Entity CreateEntity(const std::string& name = std::string());
    Entity CreateEntityWithUUID(UUID uuid, const std::string& name = std::string());

    void DestroyEntity(Entity entity);
    void DuplicateEntity(Entity entity);

    void Update();
    void Render();

    Entity GetPrimaryCameraEntity();

private:
    template<typename T>
    void OnComponentAdded(Entity entity, T& component);

private:
    entt::registry m_registry;
    
    friend class Entity;
};