#Author:  Tomáš Bydžovský
#		  bydzoto1@fit.cvut.cz


CXX       = g++
LD        = g++
CXXFLAGS  = -Wall -Wno-long-long -O0 -ggdb -Wextra -pedantic -std=c++11
LIBS      = 

TARGET	  = bydzoto1
BINARIES  = bin
SOURCES   = src
DOC  	  = doc
DOXYFILE  = Doxyfile

OBJECTS   = $(BINARIES)/Action.o $(BINARIES)/Bishop.o $(BINARIES)/ComputerPlayer.o \
$(BINARIES)/FenParser.o $(BINARIES)/Figure.o $(BINARIES)/FileIO.o $(BINARIES)/GameController.o \
$(BINARIES)/GameMode.o $(BINARIES)/HumanPlayer.o  $(BINARIES)/King.o  $(BINARIES)/Knight.o \
$(BINARIES)/main.o  $(BINARIES)/Move.o $(BINARIES)/MultiplayerMode.o $(BINARIES)/Pawn.o  \
$(BINARIES)/Player.o $(BINARIES)/Position.o $(BINARIES)/Queen.o $(BINARIES)/Rook.o  \
$(BINARIES)/SimpleConsoleUI.o  $(BINARIES)/SinglePlayerMode.o  $(BINARIES)/State.o \
$(BINARIES)/Tile.o $(BINARIES)/UI.o


#compile program and create ducumentation 
all: compile doc

#compile
compile: $(TARGET)

