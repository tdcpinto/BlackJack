#include "Deck.h"

#include "Card.h"
#include "Suit.h"
#include "Utils.h"
#include "Value.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * Cette fonction crée un jeu de carte vide.
 */
Deck create_empty_deck() {
    Deck deck;
    deck.top = 0;
    return deck;
}

/**
 * Cette fonction initialise un jeu de cartes standard (52 cartes).
 */
Deck create_standard_deck() {
    Deck deck;
    deck.top = 0;
    for(Suit s = SPADES; s <= HEARTS; s++) {
        for(Value v = ACE; v <= KING; v++) {
            Card c = create_card(v, s);
            add_card(&deck, c);
        }
    }
    return deck;
}

/**
 * Cette fonction permet d'ajouter une carte sur le dessus du paquet.
 */
void add_card(Deck * deck, Card card) {
    if(deck->top >= MAX_CARDS) {
        fprintf(stderr, "Error: Cannot add card to a full deck.\n");
        exit(EXIT_FAILURE);
    }
    deck->cards[deck->top] = card;
    deck->top++;
}

/**
 * Cette fonction renvoie le nombre de carte actuellement dans le paquet.
 */
unsigned int get_deck_size(Deck deck) {
    return deck.top;
}

/**
 * Cette fonction renvoie 0 si le paquet est vide, et 1 sinon.
 */
int is_deck_empty(Deck deck) {
    return deck.top == 0;
}

/**
 * Cette fonction fusionne deux paquets de cartes en un seul.
 */
Deck merge_decks(Deck deck1, Deck deck2) { 
    Deck res = create_empty_deck();
    for(unsigned int i = 0; i < deck1.top; i++) {
        add_card(&res, deck1.cards[i]);
    }
    for(unsigned int i = 0; i < deck2.top; i++) {
        add_card(&res, deck2.cards[i]);
    }
    return res;
}

/**
 * Cette fonction pioche la première carte du paquet
 * et la retourne.
 */
Card draw_card(Deck * deck) {
    if(deck->top == 0) {
        fprintf(stderr, "Error: Cannot draw from an empty deck.\n");
        exit(EXIT_FAILURE);
    }
    Card c = deck->cards[deck->top - 1];
    deck->top--;
    return c;
}

/**
 * Cette fonction mélange le paquet de cartes.
 * On donne une technique classique pour mélanger un paquet.
 * Pour chaque carte du paquet à la position i (de 0 à 51) :
 *    a. Générer un indice aléatoire j (de i à 51)
 *    b. Échanger les cartes à la position i et j
 */
void shuffle_deck(Deck * deck) {
    for(unsigned int i = 0; i < deck->top; i++) {
        unsigned int j = get_random_number(i, deck->top - 1);
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

/**
 * Cette fonction affiche le contenu du paquet de cartes.
 */
void show_deck(Deck deck) {
    if(deck.top == 0) {
        printf("[]");
        return;
    }
    printf("[");
    for(unsigned int i = 0; i < deck.top - 1; i++) {
        char buffer[MAX_STR];
        card_to_string(deck.cards[i], buffer);
        printf("%s, ", buffer);
    }
    char buffer[MAX_STR];
    card_to_string(deck.cards[deck.top - 1], buffer);
    printf("%s]", buffer);
}