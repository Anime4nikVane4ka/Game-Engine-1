#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SFML/Graphics.hpp>
#include <filesystem>
#include <iostream>
#include <vector>
#include <string>
#include "Config.h"
#include "RenderObject.h"

class Rectangle : public RenderObject
{
    sf::Texture _texture;
    sf::Sprite _sprite;

    // Все дефолтные данные надо будет прочитать из конфигурационного файла
    std::vector<std::filesystem::path> _logoPaths;
    std::vector<std::string> _logoNames;
    int _currentLogoIndex;
    bool _shouldDraw;
    float _color[3]; 
    float _scaleFactor;
    float _xSpeed; 
    float _ySpeed;  

    void LoadLogo(int index);

public:
    Rectangle() = default;
    Rectangle(const std::vector<std::filesystem::path>& logoPaths, int startIndex = 0);

    void ReverseMove();
    float* GetColors();

    int GetCurrentLogoIndex() const;
    void SetCurrentLogoIndex(int index);
    std::vector<std::string> GetLogoNames() const;

    float GetSpeedX() const;
    float GetSpeedY() const;
    float GetScaleFactor() const;
    bool GetShouldDraw() const;
    void SetSpeedX(float speed);
    void SetSpeedY(float speed);    
    void SetScaleFactor(float scaleFactor);
    void SetShouldDraw(bool shouldDraw);
    void SetPosition(const sf::Vector2f position) override;
    void SetColor(const sf::Vector3f color);
    
    void Draw(sf::RenderTarget& target) override;
    void Update(const sf::Vector2u& windowSize) override;
    
};

#endif //RECTANGLE_H