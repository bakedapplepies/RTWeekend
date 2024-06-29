#include "src/pch/pch.h"
#include "Renderer.h"
#include "Utils.h"

int main()
{
    // Renderer
    int imageWidth = 512;
    int imageHeight = 512;
    Renderer renderer(imageWidth, imageHeight);

    for (int row = 0; row < imageHeight; row++)
    {
        std::clog << "\rRemaining scanlines: " << imageHeight - row << ' ' << std::flush;
        for (int col = 0; col < imageWidth; col++)
        {
            Color color;
            double r = double(row) / (imageWidth - 1);
            double g = double(col) / (imageHeight - 1);
            double b = 0.0;

            color.r = uint32_t(255.999 * r);
            color.g = uint32_t(255.999 * g);
            color.b = uint32_t(255.999 * b);

            renderer.DrawPixel(color);
        }
    }
    std::clog << "\rDone.                     " << '\n';
}
