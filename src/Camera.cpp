#include "Camera.h"

Camera::Camera(uint32_t width) :
    m_imageWidth(width)
{
    m_imageHeight = uint32_t(m_imageWidth / m_aspectRatio);
    m_imageHeight = std::max(m_imageHeight, 1u);

    m_viewportHeight = 2.0f;
    m_viewportWidth = m_viewportHeight * (float(m_imageWidth) / m_imageHeight);
}

uint32_t Camera::GetWidth() const
{
    return m_imageWidth;
}

uint32_t Camera::GetHeight() const
{
    return m_imageHeight;
}