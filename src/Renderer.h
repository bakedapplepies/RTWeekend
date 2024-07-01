#pragma once

#include "src/pch/pch.h"
#include "src/Utils.h"

class Renderer
{
private:
    uint32_t m_imageWidth;
    uint32_t m_imageHeight;
    std::fstream m_outputStream;

public:
    Renderer(uint32_t image_width, uint32_t image_height);
    ~Renderer();
    void DrawPixel(const Color& color);
};