# Définition des variables du compilateur et des options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror $(shell pkg-config --cflags libprotobuf-c)
LDFLAGS = $(shell pkg-config --libs libprotobuf-c) -lpthread -lrt

# Noms des exécutables pour la version de production et la version de débogage
TARGET = main
DEBUG_TARGET = main_debug

# Emplacements des répertoires source
PROTO_DIR = proto
COM_DIR = com
CONNEXION_DIR = connexion
PROTOCOLE_DIR = protocole

# Fichiers objet nécessaires pour le lien final
OBJ = main.o $(PROTO_DIR)/fichier.pb-c.o $(CONNEXION_DIR)/connexion.o $(COM_DIR)/com.o $(PROTOCOLE_DIR)/protocole.o
DEBUG_OBJ = $(OBJ:.o=_debug.o)

# Fichiers générés par protobuf
PROTO_SOURCE = $(PROTO_DIR)/fichier.pb-c.c
PROTO_HEADER = $(PROTO_DIR)/fichier.pb-c.h
PROTO_FILE = fichier.proto

# La cible par défaut construit les versions release et debug
all: $(TARGET) $(DEBUG_TARGET)

# Construire la version release
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Construire la version debug
$(DEBUG_TARGET): CFLAGS += -DDEBUG
$(DEBUG_TARGET): $(DEBUG_OBJ)
	$(CC) $(DEBUG_OBJ) -o $(DEBUG_TARGET) $(LDFLAGS)

# Règle générique pour construire n'importe quel .o à partir de .c
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour générer les fichiers objets spécifiques à la version de débogage
%_debug.o: %.c
	$(CC) $(CFLAGS) -DDEBUG -c $< -o $@

# Règle pour générer les fichiers sources et en-têtes protobuf
$(PROTO_SOURCE) $(PROTO_HEADER): $(PROTO_FILE)
	mkdir -p $(PROTO_DIR)
	protoc-c --c_out=$(PROTO_DIR) $(PROTO_FILE)

# Nettoyer les fichiers objets et les répertoires générés
clean:
	rm -f $(OBJ) $(DEBUG_OBJ) $(TARGET) $(DEBUG_TARGET)
	rm -rf $(PROTO_DIR)

# Exécuter le programme release
run: $(TARGET)
	./$(TARGET)

# Exécuter le programme debug
debug: $(DEBUG_TARGET)
	./$(DEBUG_TARGET)