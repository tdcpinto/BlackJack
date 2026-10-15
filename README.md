# Projet : BlackJack

Le but de ce mini projet est de créer un jeu de BlackJack.
Pour ce faire, vous avez accès à des fichiers `.c` (dans le dossier `src/`),
et des fichiers `.h` (dans le dossier `includes/`).

Les fichiers `.h`, aussi appelés _headers_, servent à décrire
des structures, des fonctions, etc.
Dans ce projet, hormis le fichier `Utils.h`,
chaque header correspond à un type précis, et aux
fonctions qui lui sont associées.
De plus, chaque fichier `.c` correspondant
implémente les fonctions décrites dans le header.
Par exemple, le fichier `src/Card.c` correspond à la structure
`Card` définie dans `includes/Card.h` et il implémente
les fonctions décrites dans ce header.
Vous ne devez pas modifier ces fichiers _sauf_ l'intérieur des
`struct` et `enum`.
Une seconde exception est l'ajout d'inclusions de fichier `.h`.
Votre but est de compléter chacune des fonctions dans les `.c`.

La complétion des fichiers peut techniquement être faite dans
l'ordre que vous souhaitez.
Cependant, le plus simple est de coder les fichiers de base avant
de passer aux fichiers suivants.
Ainsi, je vous conseille l'ordre suivant :

1.  `Value.c`, `Suit.c` et `Action.c`
2.  `Card.c`
3.  `Deck.c`
4.  `Player.c`
5.  `Game.c`

Pensez à tester vos fonctions régulièrement avant de passer à la suite.
Idéalement, après avoir écrit une fonction, vous pouvez la tester dans le
fichier `main.c` fourni.

Attention : lorsque vous modifiez un fichier, et que vous utilisez un type
ou une fonction définie dans un autre fichier, pensez à inclure le fichier
`.h` correspondant.
Par exemple, dans le fichier `Card.h`, les structures `Value` et `Suit`
sont utilisées.
C'est pour cette raison que les fichiers `Value.h` et `Suit.h` sont
inclus dans `Card.h`.
Les inclusions se propagent, donc si un fichier inclut `Card.h`,
il inclut aussi tous les fichiers inclus dans `Card.h`.
Ces remarques valent aussi pour l'utilisation des constantes
du fichier `Utils.h`.

## Compilation

Ce projet utilise la compilation séparée (j'aurais normalement
fait un rappel en cours).
En cas de doute, vous pouvez compiler le projet entier avec la commande
suivante :

```bash
gcc -std=c99 -Wall -Werror -Iincludes -o main src/Utils.c \
src/Value.c src/Suit.c src/Action.c src/Card.c src/Deck.c \
src/Player.c src/Game.c main.c
```

Les options utilisées :

1.  -std=c99 : la convention C utilisée.
2.  -Wall -Werror : on affiche les warnings les plus courants
    et on les traite comme des erreurs.
    Vous pouvez retirer cette option _temporairement_ pour faire des tests rapides.
3.  -Iincludes : signale à votre compilateur où sont les headers à utiliser.
4.  -o main : la compilation génère un fichier nommé `main`, vous pouvez changer ce nom
    si vous le souhaitez.

Le reste correspond aux fichiers à compiler.
