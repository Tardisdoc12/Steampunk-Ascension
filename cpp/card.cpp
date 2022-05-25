#include "card.h"

Card::Card(){
  if(!skin.loadFromFile("../Sprite/card.png")){
    cout<<"IMAGE_LOAD_FAILED"<<endl;
  }
  Card_skin.setTexture(skin);
  Card_skin.setOrigin(Card_skin.getLocalBounds().width/2,Card_skin.getLocalBounds().height/2);
  Card_skin.setScale({1/2.f,1/2.f});
  if (!font.loadFromFile("../Font/test.ttf")){
    cout<<"FONT_LOAD_FAILED"<<endl;
  }
  name.setFont(font);
  Description.setFont(font);
  Mana.setFont(font);
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
  target.draw(Mana);
  target.draw(Description);
  target.draw(name);
}


int Card::cost(){
  string mana = Mana.getString();
  return std::stoi(mana);
}

void Card::setMana(std::string mana){
  Mana.setString(mana);
  Mana.setCharacterSize(20);
  Mana.setFillColor(sf::Color::Black);
  Mana.setPosition(this->getX()-Card_skin.getGlobalBounds().width/2,this->getY()-Card_skin.getGlobalBounds().height/2); //We need to modify the position after
}

void Card::move(sf::Vector2f distance){
  Card_skin.move(distance);
  imageSprite.move(distance);
  Mana.move(distance);
  name.move(distance);
  Description.move(distance);
}

sf::FloatRect Card::getGlobalBounds(){
  return Card_skin.getGlobalBounds();
}

void Card::setDescription(std::string desc){
  Description.setString(desc);
  Description.setCharacterSize(12);
  Description.setFillColor(sf::Color::Black);
  Description.setPosition(this->getX(),this->getY()+15.f);
}

void Card::setName(std::string nom){
  name.setString(nom);
  name.setCharacterSize(20);
  name.setFillColor(sf::Color::Black);
  name.setOrigin(name.getLocalBounds().width/2,name.getLocalBounds().height/2);
  name.setPosition(this->getX()-name.getLocalBounds().width/2,this->getY());
}

void Card::setPosition(sf::Vector2f pos){
  Card_skin.setPosition(pos);
  imageSprite.setPosition(pos);
  Description.setPosition(this->getX()-Card_skin.getLocalBounds().width*0.2f-5.f,this->getY()+20.f);
  name.setPosition(this->getX(),this->getY()-30.f);
  Mana.setPosition(this->getX()-Card_skin.getGlobalBounds().width/2+15.f,this->getY()-Card_skin.getGlobalBounds().height/2+10.f);
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

void Card::setType(std::string type){
  if (type=="1"){
    if(!skin.loadFromFile("../Sprite/card_mana2.png")){
      cout<<"IMAGE_LOAD_FAILED"<<endl;
    }
    Card_skin.setTexture(skin);
    Card_skin.setOrigin(Card_skin.getLocalBounds().width/2,Card_skin.getLocalBounds().height/2);
  }
  else if (type=="2"){
    if(!skin.loadFromFile("../Sprite/card_neutre.png")){
      cout<<"IMAGE_LOAD_FAILED"<<endl;
    }
    Card_skin.setTexture(skin);
    Card_skin.setOrigin(Card_skin.getLocalBounds().width/2,Card_skin.getLocalBounds().height/2);
  }
  else if (type=="3"){
    if(!skin.loadFromFile("../Sprite/card_spell2.png")){
      cout<<"IMAGE_LOAD_FAILED"<<endl;
    }
    Card_skin.setTexture(skin);
    Card_skin.setOrigin(Card_skin.getLocalBounds().width/2,Card_skin.getLocalBounds().height/2);
  }
  else if (type=="0"){
    if(!skin.loadFromFile("../Sprite/card.png")){
      cout<<"IMAGE_LOAD_FAILED"<<endl;
    }
    Card_skin.setTexture(skin);
    Card_skin.setOrigin(Card_skin.getLocalBounds().width/2,Card_skin.getLocalBounds().height/2);
  }
}
