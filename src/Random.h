#pragma once

#include "src/pch/pch.h"
#include "src/Utils.h"
#include <random>

class Random
{
private:
    static std::uniform_real_distribution<float> m_distribution;
    static std::mt19937 m_generator;

public:
    inline static float Float()
    {
        return m_distribution(m_generator);
    }

    inline static float Float(float min, float max)
    {
        return min + (max - min) * Float();
    }

    inline static Vec3 Vector3()
    {
        return Vec3(
            Random::Float(),
            Random::Float(),
            Random::Float()
        );
    }

    inline static Vec3 Vector3(float min, float max)
    {
        return Vec3(
            Random::Float(min, max),
            Random::Float(min, max),
            Random::Float(min, max)
        );
    }
};