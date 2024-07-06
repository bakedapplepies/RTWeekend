#pragma once

#include "src/pch/pch.h"
#include "Utils.h"

class Ray
{
private:
    Point3 m_origin;
    Vec3 m_direction;

public:
    Ray(const Point3& origin, const Vec3& direction);
    Point3 At(float t) const;

    const Point3& GetOrigin() const;
    const Vec3& GetDirection() const;
};