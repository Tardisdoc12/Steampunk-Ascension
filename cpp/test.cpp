#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<iostream>
using namespace std;
using namespace sf;


class TileMap : public sf::Drawable, public sf::Transformable
{
public:

    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
    {
        // on charge la texture du tileset
        if (!m_tileset.loadFromFile(tileset)){
            return false;
        }
        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(width * height * 4);

        // on remplit le tableau de vertex, avec un quad par tuile
        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
                // on récupère le numéro de tuile courant
                int tileNumber = tiles[i + j * width];
                if (tileNumber==166){
                  continue;
                }
                else{
                  // on en déduit sa position dans la texture du tileset
                  int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
                  int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

                  // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                  sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

                  // on définit ses quatre coins
                  quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                  quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                  quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                  quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                  // on définit ses quatre coordonnées de texture
                  quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                  quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                  quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                  quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
                }
            }

        return true;
    }

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // on applique la transformation
        states.transform *= getTransform();

        // on applique la texture du tileset
        states.texture = &m_tileset;

        // et on dessine enfin le tableau de vertex
        target.draw(m_vertices, states);
    }

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};

int main()
{
    // on crée la fenêtre
    sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");
    sf::View view1(sf::FloatRect(0, 0, 288, 160));
    window.setView(view1);
    // on définit le niveau à l'aide de numéro de tuiles
    const int level[] =
    {
        15, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,13,
        15, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,13,
        15, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,13,
        15, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,13,
        15, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,13,
        15, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,13,
        15, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,166, 13,
        15, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,166, 13,
        15, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,166, 13,
        44, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 45,
    };

    // on crée la tilemap avec le niveau précédemment défini
    TileMap map;
    if (!map.load("../Sprite/tileset.png", sf::Vector2u(16, 16), level, 18, 10))
        return -1;

    // on fait tourner la boucle principale
    while (window.isOpen())
    {
        // on gère les évènements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        // on dessine le niveau
        window.clear();
        window.draw(map);
        window.display();
    }

    return 0;
}
