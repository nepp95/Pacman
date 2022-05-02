#include "pch.h"
#include "Scene.h"

#include "Renderer/Components.h"
#include "Renderer/Entity.h"

Scene::Scene()
{}

Scene::~Scene()
{}

Entity Scene::CreateEntity(const std::string& name)
{
    return CreateEntityWithUUID(UUID(), name);
}

Entity Scene::CreateEntityWithUUID(UUID uuid, const std::string& name)
{
    Entity entity = { m_registry.create(), this };
    entity.AddComponent<IDComponent>(uuid);
    entity.AddComponent<TransformComponent>();

    auto& tag = entity.AddComponent<TagComponent>();
    tag.Tag = name.empty() ? "Entity" : name;

    return entity;
}

void Scene::DestroyEntity(Entity entity)
{
    m_registry.destroy(entity);
}

void Scene::DuplicateEntity(Entity entity)
{
    //Entity newEntity = CreateEntity(entity.GetName());
    // Copy components
}

void Scene::Update()
{
    
}

void Scene::Render()
{
    auto view = m_registry.view<TransformComponent, SpriteRendererComponent>();

    for (auto entity : view)
    {
        auto [transform, sprite] = view.get<TransformComponent, SpriteRendererComponent>(entity);
        // Renderer::DrawSprite(transform.GetTransform(), sprite, (int) entity);
    }
}

template<typename T>
void Scene::OnComponentAdded(Entity entity, T& component)
{
    static_assert(sizeof(T) == 0);
}

template<>
void Scene::OnComponentAdded<IDComponent>(Entity entity, IDComponent& component)
{}

template<>
void Scene::OnComponentAdded<TagComponent>(Entity entity, TagComponent& component)
{}

template<>
void Scene::OnComponentAdded<SpriteRendererComponent>(Entity entity, SpriteRendererComponent& component)
{}

template<>
void Scene::OnComponentAdded<TransformComponent>(Entity entity, TransformComponent& component)
{}