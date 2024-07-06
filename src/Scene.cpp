#include "Scene.h"

void Scene::Clear()
{
    m_objects.clear();
}

bool Scene::HasHit(const Ray& ray, const Interval& interval, HitRecord& record) const
{
    HitRecord tempRecord;
    bool hitAnything = false;
    float closestSoFar = interval.max;

    for (const std::unique_ptr<Hittable>& obj : m_objects)
    {
        if (obj->HasHit(ray, Interval(interval.min, closestSoFar), tempRecord))
        {
            hitAnything = true;
            closestSoFar = tempRecord.t;
            record = tempRecord;
        }
    }

    return hitAnything;
}