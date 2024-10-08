#ifndef ENTEICOMPONENTSYSTEM_HPP
#define ENTEICOMPONENTSYSTEM_HPP
#include <array>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include "Exception.hpp"

namespace core {
    using Entity = std::size_t;

    /// @brief EntityManager class manages the creation and destruction of entities.
    /// An entity is simply an ID represented by a `std::size_t` that is managed by this class.
    /// The class ensures that entities are created uniquely and can be destroyed or reused.
    class EntityManager {
    public:
        /// @brief Factory method to create an instance of EntityManager.
        /// @return A new instance of EntityManager.
        static EntityManager create_entity_manager() { return EntityManager{}; }

        /// @brief Creates a new entity.
        /// @return The newly created entity (an ID).
        Entity create_new_entity();

        /// @brief Destroys an existing entity.
        /// If the entity does not exist, it returns an error.
        /// @param entity The entity to be destroyed.
        /// @return Status of the destruction operation (success or error).
        sts::error destroy_entity(Entity entity);

    private:
        EntityManager() = default;

        std::queue<Entity> m_available_entities{};
        std::unordered_set<Entity> m_living_entities{};
        std::size_t m_total_entity_count{};
    };

    constexpr std::size_t ENTITY_COUNT = 1000;

    class BaseComponent {
    public:
        virtual ~BaseComponent() = default;
        virtual sts::error destroy_entity(Entity entity) = 0;
    };

    template<typename T>
    class Component : public BaseComponent {
    public:
        sts::error add_component(Entity entity, T const &component) {
            if (m_entity_to_index.contains(entity)) {
                return sts::error::entity_exists;
            }

            if (auto const new_index = m_entity_count; new_index < ENTITY_COUNT) {
                m_entity_to_index[entity] = new_index;
                m_index_to_entity[new_index] = entity;
                ++m_entity_count;
                m_components[new_index] = component;
                return sts::error::ok;
            }
            return sts::error::entity_limit;
        }

        sts::error remove_component(Entity entity) {
            if (auto const removed_entity = m_entity_to_index.find(entity); removed_entity != m_entity_to_index.end()) {
                auto const index_removed_entity = removed_entity->second;
                auto const index_last_entity = m_entity_count - 1;
                m_components[index_removed_entity] = m_components[index_last_entity];

                auto const last_entity = m_index_to_entity[index_last_entity];
                m_entity_to_index[last_entity] = index_removed_entity;
                m_index_to_entity[index_removed_entity] = last_entity;

                m_entity_to_index.erase(entity);
                m_index_to_entity.erase(index_last_entity);
                --m_entity_count;
                return sts::error::ok;
            }
            return sts::error::invalid_entity;
        }

        sts::error destroy_entity(Entity entity) override {
            return remove_component(entity);
        }

        T &get(Entity entity) {
            if (m_entity_to_index.contains(entity)) {
                try {
                    return m_components.at(m_entity_to_index.at(entity));

                } catch (std::out_of_range const &e) {
                    throw sts::CoreError(
                            std::format("retireving component for entity {} failed: {}", entity, e.what()));
                }
            }
            throw sts::CoreError(std::format("invalid entity {}", entity));
        }


        T get(Entity entity) const {
            if (m_entity_to_index.contains(entity)) {
                try {
                    return m_components.at(m_entity_to_index.at(entity));

                } catch (std::out_of_range const &e) {
                    throw sts::CoreError(
                            std::format("retireving component for entity {} failed: {}", entity, e.what()));
                }
            }
            throw sts::CoreError(std::format("invalid entity {}", entity));
        }

    private:
        std::unordered_map<Entity, std::size_t> m_entity_to_index{};
        std::unordered_map<std::size_t, Entity> m_index_to_entity{};
        std::size_t m_entity_count{};
        using ComponentArray = std::array<T, ENTITY_COUNT>;
        ComponentArray m_components{};
    };

    class ComponentManager {
    public:
        template<typename T>
        sts::error add_to_component(Entity entity, T const &component) {
            static_assert(std::is_default_constructible_v<T>, "Component type has to be default constructable");

            auto const type = typeid(T).name();
            if (!m_components.contains(type)) {
                m_components[type] = std::make_shared<Component<T>>();
            }

            return get_component_ptr<T>()->add_component(entity, component);
        }

        template<typename T>
        sts::error remove_from_component(Entity entity) {
            auto const type = typeid(T).name();
            if (!m_components.contains(type)) {
                return sts::error::invalid_component;
            }

            return get_component_ptr<T>()->remove_component(entity);
        }

        template<typename T>
        T &get_component(Entity entity) {
            return get_component_ptr<T>()->get(entity);
        }

        template<typename T>
        T get_component(Entity entity) const {
            return get_component_ptr<T>()->get(entity);
        }

        sts::error destroy_entity(Entity entity) {
            for(auto const& component : m_components) {
                if(auto const success = component.second->destroy_entity(entity);success!=sts::error::ok) {
                    return success;
                }
            }
            return sts::error::ok;
        }

    private:
        template<typename T>
        std::shared_ptr<Component<T>> get_component_ptr() {
            auto const type = typeid(T).name();
            try {
                return std::static_pointer_cast<Component<T>>(m_components.at(type));
            } catch (std::out_of_range const &e) {
                throw sts::CoreError(std::format("static_pointer_cast failed: {}", e.what()));
            }
        }

        std::unordered_map<std::string, std::shared_ptr<BaseComponent>> m_components{};
    };

    class System {
    private:
        std::unordered_set<Entity> m_entities;
    public:
        System() = default;

        sts::error add_entity(Entity entity);
        sts::error remove_entity(Entity entity);

        virtual void update() = 0;

    };
} // namespace core

#endif
