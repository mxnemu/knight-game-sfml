CC=g++
LIBS=-lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system -lN0Slib
LIB_DIRS:=-L$(CURDIR)/lib/noslib
INCLUDE_DIRS:=-I$(CURDIR)/lib/noslib
CFLAGS=-pthread -Wall -pedantic -g -std=c++11

GAME_INCLUDE:=$(INCLUDE_DIRS) -I$(CURDIR)/server
GAME_LIBS=$(LIBS) -lserver
GAME_LIB_DIRS=$(LIB_DIRS) -L$(CURDIR)/bin
GAME_HEADERS:=$(wildcard $(CURDIR)/game/*.h)
GAME_FILES:=$(wildcard $(CURDIR)/game/*.cpp)

#CLIENT_HEADERS:=$(wildcard $(CURDIR)/client/*.h)
#CLIENT_FILES:=$(wildcard $(CURDIR)/client/*.cpp)

SERVER_HEADERS:=$(wildcard $(CURDIR)/server/*.h)
SERVER_FILES:=$(wildcard $(CURDIR)/server/*.cpp)
#SERVER_ALL:=$(C_HEADERS) $(C_FILES)

MKDIR=mkdir -p
BIN_DIR=bin

# TODO upgrade to the version on my laptop that makes object files

game: libserver.so
	$(CC) $(CFLAGS) $(GAME_FILES) $(GAME_LIBS) $(GAME_LIB_DIRS) $(GAME_INCLUDE) -o $(BIN_DIR)/$@

#client.so: prepareDir
#	$(CC) $(CFLAGS) $(CLIENT_FILES) $(LIBS) $(LIB_DIRS) $(INCLUDE_DIRS) -shared -o $(BIN_DIR)/$@

libserver.so: prepareDir
	$(CC) $(CFLAGS) $(SERVER_FILES) $(LIBS) $(LIB_DIRS) $(INCLUDE_DIRS) -shared -fPIC -o $(BIN_DIR)/$@

#test:
#	$(CC) $(CFLAGS) List.c StringReplace.c tests/StringReplaceTest.c $(LIBS) -o $(BIN_DIR)/$@

prepareDir:
	$(MKDIR) $(BIN_DIR)
