#include<SFML/Audio.hpp>
#include<iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "entete/life.h"
#include "entete/card.h"
#include "entete/Deck.h"
#include "entete/Floor.h"
#include "entete/ennemi.h"
using namespace std;
using namespace sf;

#ifndef __Player_h__
#define __Player_h__

class Player: public sf::Transformable, public sf::Drawable{
private:
  life joueur_life;
  std::string class_player="None";
  sf::Texture skin;
  sf::Sprite joueur;
  std::vector<Card> deck_Plateformer;
  Deck deck_fight;
  std::vector<Card> Hand;
  std::vector<Card> GY;
  std::vector<Card> Defausse;
  sf::RectangleShape glob;
  bool isInFight=false;
public:
  Player();
  void initialiseLife(int Vie);//initialisation of the life of the player
  void deplacement(Floor & floor); //movement of the player
  void move(sf::Vector2f distance); //move of the sprite
  sf::Vector2f getPosition(); //return the position of the player
  void setClassType(string classType/*,carddata & allcards*/); //define the class type
  void setPosition(sf::Vector2f Pos); //define the position of the player
  sf::FloatRect getGlobalBounds(); // return the global bounds of the player
  virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const; //draw the player
  void Onfight();//put the player in fight
  void Notfight();// put the player in platformer mode
  void EnterBattle(Ennemy & ennemy); // use onfight and not fight when hitting the ennemy
};
#endif
