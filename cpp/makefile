ENTETE_PATH=../entete
CFLAGS2 = -I$(ENTETE_PATH)
CFLAGS3 = -lsqlite3

%.o: %.cpp
	g++ -o $@ -c $< $(CFLAGS2) $(CFLAGS3)


game: Deck.o allcards.o Player.o ennemi.o life.o card.o Steampunk_Tower.o createdatabase.o
	g++ Deck.o allcards.o Player.o ennemi.o life.o card.o Steampunk_Tower.o -o Steampunk_Tower -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsqlite3
	g++ createdatabase.o -o create -lsqlite3
	./create
	rm *.o
	./Steampunk_Tower
