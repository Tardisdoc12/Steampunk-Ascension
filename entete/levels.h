#include<iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include<vector>

#ifndef __levels_h__
#define __levels_h__
class room{
private:
  std::vector<int> level;
  int tile;
public:
  room();
  void room_left_1();
  void room_right_1();
  void room_middle_1();
  void room_top_left_1();
  void room_top_middle_1();
  void room_top_right_1();
  void room_void();
  void room_T_top();
  void room_cross();
  void room_right_bot();
  void room_left_bot();
  std::vector<int> return_level();
};
#endif
