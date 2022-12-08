#include "entete/arrow.h"
#include<iostream>
#include<cmath>
arrow::arrow()
{
    Arrow.setPrimitiveType(sf::Triangles);
    Arrow.resize(2*3);
    activate=false;

    sf::Vertex* triangle =&Arrow[0];

    triangle[0].position=sf::Vector2f(sf::Mouse::getPosition().x,sf::Mouse::getPosition().y);
    triangle[1].position=sf::Vector2f(triangle[0].position.x+20.f,triangle[0].position.y+10.f);
    triangle[2].position=sf::Vector2f(triangle[0].position.x+10.f,triangle[0].position.y+20.f);

    triangle[0].color=sf::Color::Red;
    triangle[1].color=sf::Color::Red;
    triangle[2].color=sf::Color::Red;
    this->setOrigin(15.f,15.f);

}

void arrow::draw(sf::RenderTarget & target,sf::RenderStates states) const{
    if(activate){
        states.transform *= getTransform();

        states.texture = NULL;

        target.draw(Arrow,states);
    }
}

/*void arrow::Creation(sf::Event event){
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            this->setPosition(sf::Mouse::getPosition().x,sf::Mouse::getPosition().y);
            Arrow.clear();
            Arrow.resize(3);
            sf::Vertex* triangle =&Arrow[0];

            triangle[0].position=sf::Vector2f(sf::Mouse::getPosition().x,sf::Mouse::getPosition().y);
            triangle[1].position=sf::Vector2f(triangle[0].position.x+20.f,triangle[0].position.y+10.f);
            triangle[2].position=sf::Vector2f(triangle[0].position.x+10.f,triangle[0].position.y+20.f);

            triangle[0].color=sf::Color::Red;
            triangle[1].color=sf::Color::Red;
            triangle[2].color=sf::Color::Red;

        }
    }
}*/

void arrow::follow(){
    if(activate){
        sf::Vector2f p(sf::Mouse::getPosition().x - this->getPosition().x, sf::Mouse::getPosition().y - this->getPosition().y);
        this->setRotation((180.0/3.14159)*std::atan2(p.y, p.x)+130);
    }
}

void arrow::Stretching(){
    sf::Vector2f p(sf::Mouse::getPosition().x-this->getPosition().x,sf::Mouse::getPosition().y-this->getPosition().y);
    float dist=std::sqrt(pow(p.x,2)+pow(p.y,2));

    //Création du triangle:
    if ((Arrow.getVertexCount()/3*sqrt(550)<dist)&&(activate)){
        Arrow.resize(Arrow.getVertexCount()+1*3);
        sf::Vertex* Triangle = &Arrow[Arrow.getVertexCount()-3];
        Triangle[0].position=sf::Vector2f(this->getOrigin().x,this->getOrigin().y);
        Triangle[1].position=sf::Vector2f(Triangle[0].position.x+20.f,Triangle[0].position.y+10.f);
        Triangle[2].position=sf::Vector2f(Triangle[0].position.x+10.f,Triangle[0].position.y+20.f);

        Triangle[0].color=sf::Color::Red;
        Triangle[1].color=sf::Color::Red;
        Triangle[2].color=sf::Color::Red;
        this->setOrigin((Triangle[1].position.x+Triangle[2].position.x)/2,(Triangle[1].position.y+Triangle[2].position.y)/2);
    }

    //Déstruction du triangle
    else if((Arrow.getVertexCount()/3*sqrt(550)>dist*1.1)&&(activate)){
        Arrow.resize(Arrow.getVertexCount()-3);
        Arrow.clear();
        sf::Vertex* triangle =&Arrow[0];

        triangle[0].position=sf::Vector2f(sf::Mouse::getPosition().x,sf::Mouse::getPosition().y);
        triangle[1].position=sf::Vector2f(triangle[0].position.x+20.f,triangle[0].position.y+10.f);
        triangle[2].position=sf::Vector2f(triangle[0].position.x+10.f,triangle[0].position.y+20.f);

        triangle[0].color=sf::Color::Red;
        triangle[1].color=sf::Color::Red;
        triangle[2].color=sf::Color::Red;

        this->setOrigin(15.f,15.f);
        for(size_t i=3;i<Arrow.getVertexCount();i=i+3){
            sf::Vertex* Triangle = &Arrow[i];
            Triangle[0].position=sf::Vector2f(this->getOrigin().x,this->getOrigin().y);
            Triangle[1].position=sf::Vector2f(Triangle[0].position.x+20.f,Triangle[0].position.y+10.f);
            Triangle[2].position=sf::Vector2f(Triangle[0].position.x+10.f,Triangle[0].position.y+20.f);

            Triangle[0].color=sf::Color::Red;
            Triangle[1].color=sf::Color::Red;
            Triangle[2].color=sf::Color::Red;
            this->setOrigin((Triangle[1].position.x+Triangle[2].position.x)/2,(Triangle[1].position.y+Triangle[2].position.y)/2);
        }
    }
}


void arrow::Activate(){
    if(!activate){
        activate=true;
    }
}

void arrow::Desactivate(){
    if(activate){
        activate=false;
    }
}
