#include "Player.h"

Player::Player(){
  isInFight=false;
  if(!skin.loadFromFile("../Sprite/test1.jpg")){
    cout<<"ERROR_FAIL"<<endl;
  }
  joueur.setTexture(skin);
  joueur.setOrigin(joueur.getLocalBounds().width/2,joueur.getLocalBounds().height/2);
  joueur.setScale({0.3f,0.3f});
}

void Player::initialiseLife(int Vie){
  joueur_life.initialise(Vie);
}

void Player::deplacement(){
  if (!isInFight){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
      joueur.move({0.f,-3.5f});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
      joueur.move({-3.5f,0.f});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
      joueur.move({3.5f,0.f});
    }
  }
}

void Player::setPosition(sf::Vector2f Pos){
  joueur.setPosition(Pos);
  joueur_life.setPosition({joueur.getPosition().x-float(joueur.getGlobalBounds().width*0.36f),float(joueur.getPosition().y+joueur.getGlobalBounds().height*0.6)});
}


void Player::draw(sf::RenderTarget & target,sf::RenderStates state) const{
  //state.transform *= getTransform();
  target.draw(joueur,state);
  if (isInFight){
    target.draw(joueur_life);
  }
}

void Player::Onfight(){
  isInFight=true;
}

void Player::Notfight(){
  isInFight=false;
}

void Player::setClassType(std::string classType){
  //deck_fight.createDeck(classType);
  //set the skin of the right class
  //set the mana of the class
}
