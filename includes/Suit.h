#ifndef SUIT_H_
#define SUIT_H_

/**
 * Votre enumération pour les couleurs d'une carte.
 * Les couleurs possibles sont :
 *  - Carreau  (Diamond)
 *  - Coeur    (Heart)
 *  - Pique    (Spade)
 *  - Trèfle   (Club)
 */
typedef enum  {
    SPADES,
    DIAMONDS,
    CLUBS,
    HEARTS
} Suit;

/**
 * Cette fonction met dans la chaîne de caractères
 * `buffer` la couleur `c` sous forme de texte.
 * On suppose que le buffer donné en entrée est
 * suffisamment grand pour accueillir toutes
 * les couleurs.
 *
 * La fonction retourne un pointeur vers la fin du buffer.
 */
char * suit_to_string(Suit c, char * buffer);

/**
 * Cette fonction met dans la chaîne de caractères 'buffer'
 * le symbole correspondant à la couleur (♠ ♥ ♦ ♣).
 * On suppose que le buffer donné en entrée est
 * suffisamment grand pour accueillir toutes
 * les couleurs.
 *
 * La fonction retourne un pointeur vers la fin du buffer.
 */
char * suit_to_symbol(Suit c, char * buffer);

/**
 * Cette fonction affiche directement la couleur `c`
 * sous forme lisible.
 *
 * Facultatif : 
 * Pour rendre l'affichage plus beau, on peut utiliser
 * des codes spécifiques afin de mettre le texte
 * affiché en couleur.
 * Par exemple : `printf("\033[31mHello world\n\033[0m")`
 * affiche "Hello world" en rouge.
 * Plus d'info : https://workboot.fr/ciela/utiliser-les-textes-en-couleurs/
 *
 * Il est possible de mettre des couleurs dans un buffer (char *),
 * mais c'est un peu plus pénible.
 * En particulier, '\033', '[', '3', '1' et 'm' sont des caractères différents.
 */
void print_suit(Suit c);

#endif