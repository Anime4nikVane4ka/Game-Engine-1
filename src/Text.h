#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "RenderObject.h"

class Text : public RenderObject
{
    sf::Font _font; 

    sf::Text _text = sf::Text(_font);

    void Transfer(const Text& other);
public:
    Text() = default;
    Text(const Text &other);
    Text(Text &&other);
    Text(const std::filesystem::path& fontPath, const sf::String text, const int fontSize);

    const int GetCharacterSize() const;
    void SetPosition(const sf::Vector2f position) override;  

    void Draw(sf::RenderTarget& target) override;
    void Update(const sf::Vector2u& windowSize) override;
    
    Text& operator =(const Text &other);
    Text& operator =(Text &&other);
};

#endif //TEXT_H