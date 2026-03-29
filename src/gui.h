#ifndef GUI_H
#define GUI_H

#include "imgui.h"
#include "Rectangle.h"

class GUI
{
public:
    GUI() = default;

    void Draw(Rectangle& rect);
    float CheckNegative(float speed);
};

#endif // GUI_H