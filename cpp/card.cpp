#include "card.h"

Card::Card(std::string nom,std::string descr,std::string path_to_image){
  GlobalCard.setPrimitiveType(sf::Quads);
  GlobalCard.resize(4*4);
  sf::Vertex* BackGround= &GlobalCard[0];
  sf::Vertex* Im= &GlobalCard[4];
  sf::Vertex* Effect= &GlobalCard[8];
  sf::Vertex* Name= &GlobalCard[12];
  taille=130.f;
  //on definit le fond de la carte
  BackGround[0].position= sf::Vector2f(0.f,0.f);
  BackGround[1].position=sf::Vector2f(taille,0.f);
  BackGround[2].position=sf::Vector2f(taille,taille*89.f/62);
  BackGround[3].position=sf::Vector2f(0.f,taille*89.f/62);
  BackGround[0].color= sf::Color(126,51,0);
  BackGround[1].color=sf::Color(255,127,0);
  BackGround[2].color= sf::Color(126,51,0);
  BackGround[3].color=sf::Color(255,127,0);
  //on définit le nom de la carte:
  Name[0].position=sf::Vector2f(BackGround[0].position.x+8.f,BackGround[0].position.y+10.f);
  Name[1].position=sf::Vector2f(BackGround[1].position.x-8.f,BackGround[1].position.y+10.f);
  Name[2].position=sf::Vector2f(Name[1].position.x,Name[1].position.y+20.f);
  Name[3].position=sf::Vector2f(Name[0].position.x,Name[0].position.y+20.f);
  //on definit l'image de la carte
  Im[0].position=sf::Vector2f(Name[0].position.x+5.f,Name[0].position.y+30.f);
  Im[1].position=sf::Vector2f(Name[1].position.x-5.f,Name[1].position.y+30.f);
  Im[2].position=sf::Vector2f(Im[1].position.x,Im[1].position.y+60.f);
  Im[3].position=sf::Vector2f(Im[0].position.x,Im[0].position.y+60.f);
  //On definit la zone de l'effet:
  Effect[0].position=sf::Vector2f(Im[0].position.x-5.f,Im[3].position.y+15.f);
  Effect[1].position=sf::Vector2f(Im[2].position.x+5.f,Im[2].position.y+15.f);
  Effect[2].position=sf::Vector2f(Effect[1].position.x,Effect[1].position.y+60.f);
  Effect[3].position=sf::Vector2f(Effect[0].position.x,Effect[0].position.y+60.f);

  if(!font.loadFromFile("../Font/StarshipRegular.otf")){
    cout<<"ERROR_FAIL"<<endl;
  }
  name.setFont(font);
  Description.setFont(font);
  this->setName(nom);
  this->setDescription(descr);
  this->setImage(path_to_image);
  //GlobalCard.setCenter(this->getGlobalBounds().width/2,this->getGlobalBounds().height/2);
  this->setOrigin(this->getGlobalBounds().width/2,this->getGlobalBounds().height/2);
}

