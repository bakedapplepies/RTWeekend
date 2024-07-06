#include "Sphere.h"

Sphere::Sphere(const Point3& center, float radius) :
    m_center(center),
    m_radius(radius)
{}

bool Sphere::HasHit(const Ray& ray, const Interval& interval, HitRecord& record) const
{
    Vec3 oc = m_center - ray.GetOrigin();
    float a = glm::dot(ray.GetDirection(), ray.GetDirection());
    float h = glm::dot(ray.GetDirection(), oc);
    float c = glm::dot(oc, oc) - powf(m_radius, 2);

    float discriminant = powf(h, 2) - a * c;

    if (discriminant < 0.0f)
        return false;
    
    float sqrt_f = sqrtf(discriminant);

    float root = (h - sqrt_f) / a;
    // Note: Interval is postive, so all first hits should be in front of the camera
    if (!interval.Surrounds(root))
    {
        root = (h + sqrt_f) / a;
        if (!interval.Surrounds(root))
        {
            return false;
        }
    }

    record.t = root;
    record.point = ray.At(root);
    record.SetFaceNormal(ray, (record.point - m_center) / m_radius);

    return true;
}