#include "Card.h"
#include "Value.h"

#include <stdio.h>
#include <string.h>

/**
 * Cette fonction permet de créer une carte
 * avec la valeur `value` et la couleur `suit`.
 */
Card create_card(Value value, Suit suit) {
    Card c;
    c.value = value;
    c.suit = suit;
    return c;
}

/**
 * Cette fonction permet de convertir 
 * une carte en chaîne de caractères.
 * On suppose que le buffer donné en entrée est
 * suffisamment grand pour accueillir toutes
 * les cartes.
 */
char * card_to_string(Card c, char * buffer) {
    buffer = value_to_symbol(c.value, buffer);
    buffer = suit_to_symbol(c.suit, buffer);
    return buffer + strlen(buffer);
}

/**
 * Cette fonction permet d'afficher une carte
 * directement. 
 */
void print_card(Card c) {
    print_value(c.value);
    printf(" of ");
    print_suit(c.suit);
}