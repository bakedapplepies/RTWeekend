#pragma once

#include "src/shapes/Hittable.h"

class Sphere : public Hittable
{
private:
    Point3 m_center;
    float m_radius;

public:
    Sphere(const Point3& center, float radius);

    bool HasHit(const Ray& ray, const Interval& interval, HitRecord& record) const override;
};