#generate documentation:
doc: $(DOXYFILE) $(SOURCES)/*
	doxygen $(DOXYFILE)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -Rf $(DOC) $(BINARIES) $(TARGET) *~ core

#link objects:
$(TARGET): $(OBJECTS)
	$(LD) -o $@ $^ $(LIBS)

#compile objects:
$(BINARIES)/%.o: $(SOURCES)/%.cpp
	mkdir -p $(BINARIES)
	$(CXX) $(CXXFLAGS) -c -o $@ $<


#dependencies:

$(BINARIES)/Action.o: $(SOURCES)/Action.cpp $(SOURCES)/Action.h

$(BINARIES)/Bishop.o: $(SOURCES)/Bishop.cpp $(SOURCES)/Bishop.h $(SOURCES)/Figure.h $(SOURCES)/Position.h \
 $(SOURCES)/Move.h $(SOURCES)/Action.h

$(BINARIES)/ComputerPlayer.o: $(SOURCES)/ComputerPlayer.cpp $(SOURCES)/ComputerPlayer.h \
 $(SOURCES)/Player.h $(SOURCES)/Move.h $(SOURCES)/Position.h $(SOURCES)/State.h $(SOURCES)/Figure.h \
 $(SOURCES)/Action.h $(SOURCES)/Tile.h

$(BINARIES)/FenParser.o: $(SOURCES)/FenParser.cpp $(SOURCES)/FenParser.h $(SOURCES)/State.h $(SOURCES)/Figure.h \
 $(SOURCES)/Position.h $(SOURCES)/Move.h $(SOURCES)/Action.h $(SOURCES)/Tile.h $(SOURCES)/Pawn.h $(SOURCES)/Rook.h \
 $(SOURCES)/King.h $(SOURCES)/Queen.h $(SOURCES)/Knight.h $(SOURCES)/Bishop.h

$(BINARIES)/Figure.o: $(SOURCES)/Figure.cpp $(SOURCES)/Figure.h $(SOURCES)/Position.h $(SOURCES)/Move.h \
 $(SOURCES)/Action.h

$(BINARIES)/FileIO.o: $(SOURCES)/FileIO.cpp $(SOURCES)/FileIO.h

$(BINARIES)/GameController.o: $(SOURCES)/GameController.cpp $(SOURCES)/GameController.h $(SOURCES)/State.h \
 $(SOURCES)/Figure.h $(SOURCES)/Position.h $(SOURCES)/Move.h $(SOURCES)/Action.h $(SOURCES)/Tile.h \
 $(SOURCES)/MultiplayerMode.h $(SOURCES)/GameMode.h $(SOURCES)/Player.h $(SOURCES)/FenParser.h \
 $(SOURCES)/Pawn.h $(SOURCES)/Rook.h $(SOURCES)/King.h $(SOURCES)/Queen.h $(SOURCES)/Knight.h $(SOURCES)/Bishop.h \
 $(SOURCES)/SingleplayerMode.h $(SOURCES)/HumanPlayer.h $(SOURCES)/ComputerPlayer.h \
 $(SOURCES)/SimpleConsoleUI.h $(SOURCES)/UI.h $(SOURCES)/FileIO.h

$(BINARIES)/GameMode.o: $(SOURCES)/GameMode.cpp $(SOURCES)/GameMode.h $(SOURCES)/Player.h $(SOURCES)/Move.h \
 $(SOURCES)/Position.h $(SOURCES)/State.h $(SOURCES)/Figure.h $(SOURCES)/Action.h $(SOURCES)/Tile.h \
 $(SOURCES)/FenParser.h $(SOURCES)/Pawn.h $(SOURCES)/Rook.h $(SOURCES)/King.h $(SOURCES)/Queen.h \
 $(SOURCES)/Knight.h $(SOURCES)/Bishop.h $(SOURCES)/GameController.h $(SOURCES)/MultiplayerMode.h \
 $(SOURCES)/SingleplayerMode.h $(SOURCES)/HumanPlayer.h $(SOURCES)/ComputerPlayer.h \
 $(SOURCES)/SimpleConsoleUI.h $(SOURCES)/UI.h $(SOURCES)/FileIO.h

$(BINARIES)/HumanPlayer.o:$(SOURCES)/HumanPlayer.cpp $(SOURCES)/HumanPlayer.h $(SOURCES)/Player.h \
 $(SOURCES)/Move.h $(SOURCES)/Position.h $(SOURCES)/State.h $(SOURCES)/Figure.h $(SOURCES)/Action.h \
 $(SOURCES)/Tile.h $(SOURCES)/GameController.h $(SOURCES)/MultiplayerMode.h $(SOURCES)/GameMode.h \
 $(SOURCES)/FenParser.h $(SOURCES)/Pawn.h $(SOURCES)/Rook.h $(SOURCES)/King.h $(SOURCES)/Queen.h \
 $(SOURCES)/Knight.h $(SOURCES)/Bishop.h $(SOURCES)/SingleplayerMode.h $(SOURCES)/ComputerPlayer.h \
 $(SOURCES)/SimpleConsoleUI.h $(SOURCES)/UI.h $(SOURCES)/FileIO.h

$(BINARIES)/King.o: $(SOURCES)/King.cpp $(SOURCES)/King.h $(SOURCES)/Figure.h $(SOURCES)/Position.h $(SOURCES)/Move.h \
 $(SOURCES)/Action.h

$(BINARIES)/Knight.o: $(SOURCES)/Knight.cpp $(SOURCES)/Knight.h $(SOURCES)/Figure.h $(SOURCES)/Position.h \
 $(SOURCES)/Move.h $(SOURCES)/Action.h

$(BINARIES)/main.o: $(SOURCES)/main.cpp $(SOURCES)/GameController.h $(SOURCES)/State.h $(SOURCES)/Figure.h \
 $(SOURCES)/Position.h $(SOURCES)/Move.h $(SOURCES)/Action.h $(SOURCES)/Tile.h $(SOURCES)/MultiplayerMode.h \
 $(SOURCES)/GameMode.h $(SOURCES)/Player.h $(SOURCES)/FenParser.h $(SOURCES)/Pawn.h $(SOURCES)/Rook.h \
 $(SOURCES)/King.h $(SOURCES)/Queen.h $(SOURCES)/Knight.h $(SOURCES)/Bishop.h $(SOURCES)/SingleplayerMode.h \
 $(SOURCES)/HumanPlayer.h $(SOURCES)/ComputerPlayer.h $(SOURCES)/SimpleConsoleUI.h $(SOURCES)/UI.h \
 $(SOURCES)/FileIO.h

$(BINARIES)/Move.o: $(SOURCES)/Move.cpp $(SOURCES)/Move.h $(SOURCES)/Position.h

$(BINARIES)/MultiplayerMode.o: $(SOURCES)/MultiplayerMode.cpp $(SOURCES)/MultiplayerMode.h \
 $(SOURCES)/GameMode.h $(SOURCES)/Player.h $(SOURCES)/Move.h $(SOURCES)/Position.h $(SOURCES)/State.h \
 $(SOURCES)/Figure.h $(SOURCES)/Action.h $(SOURCES)/Tile.h $(SOURCES)/FenParser.h $(SOURCES)/Pawn.h \
 $(SOURCES)/Rook.h $(SOURCES)/King.h $(SOURCES)/Queen.h $(SOURCES)/Knight.h $(SOURCES)/Bishop.h

$(BINARIES)/Pawn.o: $(SOURCES)/Pawn.cpp $(SOURCES)/Pawn.h $(SOURCES)/Figure.h $(SOURCES)/Position.h $(SOURCES)/Move.h \
 $(SOURCES)/Action.h

$(BINARIES)/Player.o: $(SOURCES)/Player.cpp $(SOURCES)/Player.h $(SOURCES)/Move.h $(SOURCES)/Position.h \
 $(SOURCES)/State.h $(SOURCES)/Figure.h $(SOURCES)/Action.h $(SOURCES)/Tile.h

$(BINARIES)/Position.o: $(SOURCES)/Position.cpp $(SOURCES)/Position.h

$(BINARIES)/Queen.o: $(SOURCES)/Queen.cpp $(SOURCES)/Queen.h $(SOURCES)/Figure.h $(SOURCES)/Position.h $(SOURCES)/Move.h \
 $(SOURCES)/Action.h

$(BINARIES)/Rook.o: $(SOURCES)/Rook.cpp $(SOURCES)/Rook.h $(SOURCES)/Figure.h $(SOURCES)/Position.h $(SOURCES)/Move.h \
 $(SOURCES)/Action.h

$(BINARIES)/SimpleConsoleUI.o: $(SOURCES)/SimpleConsoleUI.cpp $(SOURCES)/SimpleConsoleUI.h $(SOURCES)/UI.h \
 $(SOURCES)/State.h $(SOURCES)/Figure.h $(SOURCES)/Position.h $(SOURCES)/Move.h $(SOURCES)/Action.h \
 $(SOURCES)/Tile.h $(SOURCES)/GameController.h $(SOURCES)/MultiplayerMode.h $(SOURCES)/GameMode.h \
 $(SOURCES)/Player.h $(SOURCES)/FenParser.h $(SOURCES)/Pawn.h $(SOURCES)/Rook.h $(SOURCES)/King.h \
 $(SOURCES)/Queen.h $(SOURCES)/Knight.h $(SOURCES)/Bishop.h $(SOURCES)/SingleplayerMode.h \
 $(SOURCES)/HumanPlayer.h $(SOURCES)/ComputerPlayer.h $(SOURCES)/FileIO.h

$(BINARIES)/SinglePlayerMode.o: $(SOURCES)/SinglePlayerMode.cpp $(SOURCES)/SingleplayerMode.h \
 $(SOURCES)/GameMode.h $(SOURCES)/Player.h $(SOURCES)/Move.h $(SOURCES)/Position.h $(SOURCES)/State.h \
 $(SOURCES)/Figure.h $(SOURCES)/Action.h $(SOURCES)/Tile.h $(SOURCES)/FenParser.h $(SOURCES)/Pawn.h \
 $(SOURCES)/Rook.h $(SOURCES)/King.h $(SOURCES)/Queen.h $(SOURCES)/Knight.h $(SOURCES)/Bishop.h

$(BINARIES)/State.o: $(SOURCES)/State.cpp $(SOURCES)/State.h $(SOURCES)/Figure.h $(SOURCES)/Position.h $(SOURCES)/Move.h \
 $(SOURCES)/Action.h $(SOURCES)/Tile.h $(SOURCES)/Pawn.h $(SOURCES)/King.h $(SOURCES)/Queen.h $(SOURCES)/Rook.h

$(BINARIES)/Tile.o: $(SOURCES)/Tile.cpp $(SOURCES)/Tile.h $(SOURCES)/Figure.h $(SOURCES)/Position.h $(SOURCES)/Move.h \
 $(SOURCES)/Action.h

$(BINARIES)/UI.o: $(SOURCES)/UI.cpp $(SOURCES)/UI.h $(SOURCES)/State.h $(SOURCES)/Figure.h $(SOURCES)/Position.h \
 $(SOURCES)/Move.h $(SOURCES)/Action.h $(SOURCES)/Tile.h $(SOURCES)/GameController.h \
 $(SOURCES)/MultiplayerMode.h $(SOURCES)/GameMode.h $(SOURCES)/Player.h $(SOURCES)/FenParser.h \
 $(SOURCES)/Pawn.h $(SOURCES)/Rook.h $(SOURCES)/King.h $(SOURCES)/Queen.h $(SOURCES)/Knight.h $(SOURCES)/Bishop.h \
 $(SOURCES)/SingleplayerMode.h $(SOURCES)/HumanPlayer.h $(SOURCES)/ComputerPlayer.h \
 $(SOURCES)/SimpleConsoleUI.h $(SOURCES)/FileIO.h
