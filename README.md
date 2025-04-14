# Projet d'Encodage et Décodage de Fichiers

Ce projet est un programme en C++ qui permet d'encoder et de décoder des fichiers texte en utilisant une clé de chiffrement.

## Fonctionnalités

- Encodage de fichiers texte
- Décodage de fichiers texte
- Validation de la clé de chiffrement
- Interface utilisateur en ligne de commande

## Spécifications techniques

### Clé de chiffrement
- Longueur : entre 5 et 20 caractères
- Caractères autorisés : caractères ASCII de 33 à 126 (caractères anglais imprimables)

### Traitement des fichiers
- Supporte les caractères ASCII de 32 à 126
- Préserve les retours à la ligne (caractères 10 et 13)
- Signale une erreur si des caractères non supportés sont rencontrés

## Utilisation

1. Exécutez le programme
2. Choisissez une option :
   - 1 pour encoder un fichier
   - 2 pour décoder un fichier
3. Entrez le nom du fichier source
4. Entrez le nom du fichier de destination
5. Entrez la clé de chiffrement

## Algorithme de chiffrement

- L'encodage utilise un décalage basé sur les caractères de la clé
- Le décalage est calculé par rapport à la lettre 'a'
- Si le résultat dépasse 126, il est ajusté en soustrayant 95
- Pour le décodage, le processus est inversé

## Messages d'erreur

- "Erreur : votre clé doit contenir entre 5 et 20 caractères"
- "Erreur : votre clé ne doit contenir que des caracteres anglais"
- "Erreur lors de l'ouverture des fichiers"
- "Code erreur -1 : Certains caractères du fichier ne sont pas supportés"

## Configuration technique

- Langage : C++
- Environnement : Visual Studio
- Encodage : UTF-8
- Dépendances standard : iostream, string, fstream
