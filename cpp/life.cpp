#include "entete/life.h"

life::life(int ptDeVie){
  green.setSize({longueur,hauteur});
  red.setSize({longueur,hauteur});
  counterLife=ptDeVie;
  lifeMax=ptDeVie;
  green.setFillColor(sf::Color::Green);
  red.setFillColor(sf::Color::Black);
  red.setOutlineColor(sf::Color::White);
  red.setOutlineThickness(2.5f);
  if(!font.loadFromFile("C:/Users/laure/Desktop/Steampunk_Ascension/Font/StarshipRegular.otf")){
    cout<<"ERROR_FAIL"<<endl;
  }
  counter.setFont(font);
  counter.setString(to_string(counterLife)+" / "+to_string(lifeMax));
  counter.setFillColor(sf::Color::Red);
  counter.setCharacterSize(17.f);
  counter.setOrigin(counter.getLocalBounds().width/2,counter.getLocalBounds().height/2);
  counter.setPosition(red.getPosition().x,red.getPosition().y);
}

life::life(){
  green.setSize({longueur,hauteur});
  red.setSize({longueur,hauteur});
  green.setFillColor(sf::Color::Green);
  red.setFillColor(sf::Color::Black);
  red.setOutlineColor(sf::Color::White);
  red.setOutlineThickness(2.5f);
  if(!font.loadFromFile("C:/Users/laure/Desktop/Steampunk_Ascension/Font/StarshipRegular.otf")){
    cout<<"ERROR_FAIL"<<endl;
  }
  counter.setFont(font);
  counter.setString(to_string(counterLife)+" / "+to_string(lifeMax));
  counter.setFillColor(sf::Color::Red);
  counter.setCharacterSize(17.f);
  counter.setOrigin(counter.getLocalBounds().width/2,counter.getLocalBounds().height/2);
  counter.setPosition(red.getPosition().x,red.getPosition().y);
}

void life::initialise(int ptDevie){
  counterLife=ptDevie;
  lifeMax=ptDevie;
  counter.setString(to_string(counterLife)+" / "+to_string(lifeMax));
  counter.setOrigin(counter.getLocalBounds().width/2,counter.getLocalBounds().height/2);
  counter.setPosition(red.getPosition().x,red.getPosition().y);
}

void life::PerteDeVie(int degat){
  green.setSize({float(green.getSize().x)-float(longueur*degat/lifeMax),hauteur});
  counterLife-=degat;
  counter.setString(to_string(counterLife)+" / "+to_string(lifeMax));
}

void life::GainDeVie(int gain){
  if(counterLife+gain<=lifeMax){
    counterLife+=gain;
    green.setSize({float(green.getSize().x)+float(longueur*gain/lifeMax),hauteur});
  }
  else{
    counterLife=lifeMax;
    green.setSize({longueur,hauteur});
  }
  counter.setString(to_string(counterLife)+" / "+to_string(lifeMax));
}


void life::setMaxVie(int i){
  longueur=float(i*longueur/lifeMax);
  int inter=abs(lifeMax-i);
  if(lifeMax-i<0){
    counterLife+=inter;
    green.setSize({longueur,hauteur});
    red.setSize({longueur,hauteur});
    lifeMax=i;
  }
  else{
    if(counterLife-i>0){
      counterLife=i;
      green.setSize({longueur,hauteur});
      red.setSize({longueur,hauteur});
      lifeMax=i;
    }
    else{
      green.setSize({float(longueur*counterLife/i),hauteur});
      red.setSize({longueur,hauteur});
      lifeMax=i;
    }
  }
  counter.setString(to_string(counterLife)+" / "+to_string(lifeMax));
  counter.setPosition(red.getPosition().x+longueur/2,red.getPosition().y);
}

void life::setPosition(sf::Vector2f Pos){
  green.setPosition(Pos);
  red.setPosition(Pos);
  counter.setPosition(red.getPosition().x+longueur/2,red.getPosition().y);
}

void life::draw(sf::RenderTarget & target, sf::RenderStates states) const{
  //states.transform *= getTransform();
  target.draw(red);
  target.draw(green);
  target.draw(counter);
}
