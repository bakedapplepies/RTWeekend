#pragma once

#include "src/pch/pch.h"
#include "src/Utils.h"
#include "src/Ray.h"

class Camera
{
private:
    // TODO: Clean up unused members
    float m_idealAspectRatio = 16.0f / 9.0f;
    uint32_t m_imageWidth;
    uint32_t m_imageHeight;
    float m_viewportWidth;
    float m_viewportHeight;
    Vec3 m_pixelDelta_U;
    Vec3 m_pixelDelta_V;
    Point3 m_pixel00Loc;

public:
    Point3 center;  // aka "Eye point"
    float focalLength;  // distance from center to the viewport center

public:
    Camera(uint32_t width);
    Ray GetRay(uint32_t row, uint32_t col, const Point3& origin) const;
    uint32_t GetWidth() const;
    uint32_t GetHeight() const;
    Point3 GetFirstPixelLoc() const;
    Vec3 GetPixelDelta_U() const;
    Vec3 GetPixelDelta_V() const;
};