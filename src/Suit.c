#include "Suit.h"

#include "Utils.h"

#include <string.h>
#include <stdio.h>

/**
 * Cette fonction met dans la chaîne de caractères
 * `buffer` la couleur `c` sous forme de texte.
 * On suppose que le buffer donné en entrée est
 * suffisamment grand pour accueillir toutes
 * les couleurs.
 *
 * La fonction retourne un pointeur vers la fin du buffer.
 */
char * suit_to_string(Suit c, char * buffer) {
    switch(c) {
        case SPADES: buffer = strcpy(buffer, "spades"); break;
        case CLUBS: buffer = strcpy(buffer, "clubs"); break;
        case HEARTS: buffer = strcpy(buffer, "hearts"); break;
        case DIAMONDS: buffer = strcpy(buffer, "diamonds"); break;
        default: buffer = strcpy(buffer, "unknown"); break;
    }
    return buffer + strlen(buffer);
}


/**
 * Cette fonction met dans la chaîne de caractères 'buffer'
 * le symbole correspondant à la couleur (♠ ♥ ♦ ♣).
 * On suppose que le buffer donné en entrée est
 * suffisamment grand pour accueillir toutes
 * les couleurs.
 *
 * La fonction retourne un pointeur vers la fin du buffer.
 */
char * suit_to_symbol(Suit c, char * buffer) {
    buffer[0] = '\033';
    buffer[1] = '[';
    buffer[2] = '3';
    switch(c) {
        case SPADES:    buffer[3] = '7';
                        buffer[4] = 'm';
                        buffer = strcpy(buffer + 5, "♠\033[0m"); 
                        break;
        case CLUBS:     buffer[3] = '7';
                        buffer[4] = 'm';
                        buffer = strcpy(buffer + 5, "♣\033[0m"); 
                        break;
        case HEARTS:    buffer[3] = '1';
                        buffer[4] = 'm';
                        buffer = strcpy(buffer + 5, "♥\033[0m"); 
                        break;
        case DIAMONDS:  buffer[3] = '1';
                        buffer[4] = 'm';
                        buffer = strcpy(buffer + 5, "♦\033[0m"); 
                        break;
        default: buffer = strcpy(buffer, "?"); break;
    }
    return buffer + strlen(buffer);
}

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
void print_suit(Suit c) {
    char buffer[MAX_STR];
    suit_to_string(c, buffer);
    printf("%s", buffer);
}