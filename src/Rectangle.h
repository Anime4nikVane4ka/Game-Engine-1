#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SFML/Graphics.hpp>
#include <filesystem>
#include <vector>
#include <string>

class Rectangle
{
    //sf::RectangleShape _rectangle;
    sf::Texture _texture;
    sf::Sprite _sprite;

    // Все дефолтные данные надо будет прочитать из конфигурационного файла
    std::vector<std::filesystem::path> _logoPaths;
    std::vector<std::string> _logoNames;
    int _currentLogoIndex = 0;
    bool _shouldDraw = true;
    float _color[3] = {1.0f, 1.0f, 1.0f}; 

    float _scaleFactor;
    float _xSpeed = 1.0f; 
    float _ySpeed = 0.5f;  

    void LoadLogo(int index);

public:
    Rectangle() = default;
    Rectangle(const std::vector<std::filesystem::path>& logoPaths, int startIndex = 0);

    void ReverseMove();
    float* GetColors();

    int GetCurrentLogoIndex() const;
    void SetCurrentLogoIndex(int index);
    const std::vector<std::string>& GetLogoNames() const;

    float GetSpeedX() const;
    float GetSpeedY() const;
    float GetScaleFactor() const;
    void SetSpeedX(float speed);
    void SetSpeedY(float speed);    
    void SetScaleFactor(float scaleFactor);

    bool& GetShouldDraw();
    void Draw(sf::RenderTarget& target);
    void Update(const sf::Vector2u& windowSize);
    void SetPosition(const sf::Vector2f position);
    void SetScale(const sf::Vector2f scale);
};

#endif //RECTANGLE_H