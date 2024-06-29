#include "Renderer.h"

Renderer::Renderer(uint32_t image_width, uint32_t image_height) :
    m_imageWidth(image_width),
    m_imageHeight(image_height),
    m_outputStream("rt_image.ppm", std::ios::out | std::ios::trunc)
{
    m_outputStream << fmt::format("P3\n");
    m_outputStream << fmt::format("{} {}\n", image_width, image_height);
    m_outputStream << fmt::format("255\n");
}

void Renderer::DrawPixel(const Color& color)
{
    m_outputStream << fmt::format("{} {} {}\n", color.r, color.g, color.b);
}

Renderer::~Renderer()
{
    m_outputStream.close();
}