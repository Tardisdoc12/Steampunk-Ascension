#include<iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include<vector>

#ifndef __levels_h__
#define __levels_h__
class room{
private:

  int tile;
public:
  std::vector<int> level;
  room();
  void room_left_1();
  void room_right_1();
  void room_middle_1();
  std::vector<int> return_level();
};
#endif
