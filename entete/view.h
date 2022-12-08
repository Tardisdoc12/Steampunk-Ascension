#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include"entete/Player.h"
#include"entete/Floor.h"

#ifndef __view_h__
#define __view_h__
class camera{
private:
  sf::Vector2f size;
  sf::Vector2f position;
  sf::Vector2f position_initial;
  sf::View room;
  sf::View welcomeScreen;
public:
  camera();
  camera(sf::Vector2f _size,sf::Vector2f _position,sf::Vector2u TileSize,sf::RenderWindow & window);
  void setSize(sf::Vector2f _size);
  void setPosition(sf::Vector2f _position);
  void setEdge(sf::Vector2u TileSize);
  void move_cam(Player & player,Floor& map);

  void setView1(sf::RenderWindow & window);
};
#endif
