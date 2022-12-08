#include"entete/Floor.h"
using namespace sf;
bool Floor::load(const std::string& tileset, sf::Vector2u tileSize, vector<int> tiles, unsigned int width, unsigned int height){
  // on charge la texture du tileset
  tileSize2=tileSize;
  if (!m_tileset.loadFromFile(tileset)){
      return false;
  }
  // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
  m_vertices.setPrimitiveType(sf::Quads);
  m_vertices.resize(width * height * 4);
  m_floor.setPrimitiveType(sf::Quads);
  // on remplit le tableau de vertex, avec un quad par tuile
  for (unsigned int i = 0; i < width; ++i){
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
            if((tileNumber==25) || (tileNumber==26) || (tileNumber==27)){
              sf::Vertex test_1;
              sf::Vertex test_2;
              sf::Vertex test_4;
              sf::Vertex test_3;
              test_1.position = sf::Vector2f(i * tileSize.x, j * tileSize.y);//quad[0].position;
              test_2.position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);//quad[1].position;
              test_3.position = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);//quad[2].position;
              test_4.position = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);//quad[3].position;
              test_1.texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
              test_2.texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
              test_3.texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
              test_4.texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
              m_floor.append(test_1);
              m_floor.append(test_2);
              m_floor.append(test_3);
              m_floor.append(test_4);
            }
            if((tileNumber==13) || (tileNumber==39)){
              sf::Vertex test_1;
              sf::Vertex test_2;
              sf::Vertex test_4;
              sf::Vertex test_3;
              test_1.position = sf::Vector2f(i * tileSize.x, j * tileSize.y);//quad[0].position;
              test_2.position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);//quad[1].position;
              test_3.position = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);//quad[2].position;
              test_4.position = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);//quad[3].position;
              test_1.texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
              test_2.texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
              test_3.texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
              test_4.texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
              m_wall_right.append(test_1);
              m_wall_right.append(test_2);
              m_wall_right.append(test_3);
              m_wall_right.append(test_4);
            }
            if((tileNumber==15) || (tileNumber==39)){
              sf::Vertex test_1;
              sf::Vertex test_2;
              sf::Vertex test_4;
              sf::Vertex test_3;
              test_1.position = sf::Vector2f(i * tileSize.x, j * tileSize.y);//quad[0].position;
              test_2.position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);//quad[1].position;
              test_3.position = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);//quad[2].position;
              test_4.position = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);//quad[3].position;
              test_1.texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
              test_2.texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
              test_3.texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
              test_4.texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
              m_wall_left.append(test_1);
              m_wall_left.append(test_2);
              m_wall_left.append(test_3);
              m_wall_left.append(test_4);
            }
          }
      }
  }
  contour.top=0.f;
  contour.left=0.f;
  contour.width=width;
  contour.height=height;
  return true;
}

sf::FloatRect Floor::getContour(){
  return contour;
}
void Floor::draw(sf::RenderTarget& target, sf::RenderStates states) const{
  // on applique la transformation
  states.transform *= getTransform();

  // on applique la texture du tileset
  states.texture = &m_tileset;

  // et on dessine enfin le tableau de vertex
  target.draw(m_vertices, states);
}


sf::Vector2u Floor::getTileSize(){
  return tileSize2;
}
sf::VertexArray Floor::return_floor(){
  return m_floor;
}
sf::VertexArray Floor::return_right(){
  return m_wall_right;
}
sf::VertexArray Floor::return_left(){
  return m_wall_left;
}
