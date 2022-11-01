#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<iostream>
using namespace std;

#ifndef __Floor_h__
#define __Floor_h__
class Floor : public sf::Drawable, public sf::Transformable
{
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
public:
    bool load(const std::string& tileset, sf::Vector2u tileSize, vector<int> tiles, unsigned int width, unsigned int height);

};
#endif
