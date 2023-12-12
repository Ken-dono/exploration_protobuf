# Mini-Projet d'Exploration Protobuf avec Communication en C

- [Description](#description)
- [Exploration et Ressources](#exploration-et-ressources)
- [Fonctionnalités](#fonctionnalités)
- [Installation](#installation)
- [Structure du Projet](#structure-du-projet)
- [Utilisation](#utilisation)
- [Explication de l'exécution](#explication-de-lexécution)

## Description

Ce mini-projet démontre l'utilisation de Protocol Buffers (protobuf) pour sérialiser et désérialiser des données structurées, ainsi que l'établissement d'une communication réseau via des sockets TCP en C. Le projet inclut un exemple de définition protobuf et de mise en œuvre côté serveur et client pour l'envoi et la réception de messages sérialisés.

## Exploration et Ressources

Pour le développement de ce mini-projet, plusieurs ressources concernant les Protocol Buffers (protobuf) en C et les techniques de communication réseau ont été consultées. Les sources principales incluent :

- **Protobuf-C GitHub Repository** :
  - [GitHub - protobuf-c/protobuf-c](https://github.com/protobuf-c/protobuf-c) : Le dépôt officiel de Protobuf-C, contenant le code source et la documentation.

- **Documentation Officielle Protobuf-C** :
  - [Protobuf-C](https://protobuf-c.github.io/protobuf-c/) : Documentation officielle de Protobuf-C, détaillant son utilisation en C.

- **Wikis et Guides Protobuf-C** :
  - [Protobuf-C Wiki](https://github.com/protobuf-c/protobuf-c/wiki) : Informations sur les concepts de base et fonctionnalités avancées de Protobuf-C.
  - [Exemples Protobuf-C](https://github.com/protobuf-c/protobuf-c/wiki/Examples) : Exemples pratiques montrant l'usage de Protobuf-C pour la sérialisation et la désérialisation.

- **Forum Protobuf-C** :
  - [Google Group - Protobuf-C](https://groups.google.com/forum/#!forum/protobuf-c) : Un forum dédié aux discussions sur Protobuf-C, avec des contributions de développeurs et utilisateurs.

Ces ressources ont été utilisées pour acquérir des connaissances et résoudre des problèmes techniques spécifiques rencontrés pendant le développement du projet.


## Fonctionnalités
- Communication TCP/IP basique entre le client et le serveur.
- Utilisation de Protobuf pour la sérialisation et la désérialisation des messages.
- Gestion de différents types de messages (par exemple, `battery_level`, `status_explo`, `position`).
- Interaction utilisateur pour choisir et envoyer des messages spécifiques.
- Gestion des threads pour la lecture et l'écriture des messages.

## Installation

Assurez-vous d'avoir les paquets suivants installés :
- `protobuf-c-compiler` : Le compilateur pour Protocol Buffers, nécessaire pour compiler les fichiers `.proto`.
- `libprotobuf-c-dev` : Les bibliothèques de développement pour protobuf en C, fournissant les en-têtes et les bibliothèques nécessaires pour la compilation.
- `pkg-config` : Un outil de gestion de la configuration des paquets logiciels, utilisé pour récupérer les drapeaux de compilation et de liaison nécessaires pour les bibliothèques installées sur votre système.

Pour installer ces dépendances sous Debian/Ubuntu, utilisez la commande suivante :

```bash
sudo apt-get install protobuf-c-compiler libprotobuf-c-dev pkg-config
```
Pour compiler le projet, utilisez la commande `make` à la racine du projet.

## Structure du Projet

Le projet est organisé de la manière suivante :

- `com/` : Gère la communication entre le serveur et le client.
   - `com.c` : Implémente les fonctions de communication.
   - `com.h` : Définit les structures et les prototypes pour `com.c`.
- `connexion/` : Gère la connexion réseau.
   - `connexion.c` : Implémente les fonctions de connexion.
   - `connexion.h` : Définit les structures et les prototypes pour `connexion.c`.
- `protocole/` : Gère le codage et le décodage des messages.
   - `protocole.c` : Implémente les fonctions de codage et de décodage.
   - `protocole.h` : Définit les structures et les prototypes pour `protocole.c`.
- `main.c` : Le point d'entrée du programme.
- `fichier.proto` : Définit les structures des messages.
- `Makefile` : Script de compilation pour le projet.
- `README.md` : Ce fichier, expliquant comment installer, construire et exécuter le projet.


## Utilisation

Lancez le serveur avec la commande suivante :

```sh
make run
```

Observez les packet transmis avec la commande suivante :
```sh
sudo tcpdump -i any tcp port 12345 -X
```

Simulez un client sur la socket avec la commande suivante :
```sh
nc localhost 12345
```

## Explication de l'exécution

Le programme principal `main` s'exécute selon les étapes suivantes :

1. **Initialisation de la Communication** : 
   - Le système initialise la communication en appelant `com_init()`, qui configure la file de messages et lance les threads de lecture et d'écriture.

2. **Établissement de la Connexion** :
   - Le serveur, à travers `connexion_init()`, configure et écoute sur un port TCP/IP spécifié. Il attend ensuite une connexion entrante avec `connexion_accept()`.

3. **Interaction avec l'Utilisateur** : 
   - Une fois la connexion établie, l'utilisateur est invité à entrer des commandes pour envoyer différents types de messages (par exemple, `04` pour `battery_level`).

4. **Création et Envoi de Messages Protobuf** : 
   - Selon l'entrée de l'utilisateur, un message spécifique est créé et sérialisé en utilisant Protocol Buffers. La sérialisation convertit la structure du message en un format adapté à la transmission réseau.

5. **Transmission des Messages** : 
   - Les messages sérialisés sont envoyés sur le réseau via `com_send_message()`, qui place le message dans la file de messages. Le thread d'écriture lit ensuite ce message, le transmet via la socket TCP au client connecté.

6. **Réception et Traitement des Réponses** :
   - En parallèle, le thread de lecture surveille les données entrantes sur la socket. Lorsqu'un message est reçu, il est désérialisé en une structure de message Protobuf pour traitement.

7. **Fermeture de la Communication** :
   - L'utilisateur peut arrêter le programme en entrant `q`. Cela déclenche `com_stop()`, qui envoie un message d'arrêt aux threads et ferme la connexion réseau proprement.

8. **Nettoyage des Ressources** :
   - Avant de se terminer, le programme effectue un nettoyage, en libérant toutes les ressources allouées, y compris les buffers de sérialisation et les file de messages, assurant ainsi une fermeture sans fuite de mémoire.

À chaque étape, le programme intègre une gestion d'erreur robuste pour assurer un fonctionnement stable et sécurisé, même en cas de problèmes de réseau, de sérialisation ou d'allocation de mémoire. En cas d'erreur, des messages descriptifs sont affichés pour faciliter le débogage et la résolution des problèmes.

## Mode Débogage

Le projet supporte un mode de débogage qui peut être activé lors de la compilation. Pour compiler le projet en mode débogage, utilisez la commande suivante :

```bash
make MODE=DEBUG
```
En mode débogage, des informations supplémentaires sont imprimées sur la console pour aider au débogage du programme. En mode normal (release), ces informations sont omises pour une exécution plus propre.

## Documentation du code

La documentation complète du code, générée avec Doxygen, est disponible [ici](https://github.com/Ken-dono/exploration_protobuf/docs/index.html).