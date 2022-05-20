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
using namespace std;
using namespace sf;

int main(){
  srand(static_cast<unsigned int>(time(NULL)));
  float gamewidth=sf::VideoMode::getDesktopMode().width;
  float gameheight=sf::VideoMode::getDesktopMode().height;
  RenderWindow window;
  window.create(sf::VideoMode(gamewidth,gameheight), "Steampunk Tower", Style::Titlebar|sf::Style::Resize|sf::Style::Close);
  window.setVerticalSyncEnabled(true);


  Ennemy Op(90);
  Op.setScale({0.3f,0.3f});
  Op.setPosition({500.f,600.f});
  Player moi;
  moi.initialiseLife(90);
  moi.setPosition({300.f,300.f});

  carddata test;
  std::vector<Card> all=test.everyCardReturn();
  for (int h=0;h<test.everyCards.size();h++){
    test.everyCards[h].setPosition({1000.f/2, 900.f/2});
  }

  while(window.isOpen()){
    Event event;
    while(window.pollEvent(event)){
      if ((event.type == sf::Event::Closed) ||  ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))){
	      window.close();
        break;
      }
    }
    moi.deplacement();
    test.draganddrop(window);
    test.agrandisouris(window);
    test.always(window);

    window.clear(Color::Black);
    window.draw(moi);
    window.draw(Op);
    for(int i=0;i<test.everyCards.size();i++){
      window.draw(test.everyCards[i]);
    }
    //window.draw(test);
    window.display();
  }
  return EXIT_FAILURE;
}
