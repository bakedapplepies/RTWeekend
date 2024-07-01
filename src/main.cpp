#include "src/pch/pch.h"
#include "src/Application.h"

int main()
{
    Application application;
    application.Run();
    application.Shutdown();

    // Converts output from .ppm to .png
    // fstream in Renderer has to be closed before executing this command.
    system("ffmpeg -i rt_image.ppm rt_image.png -y -hide_banner -loglevel error");
    fmt::print("Converted rt_image.ppm into rt_image.png.");
}
