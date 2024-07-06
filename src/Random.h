#pragma once

#include "src/pch/pch.h"
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
};