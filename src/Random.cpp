#include "Random.h"

std::mt19937 Random::m_generator;
std::uniform_real_distribution<float> Random::m_distribution(0.0f, 1.0f);