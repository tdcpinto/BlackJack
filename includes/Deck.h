#ifndef DECK_H_
#define DECK_H_

#include "Card.h"
#include "Utils.h"

/**
 * Votre structure pour représenter un jeu de cartes.
 * Un jeu de carte classique contient 52 cartes.
 * On utilisera la même structure pour représenter la main d'un joueur.
 */
typedef struct Deck {
    Card cards[MAX_CARDS];
    unsigned int top;
} Deck;

/**
 * Cette fonction crée un jeu de carte vide.
 */
Deck create_empty_deck();

/**
 * Cette fonction crée un jeu de carte standard (52 cartes).
 */
Deck create_standard_deck();

/**
 * Cette fonction permet d'ajouter une carte sur le dessus du paquet.
 */
void add_card(Deck * deck, Card card);

/**
 * Cette fonction renvoie le nombre de carte actuellement dans le paquet.
 */
unsigned int get_deck_size(Deck deck);

/**
 * Cette fonction renvoie 0 si le paquet est vide, et 1 sinon.
 */
int is_deck_empty(Deck deck);

/**
 * Cette fonction fusionne deux paquets de cartes en un seul
 * nouveau paquet.
 * L'ordre des cartes n'a pas d'importance dans le nouveau paquet.
 */
Deck merge_decks(Deck deck1, Deck deck2);

/**
 * Cette fonction pioche la première carte du paquet
 * et la retourne.
 */
Card draw_card(Deck * deck);

/**
 * Cette fonction mélange le paquet de cartes.
 * On donne une technique classique pour mélanger un paquet.
 * Pour chaque carte du paquet à la position i (de 0 à 51) :
 *    a. Générer un indice aléatoire j (de i à 51)
 *    b. Échanger les cartes à la position i et j
 */
void shuffle_deck(Deck * deck);

/**
 * Cette fonction affiche le contenu du paquet de cartes.
 */
void show_deck(Deck deck);

#endif