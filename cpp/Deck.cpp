#include "Deck.h"

Deck::Deck(){

}

void Deck::createDeck(string classType,carddata & allcards){
  for(int i=0;i<allcards.everyCards.size();i++){
    deck_base.insert(deck_base.end(),allcards.everyCards[i]);
  }
}

Deck::~Deck(){

}
