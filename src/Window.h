#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "imgui.h"
#include "imgui-SFML.h"

#include "Rectangle.h"
#include "Text.h"
#include "gui.h"

class Window {
    sf::RenderWindow _window;

    sf::Clock _deltaClock;

    bool _isRun;

    std::shared_ptr<Rectangle> _rect;
    std::shared_ptr<Text> _text;
    std::shared_ptr<GUI> _gui;

    void Initialize();

    void UpdateUserInput();
    void UpdateLogic();
    void UpdateGui();
    void Render();

public:
    Window(const unsigned int wWidth, const unsigned int wHeight);
    
    void Run();
};

#endif //WINDOW_H
