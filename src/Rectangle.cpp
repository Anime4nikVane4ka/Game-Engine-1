#include "Rectangle.h"
#include <iostream>

//Rectangle::Rectangle(sf::Vector2f size)
//{
//    _rectangle = sf::RectangleShape(size);
//}
Rectangle::Rectangle(const std::filesystem::path& texturePath): _texture(texturePath), _sprite(_texture)
{
}

void Rectangle::ReverseMove() 
{
    _xSpeed *= -1.0f;
    _ySpeed *= -1.0f;
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


void Rectangle::Update()
{
    //_rectangle.setFillColor(sf::Color(_color[0]*255, _color[1]*255, _color[2]*255));
    _sprite.setColor(sf::Color(
        static_cast<std::uint8_t>(_color[0] * 255),
        static_cast<std::uint8_t>(_color[1] * 255),
        static_cast<std::uint8_t>(_color[2] * 255)
    ));
    _sprite.setPosition({ _sprite.getPosition().x + _xSpeed, _sprite.getPosition().y + _ySpeed});
}

void Rectangle::SetPosition(const sf::Vector2f position)
{
    _sprite.setPosition(position);
}

void Rectangle::SetScale(const sf::Vector2f scale)
{
    _sprite.setScale(scale);
}