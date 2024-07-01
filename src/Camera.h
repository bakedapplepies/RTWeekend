#pragma once

class Camera
{
private:
    float m_aspectRatio = 16.0f / 9.0f;
    uint32_t m_imageWidth;
    uint32_t m_imageHeight;
    float m_viewportWidth;
    float m_viewportHeight;

public:
    Camera(uint32_t width);
    uint32_t GetWidth() const;
    uint32_t GetHeight() const;
};