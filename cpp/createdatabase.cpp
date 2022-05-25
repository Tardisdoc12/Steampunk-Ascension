#include<iostream>
#include"sqlite3.h"
#include <cstring>
#include <string>
#include <vector>

using namespace std;

//on va créer la base de donnée des cartes pour le jeu

static int createDB(const char* s);
static int createTable(const char* s);
static int insertData(const char* s);
static int selectData(const char* s);
static int callback(void * NotUsed, int argc, char** argv, char** azColName);

int main(){
  const char* dir = "../DataBase/Cards.db";
  sqlite3* DB;
  createDB(dir);
  createTable(dir);
  if(selectData(dir)==0){
    insertData(dir);
  }

  return 0;
}

static int createDB(const char* s){
  sqlite3* DB;
  int exit = 0;

  exit= sqlite3_open(s,&DB);

  sqlite3_close(DB);

  return 0;
}

static int createTable(const char* s){
  sqlite3* DB;

  string sql = "CREATE TABLE IF NOT EXISTS CARDS("
    "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
    "NAME   TEXT NOT NULL,"
    "TYPE INT NOT NULL,"
    "EFFECT TEXT NOT NULL,"
    "MANA INT NOT NULL);";

  try{
      int exit =0;
      exit = sqlite3_open(s,&DB);

      char* messageError;
      exit=sqlite3_exec(DB,sql.c_str(),NULL,0,&messageError);

      if(exit != SQLITE_OK){
        cerr<<"Error Create Table"<<endl;
        sqlite3_free(messageError);
      }
      else{
        cout<<"Table created successfully"<<endl;
        sqlite3_close(DB);
      }
  }
  catch (const exception & e){
    cerr<<e.what();
  }

  return 0;
}


static int insertData(const char* s){
  sqlite3* DB;
  char* messageError;

  int exit = sqlite3_open(s,&DB);

  string sql("INSERT INTO CARDS (NAME,TYPE, EFFECT, MANA) VALUES('Test',2, 'Voici l effet', 3);"
             "INSERT INTO CARDS(NAME,TYPE, EFFECT, MANA) VALUES('Test2',1, 'vol, lien de vie',4);"
             "INSERT INTO CARDS (NAME,TYPE, EFFECT, MANA) VALUES('Griffes',0,'deal 5 damage',0);"
             "INSERT INTO CARDS (NAME,TYPE,EFFECT,MANA) VALUES('Etherium',3,'deal 2x3 damage',2)");

  exit = sqlite3_exec(DB,sql.c_str(), NULL, 0, &messageError);

  if(exit != SQLITE_OK){
    cerr<<"Error Insert"<<endl;
    sqlite3_free(messageError);
  }
  else{
    cout<<"Records created Successfully!"<<endl;
  }

  return 0;
}


static int selectData(const char* s){
  sqlite3* DB;

  vector<std::string> cara;

  int exit = sqlite3_open(s,&DB);

  string sql = "SELECT * FROM CARDS;";

  sqlite3_exec(DB,sql.c_str(), callback, &cara,NULL);

  /*for (int i=0;i<cara.size();i++){
    cout<<cara[i]<<endl;
  }*/

  return cara.size();
}

static int callback(void* NotUsed, int argc, char** argv, char** azColName){

  vector<string> *car=(vector<string>*)NotUsed;
  std::string donnee;
  for (int i=0;i<argc;i++){
    donnee="";
    donnee+=argv[i];
    //cout<<azColName[i]<<" : "<<argv[i]<<endl;
    car->insert(car->end(),donnee);
  }

  return 0;
}
