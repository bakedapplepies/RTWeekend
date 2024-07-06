#include "Application.h"
#include "src/Scene.h"
#include "src/shapes/Sphere.h"

Application::Application() :
    m_camera(1024)
{
    m_renderer = std::make_unique<Renderer>(
        m_camera.GetWidth(),
        m_camera.GetHeight()
    );

    m_samplesPerPixel = 10;
}

void Application::Run()
{
    // Renderer
    uint32_t imageWidth = m_camera.GetWidth();
    uint32_t imageHeight = m_camera.GetHeight();
    Point3 firstPixelLoc = m_camera.GetFirstPixelLoc();
    Vec3 pixelDelta_U = m_camera.GetPixelDelta_U();
    Vec3 pixelDelta_V = m_camera.GetPixelDelta_V();

    Scene scene;
    scene.AddObj<Sphere>(Point3(0.0f, 0.0f, -1.0f), 0.5f);
    scene.AddObj<Sphere>(Point3(0.0f, -100.5f, -1.0f), 100.0f);

    for (uint32_t row = 0; row < imageHeight; row++)
    {
        fmt::print("\rRemaining scanlines: {}", imageHeight - row);
        for (uint32_t col = 0; col < imageWidth; col++)
        {
            Color pixelColor(0.0f, 0.0f, 0.0f);
            
            for (uint32_t sample = 0; sample < m_samplesPerPixel; sample++)
            {
                Ray ray = m_camera.GetRay(row, col, m_camera.center);
                pixelColor += m_renderer->GetRayColor(ray, scene);
            }

            pixelColor /= m_samplesPerPixel;
            m_renderer->DrawPixel(pixelColor);
        }
    }
    fmt::print("\rImage rendered.                     \n");
}

void Application::Shutdown()
{
    m_renderer.reset();
}