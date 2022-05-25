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
  string data="";
  std::vector<std::string> dataCards=selectData(dir);
  for (int i=0;i<dataCards.size();i+=5){
    everyCards.insert(everyCards.end(),intermediaire2);
  }
  for (int i=0;i<dataCards.size();i++){
    data+=dataCards[i];
    if(i%5==0){

    }
    else if(i%5==1){
      everyCards[(i-1)/5].setName(data);
    }
    else if(i%5==2){
      everyCards[(i-2)/5].setType(data);
    }
    else if(i%5==3){
      everyCards[(i-3)/5].setDescription(data);
    }
    else if(i%5==4){
      everyCards[(i-4)/5].setMana(data);
    }
    data="";
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
    everyCards[i].follow(window);
  }
}
