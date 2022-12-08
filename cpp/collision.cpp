#include"entete/collision.h"

namespace Collision{
  bool collision_tuile(const sf::Rect<float> & rect,sf::Sprite & joueur){
    if(rect.intersects(joueur.getGlobalBounds())){
      return true;
    }
    return false;
  }

  bool collision(VertexArray array,Sprite & joueur,sf::Vector2u dim){
    for(unsigned int i=0;i<array.getVertexCount();i=i+4){
      sf::VertexArray test(sf::Quads,4);
      test[0].position=array[i].position;
      sf::Rect<float> test1(test[0].position.x,test[0].position.y,dim.x,dim.y);
      if(collision_tuile(test1,joueur)){
        return true;
      }
    }

    return false;
  }

  bool collision(sf::FloatRect& sideView,sf::FloatRect joueur){
    if(sideView.intersects(joueur)){
      return true;
    }
    return false;
  }

  bool collision(sf::Sprite ennemy,sf::Sprite & joueur){
    if(ennemy.getGlobalBounds().intersects(joueur.getGlobalBounds())){
        return true;
    }
    return false;
  }
}
