#include "entete/view.h"
#include "entete/collision.h"
#include "entete/Floor.h"
using namespace std;
using namespace sf;

camera::camera(){

}

camera::camera(Vector2f _size,Vector2f _position,Vector2u TileSize,sf::RenderWindow& window){
  size=_size;
  position=_position;
  position_initial=_position;
  room.setCenter(position);
  room.setSize(size);
}


void camera::move_cam(Player& player,Floor& map){
  if((player.getPosition().x>position_initial.x+5.f)&&(player.getPosition().x<(position_initial.x+map.getContour().width*16.f-18*16.f+5.f))){
    position=sf::Vector2f({player.getPosition().x-5.f,position.y});
    room.setCenter(position);
  }
  if((player.getPosition().y>16.f*21)&&(player.getPosition().y<16.f*25)){
    position=sf::Vector2f({position.x,player.getPosition().y});
    room.setCenter(position);
  }
  if((player.getPosition().y>16.f*15)&&(player.getPosition().y<16.f*20)){
    position=sf::Vector2f({position.x,position_initial.y});
    room.setCenter(position);
  }
  else if((player.getPosition().y>16.f*5)&&(player.getPosition().y<16.f*10)){
    position=sf::Vector2f({position.x,position_initial.y-16.f*10});
    room.setCenter(position);
  }
}


void camera::setView1(sf::RenderWindow & window){
  window.setView(room);
}
