#include<SFML/Audio.hpp>
#include<iostream>
#include<SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "card.h"
#include "life.h"
#include "ennemi.h"
#include "Player.h"
#include "allcards.h"
#include "map_generator.h"
#include "Floor.h"
#include "view.h"
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

  /*
  Ennemy Op(90);
  Op.setScale({0.3f,0.3f});
  Op.setPosition({500.f,600.f});
  */

  carddata test;
  for (int h=0;h<test.everyCards.size();h++){
    test.everyCards[h].setPosition({100.f+150.f*h, 900.f/2});
  }

  Player moi;
  moi.setClassType("scientist",test);
  moi.initialiseLife(90);
  moi.setPosition({50.f,16*9.f});


  MapGenerator floor_1(3);
  floor_1.generate_floor();
  vector<int> intermediaire_floor=floor_1.return_floor();
  Floor map;
  map.setPosition(0,0);
  if (!map.load("../Sprite/tileset.png", sf::Vector2u(16, 16), intermediaire_floor, 18*floor_1.return_n_room(), 30)){
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
    test.always(window);
    game.move_cam(moi,map);
    window.clear(Color::Black);
    window.draw(moi);
    //window.draw(Op);
    for(int i=0;i<test.everyCards.size();i++){
      window.draw(test.everyCards[i]);
    }
    window.draw(map);
    game.setView1(window);
    //cout<<"test_3 reussi"<<endl;
    window.display();
  }
  return EXIT_FAILURE;
}
