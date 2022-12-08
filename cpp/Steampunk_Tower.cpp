#include<SFML/Audio.hpp>
#include<iostream>
#include<SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "entete/life.h"
#include "entete/ennemi.h"
#include "entete/Player.h"
#include "entete/allcard.h"
#include "entete/map_generator.h"
#include "entete/Floor.h"
#include "entete/view.h"
using namespace std;
using namespace sf;

int main(){
  srand(static_cast<unsigned int>(time(NULL)));
  float gamewidth=sf::VideoMode::getDesktopMode().width;
  float gameheight=sf::VideoMode::getDesktopMode().height;
  RenderWindow window;
  window.create(sf::VideoMode(gamewidth,gameheight), "Steampunk Tower", Style::Titlebar|sf::Style::Resize|sf::Style::Close);
  window.setVerticalSyncEnabled(true);

  sf::Vector2f center({9*16.f, 15*16.f});
  sf::Vector2f size({18*16.f,10*16.f});
  sf::Vector2u TileSize({16,16});
  camera game(size,center,TileSize,window);


  Ennemy Op(90);
  Op.setScale({0.3f,0.3f});
  Op.setPosition({200.f,300.f});

  std::string file="C:/Users/laure/Desktop/Steampunk_Ascension/DataBase/Data.txt";
  allcard test(file);
  if(!test.load(file)){
      return -1;
  }
  test.setPosition(sf::Vector2f({200.f,500.f}));
  Player moi;
  moi.setClassType("scientist"/*,test*/);
  moi.initialiseLife(90);
  moi.setPosition({50.f,16*9.f});


  MapGenerator floor_1(1);
  floor_1.generate_floor();
  vector<int> intermediaire_floor=floor_1.return_floor();
  Floor map;
  map.setPosition(0,0);
  if (!map.load("C:/Users/laure/Desktop/Steampunk_Ascension/Sprite/tileset.png", sf::Vector2u(16, 16), intermediaire_floor, 18*floor_1.return_n_room(), 30)){
    return -1;
  }

  while(window.isOpen()){
    Event event;
    while(window.pollEvent(event)){
      if ((event.type == sf::Event::Closed) ||  ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))){
	      window.close();
        break;
      }
    }
    moi.deplacement(map);
    test.draganddrop(window);
    test.agrandisouris(window);
    test.always();
    game.move_cam(moi,map);
    window.clear(Color::Black);
    window.draw(moi);
    window.draw(map);
    window.draw(Op);
    test.draw(window);
    window.display();
  }
  return EXIT_FAILURE;
}
