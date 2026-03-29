#include "Rectangle.h"
#include <iostream>

//Rectangle::Rectangle(sf::Vector2f size)
//{
//    _rectangle = sf::RectangleShape(size);
//}
Rectangle::Rectangle(const std::vector<std::filesystem::path>& logoPaths, int startIndex):
_logoPaths(logoPaths),
_texture(logoPaths[startIndex]),
_sprite(_texture),
_currentLogoIndex(startIndex)
{
    for (const auto& path : _logoPaths)
        _logoNames.push_back(path.filename().string());
}

void Rectangle::LoadLogo(int index)
{
    _texture.loadFromFile(_logoPaths[index]);
    _sprite.setTexture(_texture, true);   // важно: сбросить rect под новый размер
    _currentLogoIndex = index;
}


void Rectangle::ReverseMove() 
{
    _xSpeed *= -1.0f;
    _ySpeed *= -1.0f;
}

float Rectangle::GetSpeedX() const
{
    return _xSpeed;
}

void Rectangle::SetSpeedX(float speed)
{
    _xSpeed = speed;
}

float Rectangle::GetSpeedY() const
{
    return _ySpeed;
}

void Rectangle::SetSpeedY(float speed)
{
    _ySpeed = speed;
}

float Rectangle::GetScaleFactor() const
{
    return _scaleFactor;
}

void Rectangle::SetScaleFactor(float scale) 
{
    _scaleFactor = scale;
    _sprite.setScale({_scaleFactor, _scaleFactor });
}

int Rectangle::GetCurrentLogoIndex() const
{
    return _currentLogoIndex;
}

void Rectangle::SetCurrentLogoIndex(int index)
{
    LoadLogo(index);
}

const std::vector<std::string>& Rectangle::GetLogoNames() const
{
    return _logoNames;
}

float* Rectangle::GetColors()
{
    return _color;
}

bool& Rectangle::GetShouldDraw()
{
    return _shouldDraw;
}

void Rectangle::Draw(sf::RenderTarget& target)
{
    if (_shouldDraw)
        target.draw(_sprite);
}


void Rectangle::Update(const sf::Vector2u& windowSize)
{
    //_rectangle.setFillColor(sf::Color(_color[0]*255, _color[1]*255, _color[2]*255));
    _sprite.setColor(sf::Color(_color[0] * 255, _color[1] * 255, _color[2] * 255));

    sf::Vector2f pos = _sprite.getPosition();
    pos.x += _xSpeed;
    pos.y += _ySpeed;
    sf::FloatRect bounds = _sprite.getGlobalBounds();

    // Отражение от левой / правой стены
    if (pos.x <= 0.0f)
    {
        pos.x = 0;
        _xSpeed *= -1.0f;
    }
    else if (pos.x + bounds.size.x >= windowSize.x)
    {
        pos.x = windowSize.x - bounds.size.x;
        _xSpeed *= -1.0f;
    }

    // Отражение от верхней / нижней стены
    if (pos.y <= 0.0f)
    {
        pos.y = 0;
        _ySpeed *= -1.0f;
    }
    else if (pos.y + bounds.size.y >= windowSize.y)
    {
        pos.y = windowSize.y - bounds.size.y;
        _ySpeed *= -1.0f;
    }
    //std::cout << "Top left: " << pos.x << ", " << pos.y << std::endl;
    //std::cout << "Down right : " << pos.x + bounds.size.x << ", " << pos.y + bounds.size.y << std::endl;
    //std::cout << "*****************" << std::endl;
    //std::cout << "Size : " <<bounds.size.x << ", " << bounds.size.y << std::endl;
    //std::cout << windowSize.x << ", " << windowSize.y << std::endl;

    _sprite.setPosition(pos);
}

void Rectangle::SetPosition(const sf::Vector2f position)
{
    _sprite.setPosition(position);
}