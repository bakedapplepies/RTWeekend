#include "Application.h"

Application::Application() :
    m_camera(512)
{
    m_renderer = std::make_unique<Renderer>(
        m_camera.GetWidth(),
        m_camera.GetHeight()
    );
}

void Application::Run()
{
    // Renderer
    uint32_t imageWidth = m_camera.GetWidth();
    uint32_t imageHeight = m_camera.GetHeight();

    for (uint32_t row = 0; row < imageHeight; row++)
    {
        fmt::print("\rRemaining scanlines: {}", imageHeight - row);
        for (uint32_t col = 0; col < imageWidth; col++)
        {
            Color color;
            float r = float(col) / (imageWidth - 1u);
            float g = float(row) / (imageHeight - 1u);
            float b = 0.0;

            color.r = uint32_t(255.999f * r);
            color.g = uint32_t(255.999f * g);
            color.b = uint32_t(255.999f * b);

            m_renderer->DrawPixel(color);
        }
    }
    fmt::print("\rDone.                     \n");
}

void Application::Shutdown()
{
    m_renderer.reset();
}