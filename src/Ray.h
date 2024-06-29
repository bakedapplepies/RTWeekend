#pragma once

#include "src/pch/pch.h"
#include "Utils.h"

class Ray
{
private:
    Point3 m_origin;
    Vec3 m_dir;

public:
    Ray() = default;
    Point3 at(double t) const;
};