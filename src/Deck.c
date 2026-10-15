#include "Deck.h"

/**
 * Cette fonction crée un jeu de carte vide.
 */
Deck create_empty_deck() {
    Deck d;
    return d;
}

/**
 * Cette fonction crée un jeu de carte standard (52 cartes).
 */
Deck create_standard_deck() {
    Deck d;
    return d;
}

/**
 * Cette fonction permet d'ajouter une carte sur le dessus du paquet.
 */
void add_card(Deck * deck, Card card) {

}

/**
 * Cette fonction renvoie le nombre de carte actuellement dans le paquet.
 */
unsigned int get_deck_size(Deck deck) {
    return 0;
}

/**
 * Cette fonction renvoie 0 si le paquet est vide, et 1 sinon.
 */
int is_deck_empty(Deck deck) {
    return 0;
}

/**
 * Cette fonction fusionne deux paquets de cartes en un seul
 * nouveau paquet.
 * L'ordre des cartes n'a pas d'importance dans le nouveau paquet.
 */
Deck merge_decks(Deck deck1, Deck deck2) {
    return deck1;
}

/**
 * Cette fonction pioche la première carte du paquet
 * et la retourne.
 */
Card draw_card(Deck * deck) {
    Card c;
    return c;
}

/**
 * Cette fonction mélange le paquet de cartes.
 * On donne une technique classique pour mélanger un paquet.
 * Pour chaque carte du paquet à la position i (de 0 à la fin du paquet) :
 *    a. Générer un indice aléatoire j (de i à la fin du paquet)
 *    b. Échanger les cartes à la position i et j
 */
void shuffle_deck(Deck * deck) {

}

/**
 * Cette fonction affiche le contenu du paquet de cartes.
 */
void show_deck(Deck deck) {
    
}