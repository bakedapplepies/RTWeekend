#include "Ray.h"

Ray::Ray(const Point3& origin, const Vec3& direction) :
    m_origin(origin),
    m_direction(direction)
{}

Point3 Ray::At(float t) const
{
    return m_origin + m_direction * t;
}

const Point3& Ray::GetOrigin() const
{
    return m_origin;
}

const Vec3& Ray::GetDirection() const
{
    return m_direction;
}