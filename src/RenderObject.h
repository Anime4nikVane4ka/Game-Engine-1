#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

#include <SFML/Graphics.hpp>

class RenderObject
{
public:
    virtual ~RenderObject();

    virtual void Draw(sf::RenderTarget& target) = 0;
    virtual void Update(const sf::Vector2u& windowSize) = 0;
    virtual void SetPosition(const sf::Vector2f position) = 0;
};

#endif // RENDERABLEOBJECT_H