#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<vector>
using namespace std;
using namespace sf;

#ifndef __COLLISION_H__
#define __COLLISION_H__

namespace Collision{
  bool collision_tuile(const sf::Rect<float> & rect,sf::Sprite & joueur);

  bool collision(VertexArray array,Sprite & joueur,sf::Vector2u dim);

  bool collision(sf::FloatRect& sideView,sf::FloatRect joueur);

  bool collision(sf::Sprite ennemy,sf::Sprite & Joueur);
}

#endif
