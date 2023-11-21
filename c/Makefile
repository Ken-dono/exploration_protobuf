CC = gcc
CFLAGS = -Wall -Wextra -Werror $(shell pkg-config --cflags libprotobuf-c)
LDFLAGS = $(shell pkg-config --libs libprotobuf-c) -lpthread -lrt
TARGET = main

PROTO_DIR = proto
COM_DIR = com
CONNEXION_DIR = connexion
PROTOCOLE_DIR = protocole
OBJ = main.o $(PROTO_DIR)/fichier.pb-c.o $(CONNEXION_DIR)/connexion.o $(COM_DIR)/com.o $(PROTOCOLE_DIR)/protocole.o
PROTO_SOURCE = $(PROTO_DIR)/fichier.pb-c.c
PROTO_HEADER = $(PROTO_DIR)/fichier.pb-c.h
PROTO_FILE = fichier.proto

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

main.o: main.c $(PROTO_HEADER)
	$(CC) $(CFLAGS) -c main.c

connexion.o: $(CONNEXION_DIR)/connexion.c $(CONNEXION_DIR)/connexion.h
	$(CC) $(CFLAGS) -c $(CONNEXION_DIR)/connexion.c

com.o: $(COM_DIR)/com.c $(COM_DIR)/com.h
	$(CC) $(CFLAGS) -c $(COM_DIR)/com.c

protocole.o: $(PROTOCOLE_DIR)/protocole.c $(PROTOCOLE_DIR)/protocole.h
	$(CC) $(CFLAGS) -c $(PROTOCOLE_DIR)/protocole.c

$(PROTO_DIR)/fichier.pb-c.o: $(PROTO_SOURCE) $(PROTO_HEADER)
	$(CC) $(CFLAGS) -c $(PROTO_SOURCE) -o $@

$(PROTO_SOURCE) $(PROTO_HEADER): $(PROTO_FILE)
	mkdir -p $(PROTO_DIR)
	protoc-c --c_out=$(PROTO_DIR) $(PROTO_FILE)

clean:
	rm -f $(OBJ) $(TARGET)
	rm -rf $(PROTO_DIR)

run: $(TARGET)
	./$(TARGET)