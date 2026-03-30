#include "Window.h"
#include "Config.h"

int main()
{
    setlocale(LC_ALL, "");
    setlocale(LC_NUMERIC, "C");
    Config config("../config.txt");
    // Вам нужно будет считать данные значения из конфига
    //const int wWidth = 1280;
    //const int wHeight = 720;
    Window window(config.getInt("window_width"), config.getInt("window_height"));
    window.Run();

    return 0;
}