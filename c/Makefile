CC = gcc
CFLAGS = -Wall -Wextra -Werror $(shell pkg-config --cflags libprotobuf-c)
LDFLAGS = $(shell pkg-config --libs libprotobuf-c)
TARGET = main
PROTO_DIR = proto
CONNEXION_DIR = connexion
OBJ = $(PROTO_DIR)/fichier.pb-c.o main.o $(CONNEXION_DIR)/connexion.o
PROTO_SOURCE = $(PROTO_DIR)/fichier.pb-c.c
PROTO_HEADER = $(PROTO_DIR)/fichier.pb-c.h
PROTO_FILE = fichier.proto

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

main.o: main.c $(PROTO_HEADER)
	$(CC) $(CFLAGS) -c main.c

connexion.o: $(CONNEXION_DIR)/connexion.c $(CONNEXION_DIR)/connexion.h
	$(CC) $(CFLAGS) -c $(CONNEXION_DIR)/com.c

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