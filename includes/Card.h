#ifndef CARD_H_
#define CARD_H_

#include "Suit.h"
#include "Value.h"

/**
 * Votre structure `Card` permettant
 * de représenter une carte à jouer classique.
 */
typedef struct Card {
    Value value;
    Suit suit;
} Card;

/**
 * Cette fonction permet de créer une carte
 * avec la valeur `value` et la couleur `suit`.
 */
Card create_card(Value value, Suit suit);

/**
 * Cette fonction permet de convertir 
 * une carte en chaîne de caractères.
 * On suppose que le buffer donné en entrée est
 * suffisamment grand pour accueillir toutes
 * les cartes.
 *
 * La fonction retourne un pointeur vers la fin du buffer.
 */
char * card_to_string(Card c, char * buffer);

/**
 * Cette fonction permet d'afficher une carte
 * directement. 
 */
void print_card(Card c);

#endif