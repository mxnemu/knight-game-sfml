CXX=g++
CC=gcc
LIBS=-lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system -lN0Slib
LIB_DIRS:=-L$(CURDIR)/lib/noslib -L$(CURDIR)/bin
INCLUDE_DIRS:=-I$(CURDIR)/lib/noslib -I$(CURDIR)
#might remove -fPIC from GAME_CFLAGS
CFLAGS=-pthread -Wall -pedantic -g -std=c++11 -fPIC

GAME_LIBS=$(LIBS) -lserver -lbase
GAME_HEADERS:=$(wildcard $(CURDIR)/game/*.h)
GAME_SRC:=$(wildcard $(CURDIR)/game/*.cpp)
GAME_OBJ=$(GAME_SRC:%.cpp=%.o)

BASE_HEADERS:=$(wildcard $(CURDIR)/base/*.h)
BASE_SRC:=$(wildcard $(CURDIR)/base/*.cpp)
BASE_OBJ=$(BASE_SRC:%.cpp=%.o)

SERVER_LIBS:=$(LIBS) -lbase
SERVER_HEADERS:=$(wildcard $(CURDIR)/server/*.h)
SERVER_SRC:=$(wildcard $(CURDIR)/server/*.cpp)
SERVER_OBJ=$(SERVER_SRC:%.cpp=%.o)

MKDIR=mkdir -p
RMDIR=rm -rf
BIN_DIR=bin

game: libbase.so libserver.so $(GAME_OBJ)
	$(CXX) $(GAME_OBJ) $(GAME_LIBS) $(LIB_DIRS) $(INCLUDE_DIRS) -o $(BIN_DIR)/$@

libbase.so: $(BASE_OBJ) prepareDir
	$(CXX) $(BASE_OBJ) $(LIBS) $(LIB_DIRS) $(INCLUDE_DIRS) -shared -o $(BIN_DIR)/$@

libserver.so: $(SERVER_OBJ) libbase.so prepareDir
	$(CXX) $(CFLAGS) $(SERVER_OBJ) $(SERVER_LIBS) $(LIB_DIRS) $(INCLUDE_DIRS) -shared -o $(BIN_DIR)/$@

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

#test:
#	$(CC) $(CFLAGS) List.c StringReplace.c tests/StringReplaceTest.c $(LIBS) -o $(BIN_DIR)/$@


prepareDir:
	$(MKDIR) $(BIN_DIR)
	$(MKDIR) $(BIN_DIR)/obj


clean:
	$(RM) $(GAME_OBJ)
	$(RM) $(SERVER_OBJ)
	$(RM) $(BASE_OBJ)
	$(RMDIR) $(BIN_DIR)
