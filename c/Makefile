
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = `pkg-config --libs --cflags libprotobuf-c`
TARGET = main
OBJ = fichier.pb-c.o main.o com.o
PROTO_SOURCE = fichier.pb-c.c
PROTO_HEADER = fichier.pb-c.h

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(LDFLAGS)

main.o: main.c $(PROTO_HEADER)
	$(CC) $(CFLAGS) -c main.c

com.o: com.c com.h
	$(CC) $(CFLAGS) -c com.c

fichier.pb-c.o: $(PROTO_SOURCE) $(PROTO_HEADER)
	$(CC) $(CFLAGS) -c $(PROTO_SOURCE)

$(PROTO_SOURCE) $(PROTO_HEADER): fichier.proto
	protoc-c --c_out=. fichier.proto

clean:
	rm -f $(OBJ) $(PROTO_SOURCE) $(PROTO_HEADER)

run: $(TARGET)
	./$(TARGET)