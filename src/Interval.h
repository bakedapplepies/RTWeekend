#pragma once

#include "src/pch/pch.h"
#include "src/Utils.h"

class Interval
{
public:
    float min = FLOAT_INF;
    float max = -FLOAT_INF;

public:
    Interval() = default;
    Interval(float min, float max);

    float Size() const;
    bool Contains(float x) const;
    bool Surrounds(float x) const;
    float Clamp(float x) const;

    static const Interval EMPTY;
    static const Interval WORLD;
};