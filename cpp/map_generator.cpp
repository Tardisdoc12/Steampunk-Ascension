#include "map_generator.h"
using namespace sf;

MapGenerator::MapGenerator(int _n_floor){
  n_floor = _n_floor;
  if(n_floor==1){
      room_max=7;
      room_min=3;
  }
  else if(n_floor==2){
    room_max=10;
    room_min=5;
  }
  else{
    room_max=15;
    room_min=8;
  }
  test2.room_left_1();
  map2.insert({1,test2.return_level()});
  test2.room_right_1();
  map2.insert({2,test2.return_level()});
  test2.room_middle_1();
  map2.insert({3,test2.return_level()});
}


vector<int> addmap(vector<int> floor, vector<int> room, int number_room){
  //int floor_size=(number_room)*18;
  if(number_room==0){
    return room;
  }
  int n_salle=floor.size()/180;
  for(int i=0;i<room.size();i++){
    int tile=room[i];
    int col=(i/18);
    int bon_indice=i+18*(col+1)*n_salle;
    floor.insert(floor.begin()+bon_indice,tile);
  }
  return floor;
}

void MapGenerator::generate_floor(){
  while(room_i!=room_max){
    int j=1+(rand()%3);
    if(j==1){
      if(room_i>=room_min){
        room_i=room_i+1;
        direction.push_back("gauche");
        //cout<<"gauche"<<endl;
        break;
      }
    }
    if(j==2){
        continue;
    }
    if(j==3){
      if(direction.size()!=0){
        room_i=room_i+1;
        direction.push_back("middle");
        //cout<<"middle"<<endl;
      }
    }
  }
  if (direction.back()!="gauche"){
    direction.push_back("gauche");
  }
  direction={"droite","middle","gauche"};
  for(int g=0;g<direction.size();g++){
    if(direction[g]=="gauche"){
      test2.room_right_1();
      vector<int> ff=test2.level;
      floor_i=addmap(floor_i,ff,g);
    }
    else if (direction[g]=="middle"){
      test2.room_middle_1();
      vector<int> ff=test2.level;
      floor_i=addmap(floor_i,ff,g);
      //floor_i=floor_i+test2.return_level();
    }
    else if (direction[g]=="droite"){
      test2.room_left_1();
      vector<int> ff=test2.level;
      floor_i=addmap(floor_i,ff,g);
    }
  }
  n_room=direction.size();
}


int MapGenerator::return_n_room(){
  return n_room;
}


vector<int> MapGenerator::return_floor(){
  return floor_i;
}
