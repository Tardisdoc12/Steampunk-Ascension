#include "levels.h"
using namespace std;
room::room(){

}
//mur de droite : tuile 13!! mur de gauche tuile 15
void room::room_left_1(){
  level={
    15, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,166,
    15, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,166,
    15, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,166,
    15, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,166,
    15, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,166,
    15, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,166,
    15, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,166, 166,
    15, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,166, 166,
    15, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,166, 166,
    44, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
  };
}
void room::room_right_1(){
  level={
    166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,13,
    166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,13,
    166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,13,
    166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,13,
    166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,13,
    166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,13,
    166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,166, 13,
    166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,166, 13,
    166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,166, 13,
    26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 45,
  };
}
void room::room_middle_1(){
  level={
    166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,166,
    166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,166,
    166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,166,
    166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,166,
    166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,166,
    166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,166,
    166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,166, 166,
    166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,166, 166,
    166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166, 166,166,166, 166,
    26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
  };
}
vector<int> room::return_level(){
  return level;
}
