#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<iostream>
using namespace std;

#ifndef __Floor_h__
#define __Floor_h__
class Floor: public sf::Drawable, public sf::Transformable
{
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    sf::VertexArray m_floor;
    sf::VertexArray m_wall_left;
    sf::VertexArray m_wall_right;
    sf::Vector2u tileSize2;
    sf::FloatRect contour;
    //vector<sf::Sprite> globalBoundary();
public:
    bool load(const std::string& tileset, sf::Vector2u tileSize, vector<int> tiles, unsigned int width, unsigned int height);
    sf::VertexArray return_floor();
    sf::VertexArray return_right();
    sf::VertexArray return_left();
    sf::Vector2u getTileSize();
    sf::FloatRect getContour();
};
#endif
