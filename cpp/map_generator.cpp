#include "map_generator.h"
using namespace sf;

MapGenerator::MapGenerator(int _n_floor){
  n_floor = _n_floor;
  if(n_floor==1){
      room_max=5;
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
  //  Right = wall on the right!!!
  //ligne principale:
  test2.room_left_1();
  map2.insert({1,test2.return_level()});
  test2.room_right_1();
  map2.insert({2,test2.return_level()});

  //générale :
  test2.room_middle_1();
  map2.insert({3,test2.return_level()});
  test2.room_void();
  map2.insert({9,test2.return_level()});
  test2.room_T_top();
  map2.insert({4,test2.return_level()});
  test2.room_cross();
  map2.insert({5,test2.return_level()});


  //middle et bot:
  test2.room_top_middle_1();
  map2.insert({12,test2.return_level()});
  test2.room_right_bot();
  map2.insert({13,test2.return_level()});
  test2.room_left_bot();
  map2.insert({14,test2.return_level()});


  //top_floor:
  test2.room_top_left_1();
  map2.insert({10,test2.return_level()});
  test2.room_top_right_1();
  map2.insert({11,test2.return_level()});
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

vector<string> direction_randomizer(int room_i,int room_max,int room_min,vector<string> direction){
  while(room_i!=room_max){
    int j=1+(rand()%6);
    if(j==1){
      if(room_i>=room_min){
        room_i=room_i+1;
        direction.push_back("gauche");
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
      }
    }
    if(j==4){
      if(direction.size()!=0){
        room_i=room_i+1;
        direction.push_back("middle_top");
      }
    }
    if (j==5){
      room_i=room_i+1;
      direction.push_back("cross");
    }
    if (j==6){
      room_i=room_i+1;
      direction.push_back("middle_bot");
    }
  }
  if (direction.back()!="gauche"){
    direction.push_back("gauche");
  }
  return direction;
}

int min(vector<int> v){
  int min_i=0;
  for (int i=0; i<v.size(); i++){
    if(v[i]<v[min_i]){
      min_i=i;
    }
  }
  return min_i;
}
int max(vector<int> v){
  int max_i=0;
  for (int i=0; i<v.size(); i++){
    if(v[i]>v[max_i]){
      max_i=i;
    }
  }
  return max_i;
}

template <typename T>
void remove(std::vector<T>& v, size_t index) {
    v.erase(v.begin() + index);
}

vector<string> direction_top_randomizer(vector<string>& direction,vector<string> direction_top){
  vector<int> indices_to_top;
  for(int i=0;i<direction.size();i++){
    if((direction[i]=="middle_top")||(direction[i]=="cross")){
      indices_to_top.push_back(i);
    }
  }


  if(indices_to_top.size()==1){
    if((indices_to_top[0]<=direction.size()/2)&&(indices_to_top[0]!=direction.size()-2)){
      if (direction[direction.size()-2]=="middle_bot"){
        direction[direction.size()-2]="cross";
        indices_to_top.push_back(direction.size()-2);
      }
      else{
        direction[direction.size()-2]="middle_top";
        indices_to_top.push_back(direction.size()-2);
      }
    }
    else{
      if (direction[1]=="middle_bot"){
        direction[1]=="cross";
        indices_to_top.insert(indices_to_top.begin(),1);
      }
      else{
        direction[1]="middle_top";
        indices_to_top.insert(indices_to_top.begin(),1);
      }
    }
  }
  else if(indices_to_top.size()==0){
    for(int c=1;c<direction.size();c++){
      direction_top.push_back("vide");
    }
    return direction_top;
  }


  int indice_max=max(indices_to_top);
  int i2=indices_to_top[indice_max];
  remove(indices_to_top,indice_max);
  int indice_min=min(indices_to_top);
  int i1=indices_to_top[indice_min];
  remove(indices_to_top,indice_min);

  for(int ind=1;ind<direction.size();ind++){
    direction_top.push_back("vide");
  }
  direction_top[i1]="right_top";
  direction_top[i2]="left_top";
  for(int index=i1+1;index<i2;index++){
    direction_top[index]="middle";
  }
  for(int indi=0;indi<indices_to_top.size();indi++){
    direction_top[indices_to_top[indi]]="top_middle";
  }
  return direction_top;
}
//----------------------------------------------------------------------------------------------------------------------
vector<string> direction_bot_rnd(vector<string>&direction,vector<string> direction_bot){
  vector<int> indices_to_bot;
  for(int i=0;i<direction.size();i++){
    if((direction[i]=="middle_bot")||(direction[i]=="cross")){
      indices_to_bot.push_back(i);
    }
  }

  if(indices_to_bot.size()==1){
    if((indices_to_bot[0]<=direction.size()/2)&&(indices_to_bot[0]!=direction.size()-2)){
      if (direction[direction.size()-2]=="middle_top"){
        direction[direction.size()-2]="cross";
        indices_to_bot.push_back(direction.size()-2);
      }
      else{
        direction[direction.size()-2]="middle_bot";
        indices_to_bot.push_back(direction.size()-2);
      }
    }
    else{
      if(direction[1]=="middle_top"){
        direction[1]="cross";
        indices_to_bot.insert(indices_to_bot.begin(),1);
      }
      else{
        direction[1]="middle_bot";
        indices_to_bot.insert(indices_to_bot.begin(),1);
      }
    }
  }
  else if(indices_to_bot.size()==0){
    for(int c=1;c<direction.size();c++){
      direction_bot.push_back("vide");
    }
    return direction_bot;
  }


  int indice_max=max(indices_to_bot);
  int i2=indices_to_bot[indice_max];
  remove(indices_to_bot,indice_max);
  int indice_min=min(indices_to_bot);
  int i1=indices_to_bot[indice_min];
  remove(indices_to_bot,indice_min);

  for(int ind=1;ind<direction.size();ind++){
    direction_bot.push_back("vide");
  }
  direction_bot[i1]="right_bot";
  direction_bot[i2]="left_bot";
  for(int index=i1+1;index<i2;index++){
    direction_bot[index]="middle";
  }
  for(int indi=0;indi<indices_to_bot.size();indi++){
    direction_bot[indices_to_bot[indi]]="bot_middle";
  }
  return direction_bot;
}

vector<int> generation_level(vector<string> direction,map<int, vector<int>> map2,vector<int> floor_i){
  for(int g=0;g<direction.size();g++){
    if(direction[g]=="gauche"){
      vector<int> ff=map2[2];
      floor_i=addmap(floor_i,ff,g);
    }
    else if (direction[g]=="middle"){
      vector<int> ff=map2[3];
      floor_i=addmap(floor_i,ff,g);
    }
    else if (direction[g]=="droite"){
      vector<int> ff=map2[1];
      floor_i=addmap(floor_i,ff,g);
    }
    else if (direction[g]=="middle_top"){
      vector<int> ff=map2[12];
      floor_i=addmap(floor_i,ff,g);
    }
    else if (direction[g]=="middle_bot"){
      vector<int> ff=map2[4];
      floor_i=addmap(floor_i,ff,g);
    }
    else if (direction[g]=="cross"){
      vector<int> ff=map2[5];
      floor_i=addmap(floor_i,ff,g);
    }
  }
  return floor_i;
}

vector<int> generation_top_level(vector<string> direction_top,map<int, vector<int>> map2,vector<int> floor_i,vector<int> top_floor){
  for (int g=0;g<direction_top.size();g++){
    //vector<int> ff=map2[9];
    if(direction_top[g]=="vide"){
      vector<int> top=map2[9];
      top_floor=addmap(top_floor,top,g);
    }
    else if (direction_top[g]=="right_top"){
      vector<int> top=map2[10];
      top_floor=addmap(top_floor,top,g);
    }
    else if(direction_top[g]=="left_top"){
      vector<int> top=map2[11];
      top_floor=addmap(top_floor,top,g);
    }
    else if (direction_top[g]=="top_middle"){
      vector<int> top=map2[4];
      top_floor=addmap(top_floor,top,g);
    }
    else if (direction_top[g]=="middle"){
      vector<int> top=map2[3];
      top_floor=addmap(top_floor,top,g);
    }

  }
  floor_i.insert(floor_i.begin(),top_floor.begin(),top_floor.end());

  return floor_i;
}

vector<int> generation_bot_level(vector<string> direction_bot,map<int, vector<int>> map2,vector<int> floor_i,vector<int> bot_floor){
  for (int g=0;g<direction_bot.size();g++){
    if(direction_bot[g]=="vide"){
      vector<int> bot=map2[9];
      bot_floor=addmap(bot_floor,bot,g);
    }
    else if (direction_bot[g]=="right_bot"){
      vector<int> bot=map2[13];
      bot_floor=addmap(bot_floor,bot,g);
    }
    else if(direction_bot[g]=="left_bot"){
      vector<int> bot=map2[14];
      bot_floor=addmap(bot_floor,bot,g);
    }
    else if (direction_bot[g]=="bot_middle"){
      vector<int> bot=map2[12];
      bot_floor=addmap(bot_floor,bot,g);
    }
    else if (direction_bot[g]=="middle"){
      vector<int> bot=map2[3];
      bot_floor=addmap(bot_floor,bot,g);
    }
  }
  floor_i.insert(floor_i.end(),bot_floor.begin(),bot_floor.end());

  return floor_i;
}

void MapGenerator::generate_floor(){
  direction=direction_randomizer(room_i,room_max,room_min,direction);
  direction_top=direction_top_randomizer(direction,direction_top);
  direction_bot=direction_bot_rnd(direction,direction_bot);
  cout<<direction_top.size()<<" et "<<direction.size()<<endl;
  floor_i=generation_level(direction,map2,floor_i);
  floor_i=generation_top_level(direction_top,map2,floor_i,top_floor);
  floor_i=generation_bot_level(direction_bot,map2,floor_i,bot_floor);
  n_room=direction.size();
}

int MapGenerator::return_n_room(){
  return n_room;
}

vector<int> MapGenerator::return_floor(){
  return floor_i;
}

int MapGenerator::return_topTobot(){
  return n_topTobot;
}
