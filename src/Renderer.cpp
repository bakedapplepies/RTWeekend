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
    static const Interval intensity(0.0f, 1.0f);
    m_outputStream << fmt::format("{} {} {}\n",
        static_cast<uint32_t>(intensity.Clamp(color.r) * 255.999f),
        static_cast<uint32_t>(intensity.Clamp(color.g) * 255.999f),
        static_cast<uint32_t>(intensity.Clamp(color.b) * 255.999f)
    );
}

Color Renderer::GetRayColor(const Ray& ray, const Scene& scene) const
{
    HitRecord record;
    if (scene.HasHit(ray, Interval(0.0f, FLOAT_INF), record))
    {
        Vec3 normal = record.normal;
        return 0.5f * Color(normal.x + 1.0f, normal.y + 1.0f, normal.z + 1.0f);
    }

    Vec3 unitDirection = glm::normalize(ray.GetDirection());
    float a = 0.5f * (unitDirection.y + 1.0f);  // map [-1.0 - 1.0] to [0.0 - 1.0]
    return (1.0f - a) * Color(1.0f) + a * Color(0.5f, 0.7f, 1.0f);  // lerp
}

Renderer::~Renderer()
{
    m_outputStream.close();
}