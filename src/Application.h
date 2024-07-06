#pragma once

#include "src/pch/pch.h"
#include "src/Camera.h"
#include "src/Renderer.h"

class Application
{
private:
    std::unique_ptr<Renderer> m_renderer;
    Camera m_camera;

    uint32_t m_samplesPerPixel;

public:
    Application();
    void Run();
    void Shutdown();
};