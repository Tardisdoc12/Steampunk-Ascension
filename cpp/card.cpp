#include "card.h"

Card::Card(){
  if(!skin.loadFromFile("../Sprite/card.png")){
    cout<<"IMAGE_LOAD_FAILED"<<endl;
  }
  Card_skin.setTexture(skin);
  Card_skin.setOrigin(Card_skin.getLocalBounds().width/2,Card_skin.getLocalBounds().height/2);
  Card_skin.setScale({1/2.f,1/2.f});
}

void Card::setImage(std::string path_to_image){
  if(!image.loadFromFile(path_to_image)){
    cout<<"ERROR_FAIL"<<endl;
  }
  imageSprite.setTexture(image);
}

float Card::getX(){
  return Card_skin.getPosition().x;
}

float Card::getY(){
  return Card_skin.getPosition().y;
}

void Card::draw(sf::RenderTarget & target, sf::RenderStates states) const{
  target.draw(imageSprite);
  target.draw(Card_skin);
}

int Card::cost(){
  string mana = Mana.getString();
  return std::stoi(mana);
}

void Card::setMana(std::string mana){
  Mana.setString(mana);
  Mana.setCharacterSize(20);
  Mana.setFillColor(sf::Color::Black);
  Mana.setPosition(this->getX(),this->getY()); //We need to modify the position after
}

void Card::move(sf::Vector2f distance){
  Card_skin.move(distance);
  imageSprite.move(distance);
}

sf::FloatRect Card::getGlobalBounds(){
  return Card_skin.getGlobalBounds();
}

void Card::setDescription(std::string desc){
  Description.setString(desc);
  Description.setCharacterSize(7);
  Description.setFillColor(sf::Color::Black);
  Description.setPosition(this->getX(),this->getY());
}

void Card::setName(std::string nom){
  name.setString(nom);
  name.setCharacterSize(20);
  name.setFillColor(sf::Color::Black);
  name.setOrigin(name.getLocalBounds().width/2,name.getLocalBounds().height/2);
  name.setPosition(this->getX(),this->getY());
}

void Card::setPosition(sf::Vector2f pos){
  Card_skin.setPosition(pos);
  imageSprite.setPosition(pos);
}

void Card::setScale(sf::Vector2f dim){
  Card_skin.setScale(dim);
  imageSprite.setScale(dim);
}


void Card::agrandisouris(sf::RenderWindow & window){
  if (Card_skin.getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x),float(sf::Mouse::getPosition(window).y))){
    if((!drag)&&(!agrandi)){
        agrandi=true;
        this->move({0.f,-10.f});
    }
    else if(drag){
      agrandi=false;
    }
  }
  else{
    if (agrandi){
      agrandi=false;
      this->move({0.f,10.f});
    }
  }
}


void Card::dragAndDrop(sf::RenderWindow & window){
  if((sf::Mouse::isButtonPressed(sf::Mouse::Left))&&(this->getGlobalBounds().contains(float(sf::Mouse::getPosition(window).x),float(sf::Mouse::getPosition(window).y)))){
    if(!drag){
      drag=true;
    }
  }
  else{
    if(drag){
      drag=false;
    }
  }
}

void Card::follow(sf::RenderWindow & window){
  if(drag){
    this->setPosition({float(sf::Mouse::getPosition(window).x),float(sf::Mouse::getPosition(window).y)});
  }
}

string Card::getName(){
  return this->name.getString();
}
