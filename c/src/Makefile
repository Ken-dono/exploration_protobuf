# Compilateur à utiliser
CC = gcc
# Options de compilation
CFLAGS = -Wall -Wextra -Werror $(shell pkg-config --cflags libprotobuf-c)
# Options de l'éditeur de liens
LDFLAGS = $(shell pkg-config --libs libprotobuf-c) -lpthread -lrt
# Nom du fichier de sortie
TARGET = main

# Répertoires contenant le code source
PROTO_DIR = proto
COM_DIR = com
CONNEXION_DIR = connexion
PROTOCOLE_DIR = protocole

# Fichiers objet à compiler
OBJ = main.o $(PROTO_DIR)/fichier.pb-c.o $(CONNEXION_DIR)/connexion.o $(COM_DIR)/com.o $(PROTOCOLE_DIR)/protocole.o

# Fichiers source et en-tête générés par protoc pour protobuf
PROTO_SOURCE = $(PROTO_DIR)/fichier.pb-c.c
PROTO_HEADER = $(PROTO_DIR)/fichier.pb-c.h
# Fichier proto original
PROTO_FILE = fichier.proto

# Vérifier si le mode DEBUG est activé
ifeq ($(MODE),DEBUG)
CFLAGS += -DDEBUG
endif

# Cible par défaut
all: $(TARGET)

# Édition de liens du binaire cible
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Compilation du fichier principal
main.o: main.c $(PROTO_HEADER)
	$(CC) $(CFLAGS) -c main.c

# Compilation du module connexion
connexion.o: $(CONNEXION_DIR)/connexion.c $(CONNEXION_DIR)/connexion.h
	$(CC) $(CFLAGS) -c $(CONNEXION_DIR)/connexion.c

# Compilation du module com
com.o: $(COM_DIR)/com.c $(COM_DIR)/com.h
	$(CC) $(CFLAGS) -c $(COM_DIR)/com.c

# Compilation du module protocole
protocole.o: $(PROTOCOLE_DIR)/protocole.c $(PROTOCOLE_DIR)/protocole.h
	$(CC) $(CFLAGS) -c $(PROTOCOLE_DIR)/protocole.c

# Compilation de la source générée par protobuf-c
$(PROTO_DIR)/fichier.pb-c.o: $(PROTO_SOURCE) $(PROTO_HEADER)
	$(CC) $(CFLAGS) -c $(PROTO_SOURCE) -o $@

# Génération de la source et de l'en-tête protobuf-c à partir du fichier proto
$(PROTO_SOURCE) $(PROTO_HEADER): $(PROTO_FILE)
	mkdir -p $(PROTO_DIR)
	protoc-c --c_out=$(PROTO_DIR) $(PROTO_FILE)

# Nettoyage de la construction
clean:
	rm -f $(OBJ)
	rm -rf $(PROTO_DIR)

# Exécution du binaire cible
run: $(TARGET)
	./$(TARGET)