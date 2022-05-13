#include<iostream>
#include"sqlite3.h"
#include <vector>
#include "card.h"

#ifndef __allcards_h__
#define __allcards_h__


static int callback(void * NotUsed, int argc, char** argv, char** azColName);
class carddata{
private:
  Card intermediaire2;
  std::vector<Card> everyCards;
  Card currentCard;
public:
  carddata();
  std::vector<string> selectData(const char* s);
  std::vector<Card> everyCardReturn();
  void draganddrop(sf::RenderWindow & window);
  void agrandisouris(sf::RenderWindow & window);
  void always(sf::RenderWindow & window);
};
#endif
