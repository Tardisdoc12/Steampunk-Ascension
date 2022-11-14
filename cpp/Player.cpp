#include "Player.h"
#include "allcards.h"
#include "Deck.h"
#include "Floor.h"
#include "collision.h"
Player::Player(){
  isInFight=false;
  if(!skin.loadFromFile("../Sprite/test1.jpg")){
    cout<<"ERROR_FAIL"<<endl;
  }
  joueur.setTexture(skin);
  joueur.setOrigin(joueur.getLocalBounds().width/2,joueur.getLocalBounds().height/2);
  joueur.setScale({0.01f,0.01f});
  //glob.setPosition(joueur.getGlobalBounds();
}

void Player::initialiseLife(int Vie){
  joueur_life.initialise(Vie);
}


void Player::deplacement(Floor & floor){
  if (!isInFight){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
      joueur.move({0.f,-6.5f});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
      if(!Collision::collision(floor.return_left(),joueur,floor.getTileSize())){
          joueur.move({-3.5f,0.f});
      }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
      if(!Collision::collision(floor.return_right(),joueur,floor.getTileSize())){
          joueur.move({3.5f,0.f});
      }
    }
    if(!Collision::collision(floor.return_floor(),joueur,floor.getTileSize())){
      joueur.move({0.f,3.5f});
    }
  }
}


sf::FloatRect Player::getGlobalBounds(){
  return joueur.getGlobalBounds();
}

void Player::move(sf::Vector2f distance){
  joueur.move(distance);
}

sf::Vector2f Player::getPosition(){
  return joueur.getPosition();
}

void Player::setPosition(sf::Vector2f Pos){
  joueur.setPosition(Pos);
  joueur_life.setPosition({joueur.getPosition().x-float(joueur.getGlobalBounds().width*0.36f),float(joueur.getPosition().y+joueur.getGlobalBounds().height*0.6)});
}

void Player::draw(sf::RenderTarget & target,sf::RenderStates state) const{
  //state.transform *= getTransform();
  target.draw(joueur,state);
  //target.draw(glob);
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

void Player::setClassType(std::string classType,carddata & allcards){
  deck_fight.createDeck(classType,allcards);
  //set the skin of the right class
  //set the mana of the class
}
