# Mini-Projet d'Exploration Protobuf avec Communication en C

## Description

Ce mini-projet démontre l'utilisation de Protocol Buffers (protobuf) pour sérialiser et désérialiser des données structurées, ainsi que l'établissement d'une communication réseau via des sockets TCP en C. Le projet inclut un exemple de définition protobuf et de mise en œuvre côté serveur et client pour l'envoi et la réception de messages sérialisés.

## Fonctionnalités

- Définition d'un message protobuf simple avec un champ texte.
- Compilation de la définition protobuf en code source C.
- Mise en place d'un serveur socket TCP pour écouter les connexions entrantes.
- Envoi et réception de messages sérialisés à travers le réseau.

## Structure du Projet

- `fichier.proto` : Définition du message protobuf.
- `fichier.pb-c.c`, `fichier.pb-c.h` : Fichiers sources C générés à partir de `fichier.proto`.
- `main.c` : Programme principal qui sérialise et envoie un message, puis attend et désérialise la réponse.
- `com.c`, `com.h` : Bibliothèque personnalisée pour gérer la communication réseau.
- `Makefile` : Fichier utilisé pour automatiser la compilation et la création du projet.

## Installation

Assurez-vous d'avoir les paquets suivants installés :
- `protobuf-c-compiler` : Le compilateur pour Protocol Buffers.
- `libprotobuf-c-dev` : Les bibliothèques de développement pour protobuf en C.

Pour compiler le projet, utilisez la commande `make` à la racine du projet.

## Utilisation

Lancez le serveur avec la commande suivante :

```sh
make run
```

## Explication de l'exécution

Lorsque le programme principal `main` est exécuté, il procède comme suit :

1. **Initialisation de la connexion** : 
   - Le serveur est initialisé pour écouter sur un port spécifié grâce à la fonction `connexion_init`.

2. **Attente de connexion** : 
   - Le serveur attend passivement qu'un client établisse une connexion en utilisant `connexion_accept`.

3. **Création du message Protobuf** : 
   - Un message est créé en instanciant la structure `Message` définie dans `fichier.pb-c.h` et en assignant une chaîne de caractères au champ texte.

4. **Sérialisation du message** : 
   - Le message est converti en une séquence d'octets (sérialisé) pour le transfert à travers le réseau.

5. **Envoi du message** : 
   - Le message sérialisé est envoyé au client connecté via la fonction `connexion_write`.

6. **Fermeture de la connexion** : 
   - Après l'envoi, la connexion est fermée proprement avec `close_connection`, libérant ainsi les ressources réseau.

7. **Désérialisation du message (optionnelle)** : 
   - Si une réponse est reçue, elle peut être lue et convertie en structure de message pour être traitée.

8. **Nettoyage** : 
   - Le programme libère le buffer de sérialisation et toutes autres ressources allouées avant de se terminer.

À chaque étape, le programme inclut une gestion d'erreur pour traiter les situations telles que les échecs de connexion ou les problèmes d'allocation de mémoire. En cas d'erreur, le programme affichera un message approprié et se terminera de manière anticipée pour éviter tout comportement inattendu.

