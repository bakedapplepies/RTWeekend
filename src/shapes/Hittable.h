#pragma once

#include "src/pch/pch.h"
#include "src/Utils.h"
#include "src/Ray.h"
#include "src/Interval.h"

class HitRecord
{
public:
    Point3 point;
    Vec3 normal;
    float t;
    bool isFrontFace;

    // outward_normal must be of unit-length
    void SetFaceNormal(const Ray& ray, const Vec3& outward_normal)
    {
        isFrontFace = glm::dot(ray.GetDirection(), outward_normal) < 0.0f;
        normal = isFrontFace ? outward_normal : -outward_normal;
    }
};

class Hittable
{
public:
    Hittable() = default;
    virtual ~Hittable() = default;

    virtual bool HasHit(const Ray& ray, const Interval& interval, HitRecord& record) const = 0;
};