Card::Card(){
  GlobalCard.setPrimitiveType(sf::Quads);
  GlobalCard.resize(4*4);
  sf::Vertex* BackGround= &GlobalCard[0];
  sf::Vertex* Im= &GlobalCard[4];
  sf::Vertex* Effect= &GlobalCard[8];
  sf::Vertex* Name= &GlobalCard[12];
  taille=130.f;
  //on definit le fond de la carte
  BackGround[0].position= sf::Vector2f(0.f,0.f);
  BackGround[1].position=sf::Vector2f(taille,0.f);
  BackGround[2].position=sf::Vector2f(taille,taille*89.f/62);
  BackGround[3].position=sf::Vector2f(0.f,taille*89.f/62);
  BackGround[0].color= sf::Color(126,51,0);
  BackGround[1].color=sf::Color(255,127,0);
  BackGround[2].color= sf::Color(126,51,0);
  BackGround[3].color=sf::Color(255,127,0);
  //on définit le nom de la carte:
  Name[0].position=sf::Vector2f(BackGround[0].position.x+8.f,BackGround[0].position.y+10.f);
  Name[1].position=sf::Vector2f(BackGround[1].position.x-8.f,BackGround[1].position.y+10.f);
  Name[2].position=sf::Vector2f(Name[1].position.x,Name[1].position.y+20.f);
  Name[3].position=sf::Vector2f(Name[0].position.x,Name[0].position.y+20.f);
  //on definit l'image de la carte
  Im[0].position=sf::Vector2f(Name[0].position.x+5.f,Name[0].position.y+30.f);
  Im[1].position=sf::Vector2f(Name[1].position.x-5.f,Name[1].position.y+30.f);
  Im[2].position=sf::Vector2f(Im[1].position.x,Im[1].position.y+60.f);
  Im[3].position=sf::Vector2f(Im[0].position.x,Im[0].position.y+60.f);
  //On definit la zone de l'effet:
  Effect[0].position=sf::Vector2f(Im[0].position.x-5.f,Im[3].position.y+15.f);
  Effect[1].position=sf::Vector2f(Im[2].position.x+5.f,Im[2].position.y+15.f);
  Effect[2].position=sf::Vector2f(Effect[1].position.x,Effect[1].position.y+60.f);
  Effect[3].position=sf::Vector2f(Effect[0].position.x,Effect[0].position.y+60.f);

  if(!font.loadFromFile("../Font/StarshipRegular.otf")){
    cout<<"ERROR_FAIL"<<endl;
  }
  name.setFont(font);
  Description.setFont(font);
  this->setOrigin(this->getGlobalBounds().width/2,this->getGlobalBounds().height/2);
}


void Card::setPosition(sf::Vector2f newPos){
  sf::Vertex* BackGround= &GlobalCard[0];
  sf::Vertex* Im= &GlobalCard[4];
  sf::Vertex* Effect= &GlobalCard[8];
  sf::Vertex* Name= &GlobalCard[12];
  BackGround[0].position= sf::Vector2f(newPos.x-coox+0.f,newPos.y-cooy+0.f);
  BackGround[1].position=sf::Vector2f(newPos.x-coox+taille,newPos.y-cooy+0.f);
  BackGround[2].position=sf::Vector2f(BackGround[1].position.x,BackGround[1].position.y+taille*89.f/62);
  BackGround[3].position=sf::Vector2f(BackGround[0].position.x,BackGround[0].position.y+taille*89.f/62);
  Name[0].position=sf::Vector2f(BackGround[0].position.x+8.f,BackGround[0].position.y+10.f);
  Name[1].position=sf::Vector2f(BackGround[1].position.x-8.f,BackGround[1].position.y+10.f);
  Name[2].position=sf::Vector2f(Name[1].position.x,Name[1].position.y+20.f);
  Name[3].position=sf::Vector2f(Name[0].position.x,Name[0].position.y+20.f);
  Im[0].position=sf::Vector2f(Name[0].position.x+5.f,Name[0].position.y+30.f);
  Im[1].position=sf::Vector2f(Name[1].position.x-5.f,Name[1].position.y+30.f);
  Im[2].position=sf::Vector2f(Im[1].position.x,Im[1].position.y+60.f);
  Im[3].position=sf::Vector2f(Im[0].position.x,Im[0].position.y+60.f);
  Effect[0].position=sf::Vector2f(Im[0].position.x-5.f,Im[3].position.y+15.f);
  Effect[1].position=sf::Vector2f(Im[2].position.x+5.f,Im[2].position.y+15.f);
  Effect[2].position=sf::Vector2f(Effect[1].position.x,Effect[1].position.y+60.f);
  Effect[3].position=sf::Vector2f(Effect[0].position.x,Effect[0].position.y+60.f);
  name.setPosition(newPos.x-5.f,newPos.y-78.f);
  Description.setPosition(newPos.x-55.f,newPos.y+22.f);
}

