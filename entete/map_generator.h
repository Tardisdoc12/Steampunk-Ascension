#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<stdio.h>
#include<map>
#include<vector>
#include "entete/levels.h"
using namespace std;
template<typename Map>

void PrintMap(Map& m){
    cout << "[ ";
    for (auto &item : m) {
        cout << item.first << ":" << item.second << " ";
    }
    cout << "]\n";
}

#ifndef __map_generator_h__
#define __map_generator_h__


class MapGenerator{
private:
  map<int, vector<int>> map2;
  int room_min;
  int room_max;
  int room_i=1;
  int n_floor;
  int n_topTobot=2;
  int n_room;
  room test2;
  vector<int> floor_i;
  vector<int> top_floor;
  vector<int> bot_floor;
  vector<string> direction_bot={"vide"};
  vector<string> direction={"droite"};
  vector<string> direction_top={"vide"};
public:
  MapGenerator(int _n_floor);
  void generate_floor(); //generate the level
  vector<int> return_floor(); //number of the floor between 1 and 3
  int return_n_room();//number of room in the level
  int return_topTobot();//number of way in the level
};


#endif
