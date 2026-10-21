#include "Player.h"
#include "Deck.h"

#include <string.h>
#include <stdio.h>

/**
 * Cette fonction crée un nouveau joueur.
 * En particulier, il faut lui fournir un nom, 
 * une fonction pour choisir l'action à effectuer,
 * une fonction pour choisir combien miser,
 * et une somme d'argent initiale.
 */
Player create_player(char * name, ActionFunction choose_action, BetFunction choose_bet, unsigned int money) {
    Player player;
    unsigned int name_length = strlen(name) + 1;
    strncpy(player.name, name, name_length);
    player.hand = create_empty_deck();
    player.choose_action = choose_action;
    player.choose_bet = choose_bet;
    player.money = money;
    return player;
}

/**
 * Cette fonction permet de donner une carte à un joueur.
 */
void give_card(Player * player, Card card) {
    add_card(&(player->hand), card);
}

/**
 * Cette fonction retourne le score de la main du joueur.
 */
unsigned int get_score(Player player) {
    unsigned int score = 0;
    unsigned int aces_count = 0;
    for(unsigned int i = 0; i < get_deck_size(player.hand); i++) {
        Card c = player.hand.cards[i];
        if(c.value >= TWO && c.value <= TEN) {
            score += c.value;
        } else if(c.value >= JACK && c.value <= KING) {
            score += 10;
        } else if(c.value == ACE) {
            aces_count++;
            score += 11;
        }
    }
    while(score > 21 && aces_count > 0) {
        score -= 10;
        aces_count--;
    }
    return score;
}

/**
 * Cette fonction vide la main du joueur.
 */
void empty_hand(Player * player) {
    player->hand = create_empty_deck();
}

/**
 * Cette fonction permet de récupérer le nom d'un joueur.
 * On suppose que le buffer fourni est suffisamment grand pour contenir le nom du joueur.
 */
void get_name(Player player, char * buffer) {
    unsigned int name_length = strlen(player.name) + 1;
    strncpy(buffer, player.name, name_length);
}

/**
 * Cette fonction retourne l'argent du joueur.
 */
unsigned int get_money(Player player) {
    return player.money;
}

/**
 * Affiche les informations d'un joueur (nom, main, argent).
 */
void show_player(Player player) {
    printf("Player: %s\n", player.name);
    printf("Money: %u\n", player.money);
    printf("Hand: ");
    show_deck(player.hand);
}