void Card::setDescription(std::string desc){
  Description.setString(desc);
  Description.setCharacterSize(7);
  Description.setFillColor(sf::Color::Black);
  Description.setPosition(this->getX()+8.f,this->getY()+115.f);
}

void Card::setImage(std::string path_to_image){
  if(!skin.loadFromFile(path_to_image)){
    cout<<"ERROR_FAIL"<<endl;
  }
  sf::Vertex* Im= &GlobalCard[4];
  Im[0].texCoords=sf::Vector2f(0.f,0.f);
  Im[1].texCoords=sf::Vector2f(skin.getSize().x,0.f);
  Im[2].texCoords=sf::Vector2f(skin.getSize().x,skin.getSize().y);
  Im[3].texCoords=sf::Vector2f(0.f,skin.getSize().y);
}

void Card::setName(std::string nom){
  name.setString(nom);
  name.setCharacterSize(20);
  name.setFillColor(sf::Color::Red);
  name.setOrigin(name.getLocalBounds().width/2,name.getLocalBounds().height/2);
  name.setPosition(this->getX()-coox+(taille-10.f)/2,this->getY()-cooy+15.f);
}

void Card::setScale(sf::Vector2f dim){
  Card::state.transform.scale(dim,sf::Vector2f(coox+800.f,cooy+700.f));
  //this->setPosition({GlobalCard.getBounds().left,GlobalCard.getBounds().top});
}

void Card::move(sf::Vector2f distance){
  Card::state.transform.translate(coox+distance.x,cooy+distance.y);
}

void Card::setRotation(float angle){
  Card::state.transform.rotate(angle,GlobalCard.getBounds().width/2,GlobalCard.getBounds().height/2);
}

sf::FloatRect Card::getGlobalBounds(){
  return Card::getTransform().transformRect(GlobalCard.getBounds());
}

void Card::setOrigin(float newX,float newY){
  coox=newX;
  cooy=newY;
}

float Card::getX(){
  sf::Vertex* quad= &GlobalCard[0];
  return quad[0].position.x+coox;
}

float Card::getY(){
  sf::Vertex* quad= &GlobalCard[0];
  return quad[0].position.x+coox;
}

void Card::draw(sf::RenderTarget & target, sf::RenderStates states) const{
  // on applique la transformation
  states.transform *= state.transform;

  // on applique la texture du tileset
  states.texture = &skin;
  Card::getTransform().transformRect(GlobalCard.getBounds());
  // et on dessine enfin le tableau de vertex
  target.draw(GlobalCard, states);
  target.draw(name,states);
  target.draw(Description,states);
}

void Card::agrandisouris(sf::RenderWindow & window){
  if(GlobalCard.getBounds().contains(float(sf::Mouse::getPosition(window).x),float(sf::Mouse::getPosition(window).y))){
    if(!agrandi){
      this->setScale({1.2f,1.2f});

      agrandi=true;
    }
  }
  else{
    if(agrandi){
      this->setScale({1/1.2f,1/1.2f});
      agrandi=false;
    }
  }
}

void Card::dragAndDrop(sf::RenderWindow & window/*,sf::Event event*/){
  /*if(event.type==sf::Event::MouseButtonPressed){
    if(event.mouseButton.button==sf::Mouse::Left){*/
    if((sf::Mouse::isButtonPressed(sf::Mouse::Left))&&(GlobalCard.getBounds().contains(float(sf::Mouse::getPosition(window).x),float(sf::Mouse::getPosition(window).y)))){
      if(!drag){
      this->setScale({1/1.2f,1/1.2f});
          drag=true;
        }
    //}
  }
  else{
    if(drag){
      this->setScale({1.2f,1.2f});
      drag=false;
    }

  }
}

void Card::always(sf::RenderWindow & window){
  if(drag){
      this->setPosition({float(sf::Mouse::getPosition(window).x),float(sf::Mouse::getPosition(window).y)});
  }
}


string Card::getName(){
  return this->name.getString();
}
