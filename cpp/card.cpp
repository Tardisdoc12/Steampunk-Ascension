#include "entete/card.h"
using namespace std;
using namespace sf;

Card::Card(){
}

bool Card::load(){
    if(!card_back.loadFromFile("C:/Users/laure/Desktop/Steampunk_Ascension/Sprite/card.png")){
        return false;
    }
    if(!card_image.loadFromFile("C:/Users/laure/Desktop/Steampunk_Ascension/Sprite/Image/1.jpg")){
        return false;
    }
    if(!font.loadFromFile("C:/Users/laure/Desktop/Steampunk_Ascension/Font/test.ttf")){
        return false;
    }
    // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
    card.resize(4);
    card.setPrimitiveType(sf::Quads);
    Image_card.resize(4);
    Image_card.setPrimitiveType(sf::Quads);
    // on récupère un pointeur vers le card_back à définir dans le tableau de vertex
    sf::Vertex* card_ba = &card[0];
    sf::Vertex* card_im = &Image_card[0];
    // on définit ses quatre coins
    card_ba[0].position = sf::Vector2f(0.f,0.f);
    card_ba[1].position = sf::Vector2f(150.f,0.f);
    card_ba[2].position = sf::Vector2f(150.f,430.f/2);
    card_ba[3].position = sf::Vector2f(0.f,430.f/2);
    test.setSize(sf::Vector2f(150.f,215.f));
    test.setPosition(sf::Vector2f(0.f,0.f));
    test.setFillColor(sf::Color::Transparent);
    test.setOutlineThickness(2.f);
    test.setOutlineColor(Color::Transparent);
    // on définit ses quatre coordonnées de texture
    card_ba[0].texCoords = sf::Vector2f(0.f,0.f);
    card_ba[1].texCoords = sf::Vector2f(300.f,0.f);
    card_ba[2].texCoords = sf::Vector2f(300.f,430.f);
    card_ba[3].texCoords = sf::Vector2f(0.f,430.f);

    // on définit card_im :
    card_im[0].position = sf::Vector2f(card_ba[0].position+sf::Vector2f(5.f,5.f));
    card_im[1].position=sf::Vector2f(card_ba[1].position+sf::Vector2f(0.f,5.f));
    card_im[2].position = sf::Vector2f(card_im[1].position+sf::Vector2f(0.f,95.f));
    card_im[3].position=sf::Vector2f(card_im[0].position+sf::Vector2f(0.f,95.f));

    //on definit ses 4 coordonées de Texture
    card_im[0].texCoords = sf::Vector2f(0.f,0.f);
    card_im[1].texCoords = sf::Vector2f(600.f,0.f);
    card_im[2].texCoords = sf::Vector2f(600.f,600.f);
    card_im[3].texCoords = sf::Vector2f(0.f,600.f);

    //this->setOrigin(75.f,0.f);
    Name.setFont(font);
    Description.setFont(font);
    Mana.setFont(font);
    point.setPosition(this->getPosition());
    return true;
}

void Card::setImage(std::string path_to_image){
    std::string path="C:/Users/laure/Desktop/Steampunk_Ascension/Sprite/Image/"+path_to_image+".jpg";
    if(!card_image.loadFromFile(path)){
      cout<<"ERROR_FAIL"<<endl;
    }
    sf::Vertex* card_im = &Image_card[0];
    //on definit ses 4 coordonées de Texture
    card_im[0].texCoords = sf::Vector2f(0.f,0.f);
    card_im[1].texCoords = sf::Vector2f(card_image.getSize().x,0.f);
    card_im[2].texCoords = sf::Vector2f(card_image.getSize().x,card_image.getSize().y);
    card_im[3].texCoords = sf::Vector2f(0.f,card_image.getSize().y);
}

void Card::setDescription(string desc){
    Description.setString(desc);
    Description.setCharacterSize(12);
    Description.setFillColor(sf::Color::Blue);
    Description.setPosition(this->getPosition().x+10.f,this->getPosition().y+125.f);
}

void Card::setMana(string mana){
    Mana.setString(mana);
    Mana.setCharacterSize(20);
    Mana.setFillColor(sf::Color::Blue);
    Mana.setPosition(this->getPosition().x+15.f,this->getPosition().y+10.f);
}

void Card::setName(string name){
    Name.setString(name);
    Name.setCharacterSize(20);
    Name.setFillColor(sf::Color::Blue);
    Name.setOrigin(Name.getLocalBounds().width/2,Name.getLocalBounds().height/2);
    Name.setPosition(this->getPosition().x+150.f/2,this->getPosition().y+75.f);
}

void Card::setType(string type){
    //int Type=std::stoi(type);
    if (type=="1"){
      if(!card_back.loadFromFile("C:/Users/laure/Desktop/Steampunk_Ascension/Sprite/card_mana2.png")){
        cout<<"IMAGE_LOAD_FAILED"<<endl;
      }
    }
    else if (type=="2"){
      if(!card_back.loadFromFile("C:/Users/laure/Desktop/Steampunk_Ascension/Sprite/card_neutre.png")){
        cout<<"IMAGE_LOAD_FAILED"<<endl;
      }
    }
    else if (type=="3"){
      if(!card_back.loadFromFile("C:/Users/laure/Desktop/Steampunk_Ascension/Sprite/card_spell2.png")){
        cout<<"IMAGE_LOAD_FAILED"<<endl;
      }
    }
    else if (type=="0"){
      if(!card_back.loadFromFile("C:/Users/laure/Desktop/Steampunk_Ascension/Sprite/card.png")){
        cout<<"IMAGE_LOAD_FAILED"<<endl;
      }
    }
}

void Card::agrandisouris(sf::RenderWindow & window){
  if (test.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))){
    if((!drag)&&(!agrandi)){
        agrandi=true;
        this->move({0.f,-10.f});
    }
    else if(drag){
      agrandi=true;
    }
  }
  else{
    if(agrandi){
      agrandi=false;
      this->move({0.f,10.f});
    }
  }
}

void Card::dragAndDrop(sf::RenderWindow & window){
  if((sf::Mouse::isButtonPressed(sf::Mouse::Left))&&(test.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))){
    if(!drag){
      drag=true;
      point.setPosition(this->getPosition().x+75.f,this->getPosition().y+215.f/2);
      point.Activate();
    }
  }
  else if ((sf::Mouse::isButtonPressed(sf::Mouse::Left))&&(!test.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))){
      drag=false;
      point.Desactivate();
  }
  else{
    if(drag){
      drag=false;
    }
  }
}

void Card::follow(){
  if(drag){
    //this->setPosition(float(sf::Mouse::getPosition(window).x)-75.f,float(sf::Mouse::getPosition(window).y)-215.f/2);
    //test.setPosition(float(sf::Mouse::getPosition(window).x)-75.f,float(sf::Mouse::getPosition(window).y)-215.f/2);

  }
  point.Stretching();
  point.follow();
}

void Card::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform(); // getTransform() est définie par sf::Transformable

    // on dessine le tableau de vertex

    // on applique la texture
    states.texture=&card_image;
    target.draw(Image_card,states);

    // on applique la texture
    states.texture = &card_back;
    target.draw(card, states);

    target.draw(Name,states);
    target.draw(test);
    target.draw(Description,states);
    target.draw(Mana,states);
    target.draw(point);

}

FloatRect Card::getGlobalBounds(){
    return test.getGlobalBounds();
}

void Card::DeplacePosition(sf::Vector2f dir){
    test.setPosition(dir);
}
