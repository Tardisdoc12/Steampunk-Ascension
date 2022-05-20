#include "ennemi.h"


Ennemy::Ennemy(int ptDeVie){
  ennemi_life.initialise(ptDeVie);
  if(!im.loadFromFile("../Sprite/ennemy3.png")){
    cout<<"ERROR_FAIL"<<endl;
  }
  ennemi.setTexture(im);
  ennemi.setScale({0.8f,0.8f});
  ennemi.setOrigin({ennemi.getLocalBounds().width/2,ennemi.getLocalBounds().height/2});
  ennemi_life.setPosition({ennemi.getLocalBounds().width/2,float(ennemi.getLocalBounds().height*0.5f)});
}

void Ennemy::setPosition(sf::Vector2f Pos){
  ennemi.setPosition(Pos);
  ennemi_life.setPosition({ennemi.getPosition().x-float(ennemi.getGlobalBounds().width*0.36f),float(ennemi.getPosition().y+ennemi.getGlobalBounds().height*0.6)});
}

void Ennemy::setScale(sf::Vector2f Taille){
  ennemi.setScale(Taille);
}

void Ennemy::draw(sf::RenderTarget & target,sf::RenderStates states) const{
  states.transform *= getTransform();
  target.draw(ennemi,states);
  target.draw(ennemi_life);
}
