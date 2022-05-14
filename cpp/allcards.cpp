#include"allcards.h"
using namespace std;

vector<string> carddata::selectData(const char* s){
  sqlite3* DB;

  vector<std::string> cara;

  int exit = sqlite3_open(s,&DB);

  string sql = "SELECT * FROM CARDS;";

  sqlite3_exec(DB,sql.c_str(), callback, &cara,NULL);

  return cara;
}

static int callback(void* NotUsed, int argc, char** argv, char** azColName){

  std::vector<string> *intermediaire=(vector<string>*)NotUsed;
  for (int i=0;i<argc;i++){
    string donnee;
    donnee+=argv[i];
    intermediaire->insert(intermediaire->end(),donnee);
  }

  return 0;
}

carddata::carddata(){
  sqlite3* DB;

  const char* dir = "../DataBase/Cards.db";

  std::vector<std::string> dataCards=selectData(dir); // A CHANGER CAR CE N'EST PLUS BON
  for (int i=0;i<dataCards.size();i++){
    if((i==0)||(i%4==0)){

    }
    else if((i!=0)&&(i%2==0)&&(i%4!=0)){
      intermediaire2.setDescription(dataCards[i]);
    }
    else if((i!=0)&&((i-1)%4==0)){
      intermediaire2.setName(dataCards[i]);
    }
    else if((i!=0)&&((i-1)%2==0)&&((i-1)%4!=0)){
      everyCards.insert(everyCards.end(),intermediaire2);
    }
  }

}

std::vector<Card> carddata::everyCardReturn(){
  return everyCards;
}


void carddata::draganddrop(sf::RenderWindow & window){
  for (int i=0;i<everyCards.size();i++){
    everyCards[i].dragAndDrop(window);
  }
}

void carddata::agrandisouris(sf::RenderWindow & window){
  for (int i=0;i<everyCards.size();i++){
    everyCards[i].agrandisouris(window);
  }
}

void carddata::always(sf::RenderWindow & window){
  for (int i=0;i<everyCards.size();i++){
    everyCards[i].always(window);
  }
}
