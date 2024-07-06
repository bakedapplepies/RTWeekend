#pragma once

#include "src/pch/pch.h"
#include "src/shapes/Hittable.h"
#include "src/Interval.h"

class Scene
{
private:
    std::vector< std::unique_ptr<Hittable> > m_objects;
    
public:
    Scene() = default;

    template <typename T, typename... Args>
    void AddObj(Args&&... args)
    {
        static_assert(!std::is_same<Hittable, T>(), "Scene object can't be abstract class Hittable.");
        static_assert(std::is_base_of<Hittable, T>(), "Scene object is not derived from Hittable.");

        std::unique_ptr<Hittable> obj = std::make_unique<T>(std::forward<Args>(args)...);
        m_objects.push_back(std::move(obj));
    }

    void Clear();
    bool HasHit(const Ray& ray, const Interval& interval, HitRecord& record) const;
};