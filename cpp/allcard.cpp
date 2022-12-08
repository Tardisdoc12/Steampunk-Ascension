#include "entete/allcard.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<typeinfo>
using namespace std;


allcard::allcard(string & file)
{
    myData.open(file,ios::in);
    if(!myData){
        myData.close();
        myData.open(file,ios::out);
        myData << "1 Pioche 1 3 0"<<endl; //nom cout dégats type
        myData << "2 Mineur Tech 0 0 1"<<endl;
        myData.close();
    }
    myData.close();
    if(!Temporary.load()){
        cout<<"PAS load"<<endl;
    }
}

void stringToCard(vector<string> & all,Card & tem,vector<Card> & allCards){
    for(size_t h=0;h<all.size();h++){
        cout<<"all["<<h<<"]="<<all[h]<<"!"<<endl;
    }
    for(int i=0;i<4;i++){
        if(i==0){
          tem.setImage(all[0]);
          all.erase(all.begin());
        }
        if(i==1){
            int iter=all.size()-1;
            cout<<all[iter]<<endl;
            string t=all[iter];
            tem.setType(t);
            all.pop_back();
        }
        else if(i==2){
            //int iter=all.size()-1;
            //cout<<all[iter]<<endl;
            all.pop_back();
        }
        else if(i==3){
            int iter=all.size()-1;
            //std::cout<<all[iter]<<endl;
            tem.setMana(all[iter]);
            all.pop_back();
        }
    }
    string name;
    for(size_t i=0;i<all.size();i++){
        name+=all[i]+" ";
    }
    cout<<name<<endl;
    tem.setName(name);
    allCards.push_back(tem);

}

void assign(string & voila,Card & tem,vector<Card> & allCards){
    istringstream iss(voila);
    string Test;
    vector<string> etape;
    while(iss){
        iss>>Test;
        etape.push_back(Test);
    }
    etape.pop_back();
    stringToCard(etape,tem,allCards);
}

bool allcard::load(string & file){
    string Card;
    myData.open(file,ios::in);
    while(getline(myData,Card)){
        Cards.push_back(Card);
    }
    myData.close();
    for(size_t i=0;i<Cards.size();i++){
        assign(Cards[i],Temporary,allCards);

    }
    if(Cards.size()==0){
        return false;
    }
    else{
        return true;
    }
}

void allcard::draw(sf::RenderWindow & window){
    for(size_t i=0;i<allCards.size();i++){
        window.draw(allCards[i]);
    }
}

void allcard::setPosition(sf::Vector2f position){
    for(size_t i=0;i<allCards.size();i++){
        position=sf::Vector2f({position.x+60.f*i,position.y});
        allCards[i].setPosition(position);
        allCards[i].DeplacePosition(position);
    }
}

void allcard::agrandisouris(sf::RenderWindow & window){
    for(size_t i=0;i<allCards.size();i++){
        allCards[i].agrandisouris(window);
    }
}

void allcard::draganddrop(sf::RenderWindow & window){
    for(size_t i=0;i<allCards.size();i++){
        allCards[i].dragAndDrop(window);
    }
}


void allcard::always(){
    for(size_t i=0;i<allCards.size();i++){
        allCards[i].follow();
    }
}
