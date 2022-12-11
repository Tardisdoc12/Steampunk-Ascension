#ifndef ARROW_H
#define ARROW_H
#include<iostream>
#include<SFML/Graphics.hpp>

class arrow : public sf::Transformable, public sf::Drawable
{
private:
    sf::VertexArray Arrow;
    bool activate;
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
public:
    arrow(); //to help the targetting of the ennemy with card
    void follow();
    void Stretching();
    //void Creation(sf::Event event);
    void Activate();
    void Desactivate();
};

#endif // ARROW_H
