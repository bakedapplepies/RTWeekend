#include "Camera.h"
#include "src/Random.h"

Camera::Camera(uint32_t width) :
    m_imageWidth(width)
{
    focalLength = 1.0f;
    center = Point3(0.0f);

    m_imageHeight = uint32_t(m_imageWidth / m_idealAspectRatio);
    m_imageHeight = std::max(m_imageHeight, 1u);

    m_viewportHeight = 2.0f;
    m_viewportWidth = m_viewportHeight * (static_cast<float>(m_imageWidth) / static_cast<float>(m_imageHeight));

    Vec3 viewport_U = Vec3(m_viewportWidth, 0.0f, 0.0f);
    Vec3 viewport_V = Vec3(0.0f, -m_viewportHeight, 0.0f);

    m_pixelDelta_U = viewport_U / static_cast<float>(m_imageWidth);
    m_pixelDelta_V = viewport_V / static_cast<float>(m_imageHeight);

    Point3 viewportUpperLeft = center
                        - Vec3(0.0f, 0.0f, focalLength)  // Note: Using right-handed coords
                        - viewport_U / 2.0f - viewport_V / 2.0f;  // v-component is reversed due to reversed y
    m_pixel00Loc = viewportUpperLeft + 0.5f * (m_pixelDelta_U + m_pixelDelta_V);
}

Ray Camera::GetRay(uint32_t row, uint32_t col, const Point3& origin) const
{
    Vec3 offset = Vec3(Random::Float() - 0.5f, Random::Float() - 0.5f, 0.0f);
    Point3 pixelCenter = m_pixel00Loc
                       + static_cast<float>(col + offset.x) * m_pixelDelta_U
                       + static_cast<float>(row + offset.y) * m_pixelDelta_V;
    
    Vec3 rayDirection = pixelCenter - origin;
    return Ray(origin, rayDirection);
}

uint32_t Camera::GetWidth() const
{
    return m_imageWidth;
}

uint32_t Camera::GetHeight() const
{
    return m_imageHeight;
}

Point3 Camera::GetFirstPixelLoc() const
{
    return m_pixel00Loc;
}

Vec3 Camera::GetPixelDelta_U() const
{
    return m_pixelDelta_U;
}

Vec3 Camera::GetPixelDelta_V() const
{
    return m_pixelDelta_V;
}