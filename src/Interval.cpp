#include "Interval.h"

Interval::Interval(float min, float max) :
    min(min),
    max(max)
{}

float Interval::Size() const
{
    return max - min;
}

bool Interval::Contains(float x) const
{
    return min < x && x < max;
}

bool Interval::Surrounds(float x) const
{
    return min <= x && x <= max;
}

float Interval::Clamp(float x) const
{
    return (x < min) ? min :
           (x > max) ? max :
            x;
}

const Interval Interval::EMPTY(FLOAT_INF, -FLOAT_INF);
const Interval Interval::WORLD(-FLOAT_INF, FLOAT_INF);