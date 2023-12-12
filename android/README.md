
# README pour l'application Android d'expérimentation Protobuf

## Description

Ce README détaille l'application Android conçue pour expérimenter avec Protobuf (Protocol Buffers) sous Android Studio. L'application démontre les capacités de Protobuf en matière de sérialisation et de désérialisation des données, en mettant l'accent sur la communication réseau dans un environnement Android.

## Exploration et Ressources

Pour le développement de ce mini-projet, plusieurs ressources concernant les Protocol Buffers (protobuf) en C et les techniques de communication réseau ont été consultées. Les sources principales incluent :

- **Documentation Officielle Protobuf** :
  - [Protobuf](https://protobuf.dev/) : Documentation officielle de Protobuf, détaillant son utilisation.

Ces ressources ont été utilisées pour acquérir des connaissances et résoudre des problèmes techniques spécifiques rencontrés pendant le développement du projet.


## Fonctionnalités

- Utilise Protobuf pour la sérialisation efficace des données.
- Implémente une communication client-serveur TCP.
- Démontre l'échange de données en temps réel entre un client Android et un serveur distant.

## Installation

1. Cloner le dépôt.
2. Ouvrir le projet dans Android Studio.
3. Assurer l'installation de toutes les dépendances.

## Utilisation

- Lancer l'application.
- Se connecter à un serveur en utilisant l'adresse IP donnée.
- Envoyer et recevoir des données sérialisées avec Protobuf.

## Structure

- `MainActivity.java` : Fichier de l'activité principale gérant les interactions de l'interface utilisateur.
- `TCPClient.java` : Gère la communication TCP, envoie et reçoit des messages Protobuf.
- `fichier.proto` : Fichier de schéma Protobuf définissant la structure des messages.

## Intégration Protobuf
- Installer le plugin "Protocol Buffers"
- Définir les structures de données dans le fichier `.proto`.
- Intégrer protobuf dans le build.gradle :  
  
  plugins:

  ```java
      id 'com.google.protobuf' version '0.9.1'
  ```

  dependencies:
  ```java
      implementation  "com.google.protobuf:protobuf-javalite:3.18.0"
  ```

  protoc:
  ```java
  protobuf {
      protoc {
          artifact = "com.google.protobuf:protoc:3.21.7"
      }

      // Generates the java Protobuf-lite code for the Protobufs in this project. See
      // https://github.com/google/protobuf-gradle-plugin#customizing-protobuf-compilation
      // for more information.
      generateProtoTasks {
          all().each { task ->
              task.builtins {
                  java {
                      option 'lite'
                  }
              }
          }
      }
  }
  ```
- Générer le code Java pour les classes Protobuf.
- Sérialiser et désérialiser les messages dans l'application.

## Explication de l'exécution

L'application fonctionne de la manière suivante :

1. **Démarrage de l'application** : À l'ouverture, l'application initialise l'interface utilisateur et se prépare à établir une connexion TCP.

2. **Connexion au serveur** : L'utilisateur doit entrer l'adresse IP du serveur auquel se connecter. Une fois l'adresse IP fournie, l'application établit une connexion TCP avec le serveur.

3. **Échange de messages** : Après la connexion, l'application permet à l'utilisateur d'envoyer des messages sérialisés via Protobuf au serveur. Ces messages sont définis dans le fichier `fichier.proto` et convertis en classes Java.

4. **Réception et traitement des réponses** : Le serveur répond avec des messages sérialisés. L'application les désérialise et les affiche à l'utilisateur.

5. **Fermeture de la connexion** : L'utilisateur peut fermer la connexion à tout moment. L'application gère la fermeture propre de la connexion TCP.

Cette procédure assure un échange de données sécurisé et efficace, tirant parti de la rapidité et de la légèreté de Protobuf pour la communication réseau.

